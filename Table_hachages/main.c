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
    // Testons notre table de hachage
    TableHachage *maclasseCM = initialisation();

    // Inserer des nouveaux éléments
    insertion(maclasseCM, "Alice", 24, 15);
    insertion(maclasseCM, "Bob", 14, 25);
    insertion(maclasseCM, "Charlie", 18, 12);

    // Affficher notre table de hachage
    afficherTable(maclasseCM);
    // Afficher le nombre d'élèves
    nombreEleve(maclasseCM);

    printf("--------------------\n");
    // Supprimer un élève de la table
    suppression(maclasseCM, "Bob");
    // Affficher notre table de hachage
    afficherTable(maclasseCM);
    // Afficher le nombre d'élèves
    nombreEleve(maclasseCM);

    printf("--------------------\n");
    // Inserer des nouveaux éléments
    insertion(maclasseCM, "Dylan", 22, 10);
    insertion(maclasseCM, "Emily", 19, 29);
    insertion(maclasseCM, "Fred", 26, 16);

    // Affficher notre table de hachage
    afficherTable(maclasseCM);
    // Afficher la nombre d'élèves
    nombreEleve(maclasseCM);

    printf("--------------------\n");

    // Supprimer la liste chainée (Attention : il faut bien indiquer la variable au début de la fonction pour que le pointeur soit bien redirigé vers NULL)
    maclasseCM = suppressionTable(maclasseCM);

    // Affficher notre liste chainée
    //afficherListe(maclasseCM);


    return 0;
}



// Fonctions qui va manipuler les structures éléments et liste pour la liste chainée
// Pour commencer, il faut initier la structure de controle.

TableHachage *initialisation()
{
    TableHachage *tablehachage = malloc(sizeof(*tablehachage));

    // On vérifie que l'allocation de la mémoire s'est bien passé
    if (tablehachage == NULL)
    {
        // On arrête tout
        exit(EXIT_FAILURE);
    }
    
    // Si c'est bien passé, on initie les valeurs pour chaque sous-variables
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        tablehachage->table[i] = NULL;
    }
    
    return tablehachage;
}

// Maintenant on va ajouter un nouveau élevè au début de la liste chaînée.
void insertion(TableHachage *tablehachage, char nvNom[100], int nvAge, int nvNote)
{
    // Ici on va utiliser la fonction de hachage sur le nom
    int index = hachage(nvNom);
    // On va créer un nouveau élément avec la structure Eleve
    Eleve *nouveau = malloc(sizeof(*nouveau));

    // On vérifie que la mémoire a bien été alloué au nouveau élément
    if (nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    // On donne les valeurs aux sous-variables de la variable nouveau
    strcpy(nouveau->nom, nvNom); // Ici on copie le tableau char dans une autre
    nouveau->age = nvAge;
    nouveau->moyenne = nvNote;

    // Puis on sauvegard l'indice dans la table de hachage;
    tablehachage->table[index] = nouveau;
}


// On va afficher la liste des nom dans la classe
void afficherTable(TableHachage *tablehachage) 
{
    printf("Contenu de la table de hachage :\n");

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (tablehachage->table[i] != NULL)
        {
            Eleve *eleve = tablehachage->table[i];
            printf("Index %d : %s, âge : %d, moyenne : %d\n", 
                    i, eleve->nom, eleve->age, eleve->moyenne);
        }
    }
}

// On va aussi créer une fonction pour supprimer un élève de la table
void suppression(TableHachage *tablehachage, char supNom[100])
{
    // On vérifie si la table a déjà été crée avant
    if (tablehachage == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Ici on va utiliser la fonction de hachage sur le nom
    int index = hachage(supNom);

    // Création d'une variable aSupprimer
    Eleve *aSupprimer = tablehachage->table[index];

    // Puis on libère la mémoire reservé pour cet élément qu'on veut supprimer
    free(aSupprimer);
    tablehachage->table[index] = NULL;
    
}



// Supprimer la table complete
TableHachage *suppressionTable(TableHachage *tablehachage)
{
    // Ici on va d'abord supprimer les éléments un à un avant de supprimer la liste
    // On vérifie si la liste existe déjà
    if (tablehachage == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va balayer dans tous le tableau et supprimer tous les données
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (tablehachage->table[i] != NULL)
        {
            Eleve *aSupprimer = tablehachage->table[i];
            // Puis on libère la mémoire reservé pour l'élément actuel
            free(aSupprimer);
            // Et on met le pointeur vers NULL
            tablehachage->table[i] = NULL;
        }
        
    }
    
    // Quand on a fini de supprimer tous les éléments de la liste, on peut supprimer la liste
    free(tablehachage);

    //
    return NULL;

}

// Pour connaitre la taille de la liste
void nombreEleve(TableHachage *tablehachage)
{
    if (tablehachage == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int compteur = 0;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (tablehachage->table[i] != NULL)
        {
            compteur++;
        }
    }

    printf("Il y a %d élève(s) dans la table.\n", compteur);
}

// Fonction de hachage sur le nom d'élève
int hachage(char *chaine)
{
    int i = 0, nombreHache = 0;

    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= 100;

    return nombreHache;
}