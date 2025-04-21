#include <stdio.h>   
#include <stdlib.h>

int main(int argc, const char * argv[]) {

    // On créer une variable
    int age = 20;

    // Afficher la valeur de la variable
    printf("La valeur de la variable age est %d\n", age);

    // Afiicher l'adresse de la variable
    printf("L'adrese de la variable age est %p\n", &age);

    // Création du pointeur
    int *monpointeur = NULL;
    monpointeur = &age;

    // Afficher la valeur du pointeur
    printf("La valeur de mon pointeur est %p\n", monpointeur);

    //Aficher l'adresse du pointeur
    printf("L'adresse de mon pointeur est %p\n", &monpointeur);

    //Afficher la valeur contenu dans le pointeur
    printf("La valeur contenue dans mon pointeur est %d\n", *monpointeur);
}