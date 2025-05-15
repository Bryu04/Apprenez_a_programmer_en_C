/*
  
Le fichier fichiers_manipule.c est un petit programme qui va créer et modifier des fichiers grace aux fonctions.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // Pour ouvrir un fichier, on va utiliser la structure FILE qui est définie dans "stdio.h"
    // Création et initialisation du pointeur monfichier
    FILE *monfichier = NULL;

    // La suite est d'ouvrir le fichier (s'il existe)
    monfichier = fopen("test_read.txt", "r+");

    // Vérification de l'ouverture du fichier
    if (monfichier != NULL)
    {
        printf("Le fichier test_read est ouvert sans problème. \n");
        // On fait notre modif....
        printf("On fait notre modif....\n");
        // et on ferme notre fichier quand on a fini
        printf("et on ferme notre fichier quand on a fini\n");
        fclose(monfichier);
    }
    else
    {
        printf("Impossible d'ouvrir le ficher test_read.txt : Le fichier n'existe pas !!\n");
        printf("Création du fichier : test_read.txt \n");
        monfichier = fopen("test_read.txt", "w");
        printf("et on ferme le fichier après création par l'ouverture\n");
        fclose(monfichier);
        printf("Ficher créé");
    }


    return 0;
}