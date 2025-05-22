/*

main.c
Dans ce programme, on va utiliser des listes chainées qu'on a créé
*/

#include <stdio.h>
#include <stdlib.h>

// Inclure le fichier main.h
#include "main.h"

int main(int argc, const char * argv[]) {

    return 0;
}



// Fonctions qui va manipuler les structures éléments et liste pour la liste chainée
// Pour commencer, il faut initier la structure de controle et la structure des éléments

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    // On vérifie que l'allocation de la mémoire s'est bien passé
    if (liste == NULL || element == NULL)
    {
        // On arrête tout
        exit(EXIT_FAILURE);
    }
    
    // Si c'est bien passé, on initie les valeurs pour chaque sous-variables
    element->nombre = 0;  // Le nombre est nulle
    element->suivant = NULL; // Ici, notre premier élément est aussi le dernier élément
                             // Donc, on met son pointeur suivant vers NULL
    liste->premier = element; // La liste pointe vers le premier élément.
}