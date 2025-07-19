/*

main.c
Dans ce programme, on va utiliser des listes chainées qu'on a créé
puis on va créer une fonction de hachages pour accéder aux éléments de la liste plus vite

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inclure le fichier main.h
#include "main.h"

int main(int argc, const char * argv[]) {
    // Testons notre liste chainée Eleve
    Liste *maclasseCM = initialisation();

    // Inserer des nouveaux éléments
    insertion(maclasseCM, "Alice", 24, 15);
    insertion(maclasseCM, "Bob", 14, 25);
    insertion(maclasseCM, "Charlie", 18, 12);

    // Affficher notre liste chainée
    afficherListe(maclasseCM);
    // Afficher la taille de la liste chainée
    tailleListe(maclasseCM);

    printf("--------------------\n");
    // Supprimer le dernier élément ajouté
    suppression(maclasseCM);
    // Affficher notre liste chainée
    afficherListe(maclasseCM);
    // Afficher la taille de la liste chainée
    tailleListe(maclasseCM);

    printf("--------------------\n");
    // Inserer des nouveaux éléments
    insertion(maclasseCM, "Dylan", 22, 10);
    insertion(maclasseCM, "Emily", 19, 29);
    insertion(maclasseCM, "Fred", 26, 16);

    // Affficher notre liste chainée
    afficherListe(maclasseCM);
    // Afficher la taille de la liste chainée
    tailleListe(maclasseCM);

    printf("--------------------\n");
    // Ajouter un nouveau élément au milieu
    insertionMilieu(maclasseCM, "Caroline du Nord", 29, 14, 3);

    // Affficher notre liste chainée
    afficherListe(maclasseCM);
    // Afficher la taille de la liste chainée
    tailleListe(maclasseCM);
    printf("--------------------\n");

    // Supprimer un élément au milieu
    suppressionMilieu(maclasseCM, 4);

    afficherListe(maclasseCM);
    // Afficher la taille de la liste chainée
    tailleListe(maclasseCM);

    printf("--------------------\n");

    // Supprimer la liste chainée (Attention : il faut bien indiquer la variable au début de la fonction pour que le pointeur soit bien redirigé vers NULL)
    maclasseCM = suppressionListe(maclasseCM);

    // Affficher notre liste chainée
    //afficherListe(maclasseCM);


    return 0;
}



// Fonctions qui va manipuler les structures éléments et liste pour la liste chainée
// Pour commencer, il faut initier la structure de controle.

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    // On vérifie que l'allocation de la mémoire s'est bien passé
    if (liste == NULL)
    {
        // On arrête tout
        exit(EXIT_FAILURE);
    }
    
    // Si c'est bien passé, on initie les valeurs pour chaque sous-variables
    liste->premier = NULL; // Ici, seul la liste est créée, pas d'élément.
    liste->nbEleve = 0; // Initialement, la liste est vide.
}

// Maintenant on va ajouter un nouveau élevè au début de la liste chaînée.
void insertion(Liste *liste, char nvNom[100], int nvAge, int nvNote)
{
    // On va créer un nouveau élément avec la structure Eleve
    Eleve *nouveau = malloc(sizeof(*nouveau));

    // On vérifie que la mémoire a bien été alloué au nouveau élément
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    // On donne les valeurs aux sous-variables de la variable nouveau
    strcpy(nouveau->nom, nvNom); // Ici on copie le tableau char dans une autre
    nouveau->age = nvAge;
    nouveau->moyenne = nvNote;

    // Puis on insere le nouveau élément au début de la liste
    nouveau->suivant = liste->premier;  // D'abord on pointe le nouveau élément vers l'ancien 
                                        // premier élément
    liste->premier = nouveau;  // Puis, on pointe le pointeur premier vers le nouveau élément
    // Et on augmente la taille de la liste
    liste->nbEleve++;
}

// De même, on va ajouter un nouveau élève au milieu de la liste à une position définie.
void insertionMilieu(Liste *liste, char nvNom[100], int nvAge, int nvNote, int position)
{
    // On va créer un nouveau élément avec la structure Element
    Eleve *nouveau = malloc(sizeof(*nouveau));

    // On vérifie que la mémoire a bien été alloué au nouveau élément
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va partir du premier élément et qu'on va boucler jusqu'à la position indiqué -1
    Eleve *actuel = liste->premier;
    int counter = 1;

    while (counter != position-1)
    {
        actuel = actuel->suivant;
        counter++;
    }
    
    // On donne la valeur du nouveau nombre au sous-variable de la variable nouveau
    strcpy(nouveau->nom, nvNom); // Ici on copie le tableau char dans une autre
    nouveau->age = nvAge;
    nouveau->moyenne = nvNote;

    // Puis on pointe le nouveau élément à l'élément qui suit l'actuel élément
    nouveau->suivant = actuel->suivant;

    // Enfin on change le pointeur de l'élément actuel vers le nouveau élément
    actuel->suivant = nouveau;

    // Et on augmente la taille de la liste
    liste->nbEleve++;

}

// On va afficher la liste classe
void afficherListe(Liste *liste) {
    Eleve *actuel = liste->premier;
    while (actuel != NULL) {
        printf("Nom: %s, Âge: %d, Moyenne: %d\n", actuel->nom, actuel->age, actuel->moyenne);
        actuel = actuel->suivant;
    }
}

// On va aussi créer une fonction pour supprimer le premier élève de la liste
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
        Eleve *aSupprimer = liste->premier;

        // On change d'abord le pointeur premier vers l'élément suivant
        liste->premier = liste->premier->suivant;

        // Puis on libère la mémoire reservé pour cet élément qu'on veut supprimer
        free(aSupprimer);

        // Puis on diminue la taille de la liste
        liste->nbEleve--;
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
    Eleve *elementprecedent = liste->premier;
    int counter = 1;

    while (counter != position-1)
    {
        elementprecedent = elementprecedent->suivant;
        counter++;
    }

    // Création d'une variable aSupprimer qui est la suivant de l'élémentprecedent
    Eleve *aSupprimer = elementprecedent->suivant;

    // On change d'abord le pointeur suivant de l'élementprecedent vers l'élément qui suit
    // celui qu'on veut supprimer
    elementprecedent->suivant = aSupprimer->suivant;

    // Puis on libère la mémoire reservé pour cet élément qu'on veut supprimer
    free(aSupprimer);

    // Puis on diminue la taille de la liste
    liste->nbEleve--;
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
    Eleve *actuel = liste->premier;
    Eleve *aSupprimer = NULL;


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
    printf("Il y a  %d élèves dans la classe. \n", liste->nbEleve);
}