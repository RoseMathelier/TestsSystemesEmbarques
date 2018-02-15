#include <stdio.h>
#include <stdlib.h>

int main(){

    unsigned char c1 = 3;
    unsigned char c2 = 6;
    unsigned char c3 = 0xeb;
    unsigned char c4 = 0b00111111;

    int c;

    c = c | c1;
    c = c << 8;
    c = c | c2;
    c = c << 8;
    c = c | c3;
    c = c << 8;
    c = c | c4;

    printf("c = %i, \n", c);

    return 0;
}