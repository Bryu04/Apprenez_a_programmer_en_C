/*
  
main.c
header

*/

#include <stdio.h>
#include "aire.h"  // On include seulement le fichier aire.h

// Pour visual studio, il faut include aussi le fichier .c
#include "aire.c"  

int main(int argc, const char * argv[]) {
    double result;
    result = aireRectangle(15.0, 20.0);

    // Afficher le resultat
    printf("L'aire du rectangle vaut %f\n", result);
    return 0;
}