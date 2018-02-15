#include <stdio.h>

//Utils functions to transform hexa time data into decimal

void getSimpleTime(int* dec, unsigned char hexa){
    *dec = hexa;
}

void getYear(int* yearDec, unsigned char yearHexa1, unsigned char yearHexa2){
    *yearDec = yearHexa2 << 8 | yearHexa1;
}

//Real work
int main(){

    //Open binary file
    FILE* ubx;
    ubx = fopen("16040118.ubx", "rb");

    if(!ubx){
        printf("Impossible to open file.");
        return 1;
    }

    //Open CSV file
    FILE* result;
    result = fopen("result.csv", "w+");

    if(!result){
        printf("Impossible to create file.");
        return 1;
    }

    //CSV head
    fprintf(result, "year,month,day,hours,minutes,seconds \n");

    //Read file
    unsigned char id[4], length[2], message[20];
    int compare = (0x21<<24)|(0x01<<16)|(0x62<<8)|0xb5;
    int year, month, day, hour, min, sec;
    
    while(fread(id, sizeof(char), 4, ubx)){

        //Filter the messages we are interested in
        if(id[0]==0xb5 && id[1]==0x62 && id[2]==0x01 && id[3]==0x21){
            
            //Skip the length bytes
            fread(length, sizeof(char), 2, ubx);

            //Get the payload message (+ CK_A and CK_B)
            fread(message, sizeof(char), 22, ubx);

            //Transform data into decimal
            getYear(&year, message[12], message[13]);
            getSimpleTime(&month, message[14]);
            getSimpleTime(&day, message[15]);
            getSimpleTime(&hour, message[16]);
            getSimpleTime(&min, message[17]);
            getSimpleTime(&sec, message[18]);

            //Display in console
            printf("%d, %d, %d, %d, %d, %d \n", year, month, day, hour, min, sec);

            //Export in CSV
            fprintf(result, "%d,%d,%d,%d,%d,%d \n", year, month, day, hour, min, sec);
        
        }
        
    }

    //Close file
    fclose(ubx);

    return 0;
}