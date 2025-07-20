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

    printf("########### TEST AVEC DES COLLISION #################\n");
    printf("------- Méthode 1 : Adressage linéaire --------\n");
    //Initialisation
    TabHacOA *maclasseCE1 = initiation();

    //Insertion des nouveaux élèves
    insertionOA(maclasseCE1, "Alice Monster", 18, 26);
    insertionOA(maclasseCE1, "Ball Singer", 15, 27);
    insertionOA(maclasseCE1, "Charlie Chocolatrie", 13, 12);
    insertionOA(maclasseCE1, "Bill Sanger", 25, 24);

    // Afficher notre table
    afficherTableOA(maclasseCE1);

    // Afficher le nombre d'élèves
    nombreEleveOA(maclasseCE1);
    printf("--------------------\n");

    // Supprimer un élève de la table
    suppressionOA(maclasseCE1, "Alice Monster");

    // Afficher notre table
    afficherTableOA(maclasseCE1);

    // Afficher le nombre d'élèves
    nombreEleveOA(maclasseCE1);
    printf("--------------------\n");

    // Insertion des nouveaux élèves
    insertionOA(maclasseCE1, "Silent Mac Roe", 15, 30);
    insertionOA(maclasseCE1, "Charlote Chicolarie", 25, 14);

    // Afficher notre table
    afficherTableOA(maclasseCE1);

    // Afficher le nombre d'élèves
    nombreEleveOA(maclasseCE1);
    printf("--------------------\n");

    // Supprimer un élève de la table
    suppressionOA(maclasseCE1, "Charlote Chicolarie");

    // Afficher notre table
    afficherTableOA(maclasseCE1);

    // Afficher le nombre d'élèves
    nombreEleveOA(maclasseCE1);
    printf("--------------------\n");

    // Supprimer la liste chainée (Attention : il faut bien indiquer la variable au début de la fonction pour que le pointeur soit bien redirigé vers NULL)

    maclasseCE1 = suppressionTableOA(maclasseCE1);

    // Afficher notre table
    //afficherTableOA(maclasseCE1);

    printf("-----------------------------------------------\n");
    printf("------- Méthode 2 : Chaînage --------\n");
    // Initialisation
    TabHacChain *maclasseCM2 = initialiser();

    // Insertion des nouveaux élèves
    insertionchain(maclasseCM2, "Alice Monster", 18, 26);
    insertionchain(maclasseCM2, "Ball Singer", 15, 27);
    insertionchain(maclasseCM2, "Charlie Chocolatrie", 13, 12);
    insertionchain(maclasseCM2, "Bill Sanger", 25, 24);
    

    // Afficher notre table
    afficherChainTable(maclasseCM2);

    // Afficher le nombre d'élèves
    nombreEleveChain(maclasseCM2);

    printf("--------------------\n");

    // Supprimer un élève de la table
    suppressionchain(maclasseCM2, "Alice Monster");

    // Afficher notre table
    afficherChainTable(maclasseCM2);

    // Afficher le nombre d'élèves
    nombreEleveChain(maclasseCM2);

    printf("--------------------\n");

    // Insertion des nouveaux élèves
    insertionchain(maclasseCM2, "Silent Mac Roe", 15, 30);
    insertionchain(maclasseCM2, "Charlote Chicolarie", 25, 14);

    // Afficher notre table
    afficherChainTable(maclasseCM2);

    // Afficher le nombre d'élèves
    nombreEleveChain(maclasseCM2);

    printf("--------------------\n");

    // Supprimer un élève de la table
    suppressionchain(maclasseCM2, "Bill Sanger");

    // Afficher notre table
    afficherChainTable(maclasseCM2);

    // Afficher le nombre d'élèves
    nombreEleveChain(maclasseCM2);

    printf("--------------------\n");

    // Supprimer la liste chainée (Attention : il faut bien indiquer la variable au début de la fonction pour que le pointeur soit bien redirigé vers NULL)

    maclasseCM2 = suppressionChainTable(maclasseCM2);

    // Afficher notre table
    //afficherChainTable(maclasseCM2);

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

// Maintenant on va ajouter un nouveau élevè dans la table.
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


// On va afficher les valeurs de la tables
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

// Par la suite on va intégrér les méthodes pour contourner les collisions
// Il existe 2 solutions : Adressage ouvert, Chaînages

// Méthode 1 : Adressage ouvert

TabHacOA *initiation()
{
    TabHacOA *tabhacoa = malloc(sizeof(*tabhacoa));

    // On vérifie que l'allocation de la mémoire s'est bien passé
    if (tabhacoa == NULL)
    {
        // On arrête tout
        exit(EXIT_FAILURE);
    }
    
    // Si c'est bien passé, on initie les valeurs pour chaque sous-variables
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        tabhacoa->etats[i] = LIBRE;
    }
    
    return tabhacoa;
}

