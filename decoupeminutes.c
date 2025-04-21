#include <stdio.h>   
#include <stdlib.h>

// On met les prototypes des fonctions qu'on va utiliser

void nedecoupepasMinutes(int heures, int minutes);

void decoupeMinutes(int *pointeurHeures, int *pointeurMinutes);

int main(int argc, const char * argv[]) {
    // Initialisation des paramètres de départ
    int heures = 0, minutes = 90;

    nedecoupepasMinutes(heures, minutes);

    // Ici on s'attend que ça ne marche pas
    printf("%d heures et %d minutes \n", heures, minutes);

    decoupeMinutes(&heures, &minutes);

    // Ici ça marche car on utilise l'adresse des variables pour les modifier
    printf("%d heures et %d minutes \n", heures, minutes);

    return 0;
}


void nedecoupepasMinutes(int heures, int minutes)
{
    // Les variables heures et minutes créées ici sont différentes de celles créées
    // dans la fonction main => donc pas les mêmes adresses de variables.
    // Aussi, quand la fonction sera terminé, ces 2 variables ici seront supprimées
    heures = minutes / 60;  // 90 / 60 = 1
    minutes = minutes % 60; // 90 % 60 = 30
}

void decoupeMinutes(int *pointeurHeures, int *pointeurMinutes)
{
    // Attention il faut mettre des étoiles devant les nom des pointeurs 
    // afin de pouvoir modifier la valeur des variables et non leur adresse.
    *pointeurHeures = *pointeurMinutes / 60;
    *pointeurMinutes = *pointeurMinutes % 60;
}