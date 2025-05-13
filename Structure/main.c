/*
  
main.c

*/

#include <stdio.h>
#include "main.h"

int main(int argc, const char * argv[]) {
    // Maintenant on utilise la structure crée pour déclarer une nouvelle variale

    Coordonnees point;
    // On initialise la variable point
    initialiserCoordonnees(&point);
    // Modifier les compostante de la structure point
    point.x = 10;
    point.y = 15;

    //Aficher la valeur de la variable point
    printf("Les coordonnees de point sont : (%d,%d)\n", point.x, point.y);

    // On crée une nouvelle variable de type personne
    Personne utilisateur;
    // On initialise la variable utilisateur
    initialiserPersonne(&utilisateur);
    // Modifier les compostante de la structure "utilisateur"
    printf("Quel est votre nom ? : ");
    scanf("%s", utilisateur.nom);
    printf("Quel est votre prenom ? : ");
    scanf("%s", utilisateur.prenom);
    printf("Quel est votre age ? : ");
    scanf("%d", &utilisateur.age);

    printf("Tres bien, vous vous appelez %s %s\n", utilisateur.prenom, utilisateur.nom);
    printf("Et vous avez %d ans. \n", utilisateur.age);

    return 0;
}

void initialiserCoordonnees(Coordonnees *point)
{
    (*point).x = 0;
    (*point).y = 0;
}

void initialiserPersonne(Personne *utilisateur)
{
    (*utilisateur).age = 0;
    (*utilisateur).etudiant = false;
}
