#include <stdio.h>

/*
Dans ce petit programme, on va utiliser les directives des préprocesseur. En général, on met
les directives dans un fichier .h.
*/


// La directive #define va permettre de définir une constante de préprocessor (associé une 
// valeur à un mot)
// L'avantage est que cette valeur ne sera pas sauvegarder à la mémoire mais elle sera 
// remplacé avant la compilation du code.
// On peut aussi l'utiliser pour faire des calculs simple

#define LARGEUR 5
#define LONGEUR 7
#define AIRE (LARGEUR*LONGEUR)

// On peut l'utiliser pour initialiser un tableau, contrairement aux variables int
#define TAILLE_MAX 1000

// #define peut aussi remplacer un mot par un bout de code, on dit qu'on fait une MACRO
#define COUCOU() printf("Coucou tout le monde \n");
#define MAVIE() printf("Bonjour, je m'appelle Angela \n"); \
                printf("Bienvenue dans mon émission \n"); \
                printf("Je vais vous présenter tous mes amis \n"); \
                printf("NON pas Sarah Connor !! \n");

// Un macro peut aussi prendre des paramètres en entrée comme une fonction
#define MAJEUR(age, nom) if (age >= 18) \
                         printf("Vous êtes majeur %s\n", nom); \
                         else \
                         printf("Vous êtes encore mineur %s\n", nom);

int main(int argc, const char * argv[]) {

    int aire = AIRE; 
    // Ici la valeur AIRE sera remplacé par LARGEUR et LONGEUR qui sera à leurs tours remplacés par leurs valeur correspondants AVANT la compilation

    printf("L'aire de l'objet vaut : %d\n", aire);

    // Initialisation d'un tableau
    int tab[TAILLE_MAX] = {1,2,3,4,5};

    printf("La premier valeur du tableau est : %d\n", tab[0]);

    // Exécuter le bout de code COUCOU
    COUCOU()
    
    printf("--- Parler de sa vie ----\n");
    MAVIE()
    printf("-------------------------\n");

    // ACCES Reservé au majeur
    printf("--- Demande de l'age ---\n");
    MAJEUR(22, "Jack")
    MAJEUR(15, "Daniel")
    printf("-------------------------\n");

    return 0;
}