/*

main.c
Dans ce programme, on va utiliser des listes chainées qu'on a créé
*/

#include <stdio.h>
#include <stdlib.h>

// Inclure le fichier main.h
#include "main.h"

int main(int argc, const char * argv[]) {
    // Testons nos fonctions et structures
    Liste *mesnombres = initialisation();

    // Inserer des nouveaux éléments
    insertion(mesnombres, 50);
    insertion(mesnombres, 10);
    insertion(mesnombres, 24);
    insertion(mesnombres, 35);

    // Supprimer le dernier élément ajouté
    suppression(mesnombres);

    //Affficher notre liste chainée
    afficherListe(mesnombres);

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

// Maintenant on va ajouter un nouveau élément au début de la liste chaînée.
void insertion(Liste *liste, int nvNombre)
{
    // On va créer un nouveau élément avec la structure Element
    Element *nouveau = malloc(sizeof(*nouveau));

    // On vérifie que la mémoire a bien été alloué au nouveau élément
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    // On donne la valeur du nouveau nombre au sous-variable de la variable nouveau
    nouveau->nombre = nvNombre;

    // Puis on insere le nouveau élément au début de la liste
    nouveau->suivant = liste->premier;  // D'abord on pointe le nouveau élément vers l'ancien 
                                        // premier élément
    liste->premier = nouveau;  // Puis, on pointe le pointeur premier vers le nouveau élément
    
}

// On va aussi créer une fonction pour supprimer le premier élément
void suppression(Liste *liste)
{
    // On vérifie si la liste a déjà été crée avant
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On vérifie ensuite si notre liste pointe vers le premier élément existe
    if (liste->premier != NULL)
    {
        // Création d'une variable aSupprimer
        Element *aSupprimer = liste->premier;

        // On change d'abord le pointeur premier vers l'élément suivant
        liste->premier = liste->premier->suivant;

        // Puis on libère la mémoire reservé pour cet élément qu'on veut supprimer
        free(aSupprimer);
    }
}


// La suite est d'afficher les valeurs de la liste chainée
void afficherListe(Liste *liste)
{
    // On vérifie si la liste a déjà été crée avant
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va partir du premier élément et qu'on va boucler jusqu'au dernier élément
    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre); // On imprime le nombre
        actuel = actuel->suivant; // On passe au élément suivant
    }
    
    // À la fin, on imprime "NULL" pour dire qu'on est à la fin de la liste chainée
    printf("NULL\n");
}