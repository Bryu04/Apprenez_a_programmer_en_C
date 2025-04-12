/*
----------
fonctions.c
----------

Role :

Ce fichier contient les fonctions qui sont utilisé par la fonction main du jeu plus ou moins

*/

#include "fonctions.h"

static void oukilailenombre(int nombre_entrer, int nombre_mystere)
{
    if (nombre_mystere > nombre_entrer)
        printf("C'est plus !\n");
    else if (nombre_mystere < nombre_entrer)
        printf("C'est moins !\n");
    else
        printf("Bravo, vous avez trouve le nombre mystere !!!\n");
}