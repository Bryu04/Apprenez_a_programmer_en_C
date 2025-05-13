/*
----------
main.h
----------

Role :

Ce fichier contient les prototypes et les structures qui seront utilisés dans le fichier 
main.c. Les structures sont des assemblage de variables qui peuvent avoir différents types, 
même des tableaux.

Il contient aussi les énumérations. Ces derniers permettent aussi de créer des types de
variables mais contrairement aux structures, une énumération estune liste de valeurs 
possibles pour une variable. Une énumération ne prend donc qu'une case en mémoire.
*/

// On commence par la directive #ifndef pour éviter les inclusions en boucles infinies

#ifndef main_h
#define main_h

#include <stdbool.h> // Pour le type bool

// Création d'une structure pour se déplacer en 2D

typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
    int x; // Coordonnée Abscisses
    int y; // Coordonnée Ordonnées
};

// Création d'une structure pour les caractéristique d'une personne 

typedef struct Personne Personne;
struct Personne
{
    char nom[100];
    char prenom[100];
    char adresse[1000];

    int age;
    bool etudiant; // Booléen : True or False
};


// Création d'une énumération pour le son
typedef enum Volume Volume;
enum Volume
{
    MUET = 0, FAIBLE = 10, MOYEN = 50, FORT = 100
};

// Prototypes utilisées
void initialiserCoordonnees(Coordonnees *point);

void initialiserPersonne(Personne *utilisateur);

#endif  // fin de main_j