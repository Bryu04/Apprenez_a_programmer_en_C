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

    // Affficher notre liste chainée
    afficherListe(mesnombres);

    // Afficher la taille de la liste chainée
    tailleListe(mesnombres);

    // Supprimer le dernier élément ajouté
    suppression(mesnombres);

    // Affficher notre liste chainée
    afficherListe(mesnombres);

    // Afficher la taille de la liste chainée
    tailleListe(mesnombres);

    // Recherche la position d'un nombre
    rechercheIndice(mesnombres, 10);

    // Ajouter un nouveau élément au milieu
    insertionMilieu(mesnombres, 30, 3);

    // Affficher notre liste chainée
    afficherListe(mesnombres);

    // Afficher la taille de la liste chainée
    tailleListe(mesnombres);

    // Supprimer un élément au milieu
    suppressionMilieu(mesnombres, 2);

    // Affficher notre liste chainée
    afficherListe(mesnombres);

    // Afficher la taille de la liste chainée
    tailleListe(mesnombres);

    // Supprimer la liste chainée (Attention : il faut bien indiquer la variable au début de la fonction pour que le pointeur soit bien redirigé vers NULL)
    mesnombres = suppressionListe(mesnombres);

    // Affficher notre liste chainée
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
    liste->nbElements = 1; // Initialement, la liste contient un seul élément
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
    // Et on augmente la taille de la liste
    liste->nbElements++;
    
}

// On va ajouter un nouveau élément au milieu de la liste à une position définie.
void insertionMilieu(Liste *liste, int nvNombre, int position)
{
    // On va créer un nouveau élément avec la structure Element
    Element *nouveau = malloc(sizeof(*nouveau));

    // On vérifie que la mémoire a bien été alloué au nouveau élément
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va partir du premier élément et qu'on va boucler jusqu'à la position indiqué -1
    Element *actuel = liste->premier;
    int counter = 1;

    while (counter != position-1)
    {
        actuel = actuel->suivant;
        counter++;
    }
    
    // On donne la valeur du nouveau nombre au sous-variable de la variable nouveau
    nouveau->nombre = nvNombre;

    // Puis on pointe le nouveau élément à l'élément qui suit l'actuel élément
    nouveau->suivant = actuel->suivant;

    // Enfin on change le pointeur de l'élément actuel vers le nouveau élément
    actuel->suivant = nouveau;

    // Et on augmente la taille de la liste
    liste->nbElements++;

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

        // Puis on diminue la taille de la liste
        liste->nbElements--;
    }
}

// On crée une autre fonction de suppression qui va supprimer un élément au milieu de la liste
void suppressionMilieu(Liste *liste, int position)
{
    // On vérifie si la liste a déjà été crée avant
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va partir du premier élément et qu'on va boucler jusqu'à la position indiqué-1
    Element *elementprecedent = liste->premier;
    int counter = 1;

    while (counter != position-1)
    {
        elementprecedent = elementprecedent->suivant;
        counter++;
    }

    // Création d'une variable aSupprimer qui est la suivant de l'élémentprecedent
    Element *aSupprimer = elementprecedent->suivant;

    // On change d'abord le pointeur suivant de l'élementprecedent vers l'élément qui suit
    // celui qu'on veut supprimer
    elementprecedent->suivant = aSupprimer->suivant;

    // Puis on libère la mémoire reservé pour cet élément qu'on veut supprimer
    free(aSupprimer);

    // Puis on diminue la taille de la liste
    liste->nbElements--;
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

// Rechercher l'indice d'une valeur dans la liste chainée
void rechercheIndice(Liste *liste, int chnombre)
{
    // On vérifie si la liste a déjà été crée avant
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va partir du premier élément et qu'on va boucler jusqu'à trouver l'élément qui 
    // contient notre nombre
    Element *actuel = liste->premier;
    int counter = 1;

    while (actuel->nombre != chnombre)
    {
        actuel = actuel->suivant;
        counter++;
    }
    
    printf("La valeur %d se trouve à la position : %d\n", chnombre, counter);
}

// Supprimer la liste complete
Liste *suppressionListe(Liste *liste)
{
    // Ici on va d'abord supprimer les éléments un à un avant de supprimer la liste
    // On vérifie si la liste existe déjà
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va partir du premier élément et qu'on va boucler jusqu'au dernier élément
    Element *actuel = liste->premier;
    Element *aSupprimer = NULL;


    while (actuel != NULL)
    {
        aSupprimer = actuel; // On récupère l'adresse de l'actuel élément
        actuel = actuel->suivant; // On passe au élément suivant
        
        // Puis on libère la mémoire reservé pour l'élément actuel
        free(aSupprimer);
    }

    // Quand on a fini de supprimer tous les éléments de la liste, on peut supprimer la liste
    free(liste->premier);
    free(liste);

    //
    return NULL;

}

// Pour connaitre la taille de la liste
void tailleListe(Liste *liste)
{
    // Pour connaitre la taille de la liste, on affiche la valeur de nbElements
    printf("La taille actuelle de la liste est : %d\n", liste->nbElements);
}