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
        printf("-----------------------------------\n");
    }
    else
    {
        printf("Impossible d'ouvrir le ficher test_read.txt : Le fichier n'existe pas !!\n");
        printf("Création du fichier : test_read.txt \n");
        monfichier = fopen("test_read.txt", "w");
        printf("et on ferme le fichier après création par l'ouverture\n");
        fclose(monfichier);
        printf("Ficher créé");
        printf("-----------------------------------\n");
    }

    // Maintenant qu'on a vu comment ouvrir un fichier, on va l'éditeur
    // On réinitie la variable monfichier avant d'ouvrir un autre fichier
    monfichier = NULL;
    monfichier = fopen("test_write.txt", "w");
    // Utilisation de la fonction fputc
    // La fonction fputc permet d'écrire un caractère dans un fichier.
    if (monfichier != NULL)
    {
        printf("---- Ecriture d'un caractere ------\n");
        fputc('C', monfichier);
        fclose(monfichier);
        printf("Fin de l'écriture\n");
        printf("-----------------------------------\n");
    }


    // Utilisation de la fonction fputs
    // La fonction fputs, comparé à fputc, permet d'écrire une chaine de caractères dans
    // un fichier.
    // On réinitie la variable monfichier avant d'ouvrir un autre fichier
    monfichier = NULL;
    monfichier = fopen("test_write_2.txt", "w");

    if (monfichier != NULL)
    {
        printf("---- Ecriture d'une chaine de caracteres ------\n");
        fputs("Hello guys !!\nWelcome to my site.", monfichier);
        fclose(monfichier);
        printf("Fin de l'écriture\n");
        printf("-----------------------------------------------\n");
    }

    // Utilisation de la fonction fprintf
    // La fonction fprintf ressemble beaucoup à printf sauf elle écrit le contenu dans un
    // fichier. (Un peu comme sprintf qui écrit le contenu dans une chaine de caractères)
    int age = 0;
    char nom[100];
    // On réinitie la variable monfichier avant d'ouvrir un autre fichier
    monfichier = NULL;
    monfichier = fopen("test_write_3.txt", "w");

    if (monfichier != NULL)
    {
        printf("Quel est votre nom ? : ");
        scanf("%s", nom);
        printf("Quel est votre age ? : ");
        scanf("%d", &age);
        
        printf("---- Ecriture des informations dans un fichier ------\n");
        fprintf(monfichier, "Monsieur %s, qui utilise le programme, dit qu'il a %d ans",
                nom, age);
        fclose(monfichier);
        printf("Fin de l'écriture\n");
        printf("-----------------------------------------------------\n");
    }

    return 0;
}