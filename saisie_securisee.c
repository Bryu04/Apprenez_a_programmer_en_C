/*

saisie_securisee.c
Dans ce programme, on va regarder les limite de scanf et crée un propre fonction de saisie plus sécurisante
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Création d'une fonction qui va lire la saisie de l'utilisateur

int lecture(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    // On lit le texte saisi au clavier
    if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie
    {
        positionEntree = strchr(chaine, '\n'); // On cherche l'Entrée
        if (positionEntree != NULL) // On a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace le caractère par \0
        }
        return 1; // On retourne 1 si pas d'erreur
    }
    else
    {
        return 0; // On retourne 0 s'il y a une erreur
    }
}


int main(int argc, const char * argv[]) {
    // Ici on va demande à l'utilisateur de rentrer son nom

    char nom[10];
    printf("Quel est votre nom ? : ");
    lecture(nom, 10);
    printf("Ah vous vous appelez %s !!\n", nom);

    return 0;
}