### Création d'un fichier CSV contenant les données temporelles issues d'un Ublox.

## Contexte :

Petit programme en C réalisé lors du cours de systèmes embarqués du master TSI de l'ENSG (15 février 2018).

## Etapes :

* Ouvrir le fichier binaire.
* Créer le fichier de sortie (avec un header si l'on veut).
* Parcourir le fichier en entrée.
* Filtrer les messages qui nous intéressent en récupérant les 4 premiers octets b5 62 (synchronisation) 01 21 (message de temps UTC).
* Lorsqu'on récupère un message de ce type, sauter les deux octets suivants, puis récupérer les 20 octets de charge utile.
* Vérifier que le message est intègre en comparant avec les deux CheckSum.
* Récupérer les octets 12 à 18 correspondant aux informations sur l'année, le mois, le jour, l'heure, la minute, la seconde.
* Convertir ces données en décimal.
* Les écrire dans le CSV.
* A la fin de la boucle, on ferme les fichiers.
