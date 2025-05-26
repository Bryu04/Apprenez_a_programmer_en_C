/*

manipule_tableau.h
Ce fichier contient les prototypes utilisés dans le programme principale manipule_tableau.c

*/

void affichertableau(int *tableau, int taille);
void inversertableau(int *tableau, int taille);
int recherchevaleur(int *tableau, int taille, int valeur);
void triParSelection(int *tableau, int taille);
int recherchedichotomique(int *tableau, int taille, int valeur);
int sommeTableau(int *tableau, int taille);
void copiertableau(int *actueltableau, int *nouveautableau, int taille);
void allocationdynamiquetableau(int **nouveautableau, int taille);