// Maintenant on va ajouter un nouveau élevè dans la table.
void insertionOA(TabHacOA *tabhacoa, char nvNom[100], int nvAge, int nvNote)
{
    // Ici on va utiliser la fonction de hachage sur le nom
    int index = hachage(nvNom);
    // Ici, on va faire de l'adressage linéaire pour gérer les collisions
    // Linéaire : index = (i+1) % TABLE_SIZE
    int original_index = index;
    int i = 0;
    // Puis, on recherche une case libre
    while (tabhacoa->etats[index] == OCCUPE)
    {
        // On ajoute 1 à notre compteur
        i++;
        index = (original_index + i) % TABLE_SIZE;

        // Si on boucle entièrement, on arrête
        if (index == original_index)
        {
            printf("Erreur : la table est pleine, impossible d'ajouter %s\n", nvNom);
            return;
        }
    }
    
    
    // On copie les valeurs
    strcpy(tabhacoa->table[index].nom, nvNom);
    tabhacoa->table[index].age = nvAge;
    tabhacoa->table[index].moyenne = nvNote;

    // Et on change la case en OCCUPE
    tabhacoa->etats[index] = OCCUPE;

}

void afficherTableOA(TabHacOA *tabhacoa)
{
    printf("Contenu de la table de hachage (adressage ouvert) :\n");

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (tabhacoa->etats[i] == OCCUPE)
        {
            Eleve *eleve = &(tabhacoa->table[i]);
            printf("Index %d : %s, âge : %d, moyenne : %d\n", 
                   i, eleve->nom, eleve->age, eleve->moyenne);
        }
    }
}

// On va aussi créer une fonction pour supprimer un élève de la table
void suppressionOA(TabHacOA *tabhacoa, char supNom[100])
{
    // On vérifie si la table a déjà été crée avant
    if (tabhacoa == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Ici on va utiliser la fonction de hachage sur le nom
    int original_index = hachage(supNom);
    // Ici, on va faire de l'adressage linéaire pour gérer les collisions
    // Linéaire : index = (i+1) % TABLE_SIZE
    int index = original_index;
    int i = 0;

    while (tabhacoa->etats[index] != LIBRE)
    {
        if (tabhacoa->etats[index] == OCCUPE && strcmp(tabhacoa->table[index].nom, supNom) == 0)
        {
            // "Supprimer" l’élève en marquant la case comme supprimée
            tabhacoa->etats[index] = SUPPRIME;
            tabhacoa->table[index].nom[0] = '\0'; // Optionnel : effacer le nom
            printf("L'élève %s a été supprimé.\n", supNom);
            return;
        }

        // Probing linéaire
        i++;
        index = (original_index + i) % TABLE_SIZE;

        if (index == original_index)
        {
            // On a bouclé
            break;
        }
    }

    printf("Erreur : l'élève %s n'existe pas dans la table.\n", supNom);
    
}

// Supprimer la table complete
TabHacOA *suppressionTableOA(TabHacOA *tabhacoa)
{
    // Ici on va d'abord supprimer les éléments un à un avant de supprimer la liste
    // On vérifie si la liste existe déjà
    if (tabhacoa == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va balayer dans tous le tableau et supprimer tous les données
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        tabhacoa->etats[i] = LIBRE;  // On remet à zéro tous les états
        tabhacoa->table[i].nom[0] = '\0';  // Optionnel : efface le nom pour "visuel"
        tabhacoa->table[i].age = 0;
        tabhacoa->table[i].moyenne = 0;    
    }
    
    // Quand on a fini de supprimer tous les éléments de la liste, on peut supprimer la liste
    free(tabhacoa);

    //
    return NULL;

}

// Pour connaitre le nombre d'élèves
void nombreEleveOA(TabHacOA *tabhacoa)
{
    if (tabhacoa == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int compteur = 0;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (tabhacoa->etats[i] == OCCUPE)
        {
            compteur++;
        }
    }

    printf("Il y a %d élève(s) dans la table.\n", compteur);
}

// Méthode 2 : Chaînages

TabHacChain *initialiser()
{
    TabHacChain *tabhachain = malloc(sizeof(*tabhachain));

    // On vérifie que l'allocation de la mémoire s'est bien passé
    if (tabhachain == NULL)
    {
        // On arrête tout
        exit(EXIT_FAILURE);
    }
    
    // Si c'est bien passé, on initie les valeurs pour chaque sous-variables
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        tabhachain->table[i] = NULL;
    }
    
    return tabhachain;
}

