#include <stdio.h>   
#include <stdlib.h>

/*
Dans ce petit programme, on va manipuler davantage les chaînes de caractères.

*/


int main(int argc, const char * argv[]) {

    // Initialisation du tableau de char
    char prenom[100];
    printf("Comment t'appelles-tu ? :");
    scanf("%s", prenom); // On sauvegarde l'entrée de l'utisateur dans la variable

    printf("Bonjour %s, ravi de te rencontrer !!", prenom);

    return 0;
}
