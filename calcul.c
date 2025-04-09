#include <stdio.h>   
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // L'addition de 2 nombres
    // On initie les 2 nombres et le resultat
    int nombre1 = 0;
    int nombre2 = 0;
    int resultat = 0;

    // On demande à l'utilisateur de rentrer 2 nombres
    printf("Entrez le premier nombre : ");
    scanf("%d",&nombre1);
    printf("Entrez le seconde nombre : ");
    scanf("%d",&nombre2);

    // On fait la somme
    resultat = nombre1 + nombre2;
    // On affiche le résultat
    printf("Le resultat de la somme entre les nombres %d et %d est %d\n",nombre1,nombre2,resultat);

    // On fait de même avec les opérations substraction,
    // multiplication, modulo et division

    // On fait la soustraction
    resultat = nombre1 - nombre2;
    // On affiche le résultat
    printf("Le resultat de la soustraction entre les nombres %d et %d est %d\n",nombre1,nombre2,resultat);

    // On fait la multiplication
    resultat = nombre1 * nombre2;
    // On affiche le résultat
    printf("Le resultat de la mutiplication entre les nombres %d et %d est %d\n",nombre1,nombre2,resultat);

    // On fait le modulo
    resultat = nombre1 % nombre2;
    // On affiche le résultat
    printf("Le resultat du modulo entre les nombres %d et %d est %d\n",nombre1,nombre2,resultat);

    // On fait la division
    float resultat2 = 0;  // On initie une variable pour la division
    float nombre3 = 0; // On fait de même pour un nombre decimale
    float nombre4 = 0;
    nombre3 = nombre1;
    nombre4 = nombre2;
    resultat2 = nombre3 / nombre4;
    // On affiche le résultat
    printf("Le resultat de la division entre les nombres %d et %d est %f\n",nombre1,nombre2,resultat2);

    return 0;
}