/*

manipule_tableau.c
Dans ce programme, on va manipuler les tableaux en utilisant les pointeurs

*/

#include <stdio.h>   
#include <stdlib.h>

#include "manipule_tableau.h" // Importation des prototypes

int main(int argc, const char * argv[]) {

    // On part d'un tableau avec quelques valeurs (5 entiers par exemple)
    int tab[5]  = {10, 5 ,6 ,4 ,15};

    // Afficher les valeurs du tableau
    printf("--------------------- Afficher les valeurs du tableau -----------------\n");
    affichertableau(tab, 5);
    printf("-----------------------------------------------------------------------\n");

    printf("------------------------ Inversion du tableau -------------------------\n");
    inversertableau(tab, 5);
    affichertableau(tab, 5);
    printf("-----------------------------------------------------------------------\n");
    printf("-------------- Recherche une valeur dans le tableau -------------------\n");
    recherchevaleur(tab, 5, 6);
    recherchevaleur(tab, 5, 25);
    printf("-----------------------------------------------------------------------\n");
    printf("-------------- Trier le tableau par ordre croissant -------------------\n");
    triParSelection(tab, 5);
    affichertableau(tab, 5);
    printf("-----------------------------------------------------------------------\n");
    printf("-------------- Recherche une valeur dans le tableau trié --------------\n");
    recherchedichotomique(tab, 5, 15);
    recherchedichotomique(tab, 5, 25);
    printf("-----------------------------------------------------------------------\n");
    printf("--------------------- Somme des valeurs du tableau --------------------\n");
    printf("La somme de toutes les valeurs du tableau est %d\n", sommeTableau(tab, 5));
    printf("-----------------------------------------------------------------------\n");

    // On crée un nouveau tableau vers où on copie les éléments du premier tableau
    int copytab[10] = {0};
    printf("------------ Copier un tableau dans un autre tableau ------------------\n");
    copiertableau(tab, copytab, 5);
    affichertableau(copytab, 5);
    printf("-----------------------------------------------------------------------\n");
    printf("--------- Allocation dynamique de la mémoire pour un tableau ----------\n");
    int *montableau = NULL;
    allocationdynamiquetableau(&montableau, 5);
    printf("-----------------------------------------------------------------------\n");

    return 0;
    
}


// Afficher les valeurs d'un tableau en utilisant des pointeurs
void affichertableau(int *tableau, int taille)
{
    printf("Les valeurs de ce tableau sont : \n");
    for (int i=0; i < taille; i++)
    {
        if (i == taille-1)
        {
            printf("%d", *(tableau+i));
        }
        else
        {
            printf("%d, ", *(tableau+i));
        }
        
    }
    printf("\n");
}


// Inverser les valeurs du tableau
void inversertableau(int *tableau, int taille)
{
    // On fait un boucle jusqu'à la moitié du tableau
    for (int i = 0; i < taille /2; i++)
    {
        // On crée un pointeur qui pointe vers le début du tableau
        int *debut = tableau+i;
        // On fait de même pour la fin du tableau
        int *fin = tableau + (taille -1 -i);
    
        // On échange les places des pointeur 
        int temp = *debut;
        *debut = *fin;
        *fin = temp;
    }
    
}

// Recherche la position du élément dans le tableau
int recherchevaleur(int *tableau, int taille, int valeur)
{
    for (int i = 0; i < taille; i++)
    {
        if (*(tableau+i) == valeur)
        {
            printf("La valeur %d se trouve à la position %d du tableau\n", valeur, i+1);
            return i;
        }
        
    }

    // Si la valeur n'est pas dans le tableau
    printf("Le nombre %d n'est pas dans le tableau\n", valeur);
    return -1;
    
}

// Trier le tableau par ordre croissant
void triParSelection(int *tableau, int taille)
{
    // On va faire un boucle dans un 2e boucle
    // On va récupérer les petits valeurs et les mettre en premiers places dans le tableau
    for (int i = 0; i < taille - 1; i++)
    {
        int indexMin = i;

        for (int j = i + 1; j < taille; j++)
        {
            if (tableau[j] < tableau[indexMin])
            {
                indexMin = j;
            }
        }

        // Échange si un plus petit élément a été trouvé
        if (indexMin != i)
        {
            int temp = tableau[i];
            tableau[i] = tableau[indexMin];
            tableau[indexMin] = temp;
        }
    }
}

// Recherche la position du élément dans le tableau trié 
// Cette fois-ci on va partir du milieu et parcourir à gauche ou à droite pour trouver la 
// valeur recherchée.

int recherchedichotomique(int tableau[], int taille, int valeur)
{
    int debut = 0;
    int fin = taille - 1;

    while (debut <= fin) {
        int milieu = (debut + fin) / 2;

        if (tableau[milieu] == valeur) 
        {
            printf("Le nombre %d se trouve à la position %d\n", valeur, milieu+1);
            return milieu;
        }
        else if (tableau[milieu] < valeur)
        { 
            debut = milieu + 1;
        }
        else
        { 
            fin = milieu - 1;
        }
    }

    // Si la valeur n'est pas dans le tableau
    printf("Le nombre %d n'est pas dans le tableau\n", valeur);
    return -1;

}

// Somme de tous les valeurs du tableau
int sommeTableau(int *tableau, int taille)
{
    int result = 0;
    for (int i = 0; i < taille; i++)
    {
        result += *(tableau+i);
    }

    return result;    
}

// Copier un tableau dans un autre tableau
void copiertableau(int *actueltableau, int *nouveautableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        *(nouveautableau+i) = *(actueltableau+i);
    }
}


// Allocation dynamique d'un tableau
void allocationdynamiquetableau(int **nouveautableau, int taille)
{
    // On alloue de la mémoire pour le tableau
    printf("Création d'un tableau\n");
    *nouveautableau = malloc(taille * sizeof(int));

    // On vérifie si l'allocation s'est bien passé
    if (*nouveautableau == NULL)
    {
        printf("Erreur d'allocation mémoire.\n");
        return;
    }
    
    // On intie le nouveau tableau avec des valeurs
    printf("Initialisation des valeurs du tableau\n");
    for (int i = 0; i < taille; i++)
    {
        *(*nouveautableau+i) = i+1;
    }
    
    // Afficher le tableau
    printf("Afficher les valeurs du tableau\n");
    affichertableau(*nouveautableau, taille);

    // Libérer la mémoire
    printf("Libération de la mémoire \n");
    free(*nouveautableau);

    // Puis, on pointe le pointeur vers NULL
    *nouveautableau = NULL;
    
}
