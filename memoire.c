/*

memoire.c
Dans ce petit programme, on va decouvrir comment le programme C alloue automatiquement de la mémoire et on le fera manuellement.
*/

#include <stdio.h>
#include <stdlib.h>

// Création d'une structure pour se déplacer en 2D

typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
    int x; // Coordonnée Abscisses
    int y; // Coordonnée Ordonnées
};


int main(int argc, const char * argv[]) {
    // Taille par défaut les types de variables
    printf("Allocation automatique des variables par defaut\n");
    printf("char : %d octects\n",sizeof(char));
    printf("int : %d octects\n",sizeof(int));
    printf("long : %d octects\n",sizeof(long));
    printf("float : %d octects\n",sizeof(float));
    printf("double : %d octects\n",sizeof(double));
    
    // On peut même vérifier la taille alloué d'une structure
    printf("Coordonnees : %d octects\n",sizeof(Coordonnees));

    printf("-----------------------------------------------\n");

    // La prochaine étape d'allouer manuellement la mémoire
    // Pour cela on va utiliser les fonctions; malloc et free.

    printf("------- Allocation manuel de la memoire --------\n");
    int *memoireAlloue = NULL;
    memoireAlloue = malloc(sizeof(int)); // On va lui attribuer la même taille de mémoire qu'un int
    // Maintenant, comme pour les fichiers, on va vérifier si l'allocation a bien été fait
    if (memoireAlloue == NULL)
    {
        printf("L'allocation de la memoire n'a pas ete un succes\n");
        // On arrete le programme
        exit(0);
    }
    else
    {
        printf("L'allocation de la memoire a ete fait\n");
        printf("Quel est votre age ? : ");
        scanf("%d", memoireAlloue);
        printf("Vous avez %d ans \n", *memoireAlloue);

        // Libération de la mémoire
        printf("Liberation de la memoire\n");
        free(memoireAlloue);
    }
    
    printf("-----------------------------------------------\n");
    return 0;
}