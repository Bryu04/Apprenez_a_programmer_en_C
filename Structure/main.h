/*
----------
main.h
----------

Role :

Ce fichier contient les prototypes et les structures qui seront utilisés dans le fichier main.c 

*/

// On commence par la directive #ifndef pour éviter les inclusions en boucles infinies

#ifndef main_h
#define main_h

#include <stdbool.h> // Pour le type bool

// Création d'une structure pour se déplacer en 2D

struct Coordonnees
{
    int x; // Coordonnée Abscisses
    int y; // Coordonnée Ordonnées
};

// Création d'une structure pour les caractéristique d'une personne 

struct Personne
{
    char nom[100];
    char prenom[100];
    char adresse[1000];

    int age;
    bool etudiant; // Booléen : True or False
};


#endif  // fin de main_j