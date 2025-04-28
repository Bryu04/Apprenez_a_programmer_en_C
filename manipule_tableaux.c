#include <stdio.h>   
#include <stdlib.h>

// Dans ce petit programme, on va manipuler encore plus des tableaux


//Prototype des fonctions 

void nombresPaires(int tab[], int taille);

int sommeTableau(int tableau[], int tailleTableau);

double moyenneTableau(int tableau[], int tailleTableau);

int main(int argc, const char * argv[]) {

    // Initialisation du table
    int tab[4] = {12, 45, 30, 23};
    
    // Afficher nombre pairs
    nombresPaires(tab, 4);

    // Afficher la somme des nombres du tableau
    printf("La somme de toutes les valeurs du tableau est %d\n", sommeTableau(tab, 4));

    // Afficher la moyenne des nombres du tableau
    printf("La moyenne des nombres du tableau est %f\n", moyenneTableau(tab, 4));
    return 0;
}

void nombresPaires(int tab[], int taille)
{
    for (int i=0; i < taille; i++)
    {
        if (tab[i] %2 == 0)
        {
            printf("Le nombre %d est pair\n", tab[i]);
        }
    }
}


int sommeTableau(int tableau[], int tailleTableau)
{
    int result = 0;
    for (int i=0; i < tailleTableau; i++)
    {
        result += tableau[i];
    }

    return result;
}

double moyenneTableau(int tableau[], int tailleTableau)
{
    int somme = 0;
    for (int i=0; i < tailleTableau; i++)
    {
        somme +=tableau[i];
    }

    return (double)somme/(double)tailleTableau;
}