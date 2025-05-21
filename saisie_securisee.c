/*

saisie_securisee.c
Dans ce programme, on va regarder les limite de scanf et crée un propre fonction de saisie plus sécurisante
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Création d'une fonction qui va vider le "buffer", endroit où la saisie du clavier est 
// stocké temporairemment avant d'être récupérer par scanf, fgets, getchar (ou d'autres 
// fonctions)
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
    
}

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
        else
        {
            viderBuffer();   // On vide la mémoire stdin ou buffer
        }
        return 1; // On retourne 1 si pas d'erreur
    }
    else
    {
        viderBuffer();   // On vide la mémoire stdin ou buffer
        return 0; // On retourne 0 s'il y a une erreur
    }
}


// Création d'une fonction qui lui va récupérer la sortie de la fonction lecture pour récupérer des nombres
long lecturelong()
{
    char nombreTexte[100] = {0};

    if (lecture(nombreTexte, 100))
    {
        // Si la lecture du texte est ok, convertir le nombre en long et le retourner
        return strtol(nombreTexte, NULL, 10);
    }
    else
    {
        return 0; // Si erreur, on retourne la valeur 0
    }
    
}

int main(int argc, const char * argv[]) {
    // Ici on va demande à l'utilisateur de rentrer son nom

    char nom[10];
    printf("Quel est votre nom ? : ");
    lecture(nom, 10);
    printf("Ah vous vous appelez %s !!\n", nom);
    printf("-------------------------------------\n");

    // Récupérer des nombres de manière sécurisé
    long age = 0;
    printf("Quel est votre age ? : ");
    age = lecturelong();
    printf("Ah vous avez donc %ld ans !! \n", age);
    printf("-------------------------------------\n");

    return 0;
}