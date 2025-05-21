/*

main.c
Ce programme contient la fonction principale du jeu du pendu
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Pour l'alétoire
#include "main.h"  // Inclure les prototypes des fonctions

// FONCTION PRINCIPALE
int main(int argc, char* argv[])
{
    // La liste des mots où le programme va piocher aléatoirement
    const char *liste[] = {"CHAT", "CHIEN", "MAISON", "VOITURE", "ORDINATEUR"};
    int taille = sizeof(liste) / sizeof(liste[0]);
     
    // Initialisation de la graine pour rand()
    srand(time(NULL));

    // Choix aléatoire
    int indice = rand() % taille;

    char lettre = 0; // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char motSecret[50]; // C'est le mot à trouver
    
    // On copie le mot choisi aléatoirement dans le mot secret
    strcpy(motSecret, liste[indice]);
    int coupsRestants = 10; // Compteur de coups restants (0 = mort)


    printf("Bienvenue dans le Pendu !\n");
    
    // Enregistrer la taille du mot dans une variable 
    int nombreLettres = tailleMot(motSecret);
    // Initialiser un pointeur
    int *lettreTrouvee = NULL;
    lettreTrouvee = malloc(nombreLettres * sizeof(int)); // allocation de la mémoire
    // Initialisation du tableau lettreTrouvee
    initTableau(lettreTrouvee, nombreLettres);

    // Boucles principale
    while (coupsRestants > 0 && !gagne(lettreTrouvee, nombreLettres))
    {
        printf("Il vous reste %d coups a jouer \n", coupsRestants);
        printf("Quel est le mot secret ? ");
        // Ici on va afficher seulement les lettres trouvées
        for (int i = 0 ; i < nombreLettres ; i++)
        {
            if (lettreTrouvee[i])
            {
                printf("%c", motSecret[i]);
            }
            else
            {
                printf("*");
            }   
        }
        printf("\n"); // Un retour à la ligne

        // Demander à l'utilisateur de saisie une lettre
        printf("Proposez une lettre : ");
        lettre = lireCaractere();

        // On vérifie si la lettre se trouve dans le mot secret
        // Si ce n'était PAS la bonne lettre
        if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
        {
            coupsRestants--; // On enlève un coup au joueur
        }

    }

    // Quand on quitte la boucle principale, on vérifie si le joueur a gagné ou pas
    if (gagne(lettreTrouvee, nombreLettres))
    {
        printf("Gagne ! Le mot secret etait bien : %s \n", motSecret);
    }
    else
    {
        printf("Perdu ! Le mot secret etait : %s \n", motSecret);
    }
    
    // Libération de la mémoire
    free(lettreTrouvee);
    return 0;
}



// Fonctions qui sera utilisé par la fonction principale
int tailleMot(char motSecret[])
{
    int nombreLettres = 0;
    for(int i = 0; motSecret[i] != '\0'; i++)
    {
        nombreLettres++;
    }
    return nombreLettres;
}

// Initialisation du tableau de booléen
void initTableau(int* lettreTrouvee, int taille)
{
    for(int i = 0; i < taille; i++)
    {
        lettreTrouvee[i] = 0;
    }
}


// Fonction gagné ou pas
int gagne(int *lettreTrouvee, int nombreLettres)
{
    int i = 0;
    int joueurGagne = 1;
 
    for (i = 0 ; i < nombreLettres ; i++)
    {
        if (lettreTrouvee[i] == 0)
        {
            joueurGagne = 0;
        }
    }
 
    return joueurGagne;
}


// Fonction pour lire le caractère entrée
char lireCaractere()
{
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu
}


// Fonction pour rechercher le caractère dans le mot secret
int rechercheLettre(char lettre, char motSecret[], int* lettreTrouvee)
{
    int i = 0, bonneLettre = 0;
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }
    return bonneLettre;
}
