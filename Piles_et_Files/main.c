/*

main.c
Dans ce programme, on va stocker des données avec les piles et les files
*/

#include <stdio.h>
#include <stdlib.h>

// Inclure le fichier main.h
#include "main.h"

int main(int argc, const char * argv[]) {
    
    // Testons nos fonctions et structures
    printf("------- Tester la structure Pile -------\n");
    Pile *maPile = initialiser();

    // Inserer des nouveaux éléments
    empiler(maPile, 4);
    empiler(maPile, 8);
    empiler(maPile, 15);
    empiler(maPile, 16);
    empiler(maPile, 23);
    empiler(maPile, 42);

    // Affficher notre pile
    printf("Etat de la pile :\n");
    afficherPile(maPile);

    // Dépiler des éléments
    printf("Je depile %d\n", depiler(maPile));
    printf("Je depile %d\n", depiler(maPile));

    printf("Etat de la pile :\n");
    afficherPile(maPile);

    printf("----------------------------------------\n");
    printf("------- Tester la structure File -------\n");
    // On fait de même pour la structure File
    File *maFile = initialisation();

    // Enfilage des nouveau éléments
    enfiler(maFile, 4);
    enfiler(maFile, 8);
    enfiler(maFile, 15);
    enfiler(maFile, 16);
    enfiler(maFile, 23);
    enfiler(maFile, 42);

    // Afficher la File
    printf("Etat de la file :\n");
    afficherFile(maFile);

    // Défiler des éléments
    printf("Je defile %d\n", defiler(maFile));
    printf("Je defile %d\n", defiler(maFile));

    // Afficher la File
    printf("Etat de la file :\n");
    afficherFile(maFile);

    printf("----------------------------------------\n");
    return 0;
}


// Initialisation de la pile
Pile *initialiser()
{
    Pile *pile = malloc(sizeof(*pile));
    Element *element = malloc(sizeof(*element));

     // On vérifie que l'allocation de la mémoire s'est bien passé
     if (pile == NULL || element == NULL)
     {
         // On arrête tout
         exit(EXIT_FAILURE);
     }

     // Si c'est bien passé, on initie les valeurs pour chaque sous-variables
    element->nombre = 0;  // Le nombre est nulle
    element->suivant = NULL; // Ici, notre premier élément est aussi le dernier élément
                             // Donc, on met son pointeur suivant vers NULL
    pile->premier = element; // La pile pointe vers le premier élément.
}

// Empilage d'un élément
void empiler(Pile *pile, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));

    if (pile == NULL || nouveau == NULL)
    {
        // On arrete le programme
        exit(EXIT_FAILURE);
    }

    // On donne la valeur du nouveau nombre au sous-variable de la variable nouveau
    nouveau->nombre = nvNombre;

    // Puis on insere le nouveau élément au début de la liste
    nouveau->suivant = pile->premier;  // D'abord on pointe le nouveau élément vers l'ancien 
                                        // premier élément
    pile->premier = nouveau;  // Puis, on pointe le pointeur premier vers le nouveau élément
    
    
}

// Dépilage d'un élément
// Cette fois-ci, on enlève l'élément et on affiche la valeur

int depiler(Pile *pile)
{
    if (pile == NULL)
    {
        // On arrete le programme
        exit(EXIT_FAILURE);
    }

    // On crée une variable pour le nombre à depiler
    int nombreDepile = 0;
    // Et le pointeur qui pointe sur le premier élément
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        nombreDepile = elementDepile->nombre;
        // On change d'abord le pointeur premier vers l'élément suivant
        pile->premier = elementDepile->suivant;
        // Puis on libère la mémoire reservé pour cet élément qu'on veut supprimer
        free(elementDepile);
    }

    // Et finalement on retourne la valeur qui a été dépilé
    return nombreDepile;

}

// Afficher la pile
void afficherPile(Pile *pile)
{
    // On vérifie si la pile a déjà été crée avant
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va partir du premier élément et qu'on va boucler jusqu'au dernier élément
    Element *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->nombre); // On imprime le nombre
        actuel = actuel->suivant; // On passe au élément suivant
    }

    printf("\n");
}


// On va faire de même pour les Files
// Initialisation de la File

File *initialisation()
{
    File *file = malloc(sizeof(*file));
    Element *element = malloc(sizeof(*element));

     // On vérifie que l'allocation de la mémoire s'est bien passé
     if (file == NULL || element == NULL)
     {
         // On arrête tout
         exit(EXIT_FAILURE);
     }

     // Si c'est bien passé, on initie les valeurs pour chaque sous-variables
    element->nombre = 0;  // Le nombre est nulle
    element->suivant = NULL; // Ici, notre premier élément est aussi le dernier élément
                             // Donc, on met son pointeur suivant vers NULL
    file->premier = element; // La file pointe vers le premier élément.
}


// Enfilage d'un élément
// Ici, le nouvel élément sera mis à la fin de la File
void enfiler(File *file, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        file->premier = nouveau;
    }
}

// Défilage d'un élement
// C'est comme le dépilage, on enlève le premier élément
int defiler(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On crée une variable pour le nombre à depile
    int nombreDefile = 0;

    /* On vérifie s'il y a quelque chose à défiler */
    if (file->premier != NULL)
    {
        Element *elementDefile = file->premier;

        nombreDefile = elementDefile->nombre;
        // On change d'abord le pointeur premier vers l'élément suivant
        file->premier = elementDefile->suivant;
        // Puis on libère la mémoire reservé pour cet élément qu'on veut supprimer
        free(elementDefile);
    }

    // Et finalement on retourne la valeur qui a été défilé
    return nombreDefile;
}

// Afficher la file
void afficherFile(File *file)
{
    // On vérifie si la file a déjà été crée avant
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va partir du premier élément et qu'on va boucler jusqu'au dernier élément
    Element *actuel = file->premier;

    while (actuel != NULL)
    {
        printf("%d ", actuel->nombre); // On imprime le nombre
        actuel = actuel->suivant; // On passe au élément suivant
    }

    printf("\n");
}