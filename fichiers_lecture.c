/*
  
Le fichier fichiers_lecture.c est un petit programme qui va permettre de lire des fichiers grace aux fonctions.

*/

#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 1000 // Taille de la chaine

int main(int argc, const char * argv[]) {

    // Création du pointeur monfichier
    FILE *monficher = NULL;

    monficher = fopen("test_read.txt", "r");
    // Utilisation de la fonction fgetc
    // La fonciton fgetc permet de lire un caractère depuis un fichier texte.
    // Pour lire tout le contenu du fichier, on va utiliser une boucle
    int caractereActuel = 0;

    if (monficher != NULL)
    {
        printf("--- Debut de la lecture ---------\n");
        //Boucle de lecture des caracteres un à un
        do
        {
            caractereActuel = fgetc(monficher);
            printf("%c", caractereActuel);
        } while (caractereActuel != EOF);
        printf("\n");
        // On n'oublie pas de fermer le fichier
        fclose(monficher);
        printf("----- Fin de la lecture ---------\n");
    }

    // Utilisation de la fonction fgets
    // La fonction fgets, comparé au fgetc, permet de lire une chaine dans un fichier.
    // Pour cela on va utiliser la directive #define pour limiter la taille de la chaine

    // Reinitialiser le pointeur
    monficher = NULL;
    // Ouverture du fichier
    monficher = fopen("test_read.txt", "r");

    char chaine[TAILLE_MAX];

    if (monficher != NULL)
    {
        printf("--- Debut de la lecture pour une chaine ---\n");
        fgets(chaine, TAILLE_MAX, monficher);
        printf("%s\n", chaine);
        printf("----- Fin de la lecture de la chaine ------\n");
        fclose(monficher);
    }
    
    // Pour lire plusieurs lire du fichier avec fgets, on va faire une boucle.

    FILE *monficher2 = NULL;
    char chaine2[TAILLE_MAX];
    // Ouverture du fichier
    monficher2 = fopen("test_read_2.txt", "r");

    if (monficher2 != NULL)
    {
        printf("--- Debut de la lecture du fichier test_read_2.txt ---\n");
        while (fgets(chaine2, TAILLE_MAX, monficher2) != NULL)
        {
            printf("%s", chaine2);
        }
        printf("\n");
        fclose(monficher2);
        printf("---- Fin de la lecture du fichier test_read_2.txt ----\n");
    }
    
    // Utilisation de la fonction fscanf
    // La fonction fscanf ressemble beaucoup à la fonction scanf, mais au lieu de récupérer
    // une entrée, elle va le récupérer depuis un fichier.

    FILE *monficher3 = NULL;
    int score[3] = {0};

    monficher3 = fopen("test_score.txt", "r");

    if (monficher3 != NULL)
    {
        printf("--- Debut de la lecture des scores ---\n");
        fscanf(monficher3, "%d %d %d", &score[0], &score[1], &score[2]);
        printf("Les meilleurs scores sont : %d, %d et %d\n", score[0], score[1], score[2]);
        fclose(monficher3);
        printf("---- Fin de la lecture des scores ----\n");
    }
    

    return 0;
}