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

int main(int argc, const char * argv[]) {

    int aire = AIRE; 
    // Ici la valeur AIRE sera remplacé par LARGEUR et LONGEUR qui sera à leurs tours remplacés par leurs valeur correspondants AVANT la compilation

    printf("L'aire de l'objet vaut : %d\n", aire);

    // Initialisation d'un tableau
    int tab[TAILLE_MAX] = {1,2,3,4,5};

    printf("La premier valeur du tableau est : %d\n", tab[0]);
    return 0;
}