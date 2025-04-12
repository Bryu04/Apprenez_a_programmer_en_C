/*
  
main.c

La fonction principale pour le jeu "plus ou moins"

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Include les fichiers .h
#include "fonctions.h"
// Pour visual studio, il faut include aussi le fichier .c
#include "fonctions.c"  

int main(int argc, const char * argv[]) {

    // Définition des constantes
    const int MAX = 100, MIN = 1;

    //Declarer la variable initiale
    int nombreMystere = 0;
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

    // Initiation de la variable pour stocker le nombre Entré
    int nombreEntre = 0;

    // Introduction du jeu
    printf("---- JEU PLUS OU MOINS ----\n");
    printf("Bienvenue dans le jeu 'plus ou moins' !!!\n");
    printf("Votre mission si vous acceptez est de trouver le nombre mystEre que l'ordinateur cache.\n");
    printf("\n");
    printf("Veuillez entrer un nombre : ");

    // Capture de nombre entré
    scanf("%d", &nombreEntre);

    // Boucles while
    while (nombreMystere != nombreEntre)
    {
        oukilailenombre(nombreEntre,nombreMystere);
        scanf("%d", &nombreEntre);
    }
    
    oukilailenombre(nombreEntre,nombreMystere);

    return 0;
}