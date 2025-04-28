#include <stdio.h>   
#include <stdlib.h>

// Dans ce petit programme, on va manipuler des tableaux

int main(int argc, const char * argv[]) {
    //Initialisation du tableau

    float tableau[6];

    tableau[0] = 10;
    tableau[1] = 12;
    tableau[2] = 14;

    
    //Afficher les valeurs du tableau
    printf("Case 1 : %f\n", tableau[0]);
    printf("Case 2 : %f\n", tableau[1]);
    printf("Case 3 : %f\n", tableau[2]);


    // Afficher les valeurs du tableau grace aux pointeurs
    // Le tableau est un pointeur

    printf("Case 1 (mode pointeur): %f\n", *tableau);
    printf("Case 2 (mode pointeur): %f\n", *(tableau+1));
    printf("Case 3 (mode pointeur): %f\n", *(tableau+2));

    return 0;
}