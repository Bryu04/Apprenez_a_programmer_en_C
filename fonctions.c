#include <stdio.h>   
#include <stdlib.h>


// Definition de la fonction triple
int triple (int nombre)
{
    int resultat = 3 * nombre;
    return resultat;
}

int main(int argc, const char * argv[]) {
    // Initialisation des variables pour la fonction
    int nombreEntier = 0, nombreTriple = 0;

    // On demande à l'utilisateur d'entrer un nombre
    printf("Entrez un nombre : ");
    scanf("%d", &nombreEntier);

    // Appeler la fonction triple
    nombreTriple = triple(nombreEntier);

    // Afficher le resultat
    printf("Le triple du nombre %d est %d\n", nombreEntier, nombreTriple);
    return 0;
}