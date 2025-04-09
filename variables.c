#include <stdio.h>   
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int nombre_de_vies;
    nombre_de_vies = 5;
    printf("Nombre : %d\n",nombre_de_vies);
    nombre_de_vies = 4;
    printf("Je suis touchE. Nombre restant : %d\n",nombre_de_vies);
    const int Attack = 10;
    printf("Point d'attaque : %d\n",Attack);
    // J'essaie augmenter mes point d'attaque de base
    //Attack = 20;
    //printf("Point d'attaque augmentE : %d\n",Attack);
    //ça ne marche pas parce que la variable Attack est une 
    //constante
    return 0;
}