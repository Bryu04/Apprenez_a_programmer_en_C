#include <stdio.h>   
#include <stdlib.h>

/*
Dans ce petit programme, on va manipuler les chaînes de caractères.
On va voir les 3 façons d'initier une chaine de caractères, qui est un 
tableau de char

*/


int main(int argc, const char * argv[]) {

    // Initialisation du tableau de char
    // Méthode 1 :
    char chaine1[6];  // Ici le tableau va contenir un mot de 5 lettres, 
                      // plus le caractère de fin de chaine
    chaine1[0] = 'h';
    chaine1[1] = 'e';
    chaine1[2] = 'l';
    chaine1[3] = 'l';
    chaine1[4] = 'o';
    chaine1[5] = '\0';  // Cette ligne n'est pas obligatoire car par défaut lors de 
                        // la déclaration de la chaine, tous les cases ont été intialisés
                        // avec le caractère de fin de chaine

    // Afficher le texte
    printf("%s\n", chaine1);

    // Erreur courant : l'oubli du caractère de fin de chaine
    char chaine2[5];

    chaine2[0] = 'e';
    chaine2[1] = 'c';
    chaine2[2] = 'h';
    chaine2[3] = 'o';
    chaine2[4] = '1';

    // Afficher le texte
    printf("%s\n", chaine2);

    // Méthode 2 : comme pour les tableux de int

    char chaine3[6] = {'f','i','r','s','t'};

    // Afficher le texte
    printf("%s\n", chaine3);

    // Méthode 3 : entre guillemets le mot sans spécifier la taille
    char chaine4[] = "calenda";


    // Modifier une case (Attention : c'est possible qu'après l'initialisation)
    chaine4[5] = 'j';

    // Afficher le texte
    printf("%s\n", chaine4);

    return 0;
}