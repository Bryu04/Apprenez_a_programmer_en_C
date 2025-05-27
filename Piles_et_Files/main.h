/*

main.h
Dans ce fichier, on va stocker des données grâce à la création des piles et files à partir des structures qui seront utilisées dans le programme main.c
*/

// Création d'une structure d'éléments qui va contenir les données
// Ici chaque élément de cette liste aura cette structure générique
typedef struct Element Element;
struct Element
{
    int nombre;  // Une donnée; ici une nombre
    Element *suivant;  // Un pointeur qui pointe sur le prochain élément (de même type) de la 
                       // liste
};

// Et il nous faut la structure de controle (ici ce sera la pile)

typedef struct Pile Pile;
struct Pile
{
    Element *premier; // Un pointeur qui pointe sur le premier élément de la Pile
};

// On fait une autre structure de controle (qui sera la file)
typedef struct File File;
struct File
{
    Element *premier; // Un pointeur qui pointe sur le premier élément de la File
};


// Prototypes des fonctions qui va manipuler les empilement et déempilement pour la Pile
Pile *initialiser();
void empiler(Pile *pile, int nvNombre);
int depiler(Pile *pile);
void afficherPile(Pile *pile);

// Prototypes des fonctions qui va manipuler les enfilage et défilage pour la File
File *initialisation();
void enfiler(File *file, int nvNombre);
int defiler(File *file);
void afficherFile(File *file);