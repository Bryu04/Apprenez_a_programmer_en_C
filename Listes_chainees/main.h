/*

main.h
Dans ce fichier, on va créer des listes chaînées à partir des structures qui seront utilisées dans le programme main.c
*/

// Création d'une structure pour créer une liste chainées de nombres entiers
// Ici chaque élément de cette liste aura cette structure générique
typedef struct Element Element;
struct Element
{
    int nombre;  // Une donnée; ici une nombre
    Element *suivant;  // Un pointeur qui pointe sur le prochain élément (de même type) de la 
                       // liste
};

// Il nous faut aussi une structure de controle de la liste chainée
typedef struct Liste Liste;
struct Liste
{
    Element *premier; // Un pointeur qui pointe sur le premier élément de la liste chainée
    int nbElements;  // Le nombre d'éléments présent dans la liste
};


// Prototypes des fonctions qui va manipuler notre liste chainées
Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
void rechercheIndice(Liste *liste, int nombre);
void insertionMilieu(Liste *liste, int nvNombre, int position);
void suppressionMilieu(Liste *liste, int position);
Liste *suppressionListe(Liste *liste);
void tailleListe(Liste *liste);