// Maintenant on va ajouter un nouveau élevè au début de la liste chaînée dans la table.
void insertionchain(TabHacChain *tabhachain, char nvNom[100], int nvAge, int nvNote)
{
    // Ici on va utiliser la fonction de hachage sur le nom
    int index = hachage(nvNom);
    // On va créer un nouveau élément avec la structure Eleve
    ChainEleve *nouveau = malloc(sizeof(*nouveau));

    // On vérifie que la mémoire a bien été alloué au nouveau élément
    if (nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    // On donne les valeurs aux sous-variables de la variable nouveau
    strcpy(nouveau->nom, nvNom); // Ici on copie le tableau char dans une autre
    nouveau->age = nvAge;
    nouveau->moyenne = nvNote;

    // Puis on sauvegard l'indice dans la table de hachage
    // Attention, ici chaque case est une liste chaînées
    // D'abord, on pointe le suivant du nouveau element vers l'ancien
    nouveau->suivant = tabhachain->table[index];
    
    // Puis on pointe le tableau avec indice vers le nouveau élément pour le mettre
    // en début de la liste
    tabhachain->table[index] = nouveau;
}

// On va afficher les valeurs de la tables et on inclut la liste
void afficherChainTable(TabHacChain *tabhachain) 
{
    printf("Contenu de la table de hachage :\n");

    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        ChainEleve *eleve = tabhachain->table[i];

        if (eleve != NULL) 
        {
            printf("Index %d :", i);

            while (eleve != NULL) 
            {
                printf(" %s (âge : %d, moyenne : %d) ->", eleve->nom, eleve->age, eleve->moyenne); // On inprime
                eleve = eleve->suivant; // puis on passe au suivant
            }
            // À la fin, on imprime "NULL" pour dire qu'on est à la fin de la liste chainée
            printf(" NULL\n");
        }
    }
}


// On va aussi créer une fonction pour supprimer un élève de la table
// Attention, l'élève peut se trouver dans une liste
void suppressionchain(TabHacChain *tabhachain, char supNom[100])
{
    // On vérifie si la table a déjà été crée avant
    if (tabhachain == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Ici on va utiliser la fonction de hachage sur le nom
    int index = hachage(supNom);

    // Création d'une variable aSupprimer
    ChainEleve *aSupprimer = tabhachain->table[index];

    // Attention, on doit vérifier si c'est bien la bonne personne

    // 1e cas : si la personne est en tête de la liste
    if (aSupprimer != NULL && strcmp(aSupprimer->nom, supNom) == 0)
    {
        // On change le pointeur du l'indeice de la table vers le suivant
        tabhachain->table[index] = aSupprimer->suivant;
        // Puis on libère la mémoire reservé pour cet élément qu'on veut supprimer
        free(aSupprimer);
    
    }
    
    // Cas général : l'élève au milieu de la liste
    else
    {
        // On aura besion de l'élément qui le précéde
        ChainEleve *elementprecedent;
        while (aSupprimer != NULL && strcmp(aSupprimer->nom, supNom) != 0)
        {
            elementprecedent = aSupprimer; // On déplace l'élément précédent d'une case
            aSupprimer = aSupprimer->suivant; // On passe à l'élément suivant
        }
        
        // 2e cas : si on boucle la liste mais on trouve pas le nom
        if (aSupprimer == NULL)
        {
            printf("Cet élève n'est pas dans la classe \n");
            return;
        }

        // On change d'abord le pointeur suivant de l'élementprecedent vers l'élément 
        // qui suit celui qu'on veut supprimer
        elementprecedent->suivant = aSupprimer->suivant;
        // Puis on libère la mémoire reservé pour cet élément qu'on veut supprimer
        free(aSupprimer);

        // Imprime un confirmation
        printf("Les données de l'élève %s a été supprimé de la table\n", supNom);
    }
}


// Supprimer la table des liste chaînée complete
TabHacChain *suppressionChainTable(TabHacChain *tabhachain)
{
    // Ici on va d'abord supprimer les éléments un à un avant de supprimer la liste
    // On vérifie si la liste existe déjà
    if (tabhachain == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On va balayer dans tous le tableau et supprimer tous les données
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        ChainEleve *actuel = tabhachain->table[i];
        while (actuel != NULL)
        {
            ChainEleve *aSupprimer = actuel;
            actuel = actuel->suivant;
            // Puis on libère la mémoire reservé pour l'élément actuel
            free(aSupprimer);
        }
        // Et on met le pointeur vers NULL
        tabhachain->table[i] = NULL;
         
    }
    
    // Quand on a fini de supprimer tous les éléments de la liste, on peut supprimer la liste
    free(tabhachain);
    return NULL;

}

// Pour connaitre le nombre d'élèves
void nombreEleveChain(TabHacChain *tabhachain)
{
    if (tabhachain == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int compteur = 0;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
    
        // Attention, il faut boucler sur la liste
        ChainEleve *actuel = tabhachain->table[i];
        while (actuel != NULL)
        {
            compteur++;
            actuel = actuel->suivant;
        }
    }

    printf("Il y a %d élève(s) dans la table.\n", compteur);
}