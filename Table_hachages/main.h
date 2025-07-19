/*

main.h
Dans ce fichier, on va créer des listes chaînées à partir des structures qui seront utilisées dans le programme main.c
Puis on va utiliser une table de hachage pour permettre de parcourir les éléments de la liste plus vite.
*/

// Création d'une structure pour créer une liste chainée qui contient des infos sur des 
// éleves (nom, age et leur moyenne générale)
// Ici chaque élément de cette liste aura cette structure générique

typedef struct Eleve Eleve;
struct Eleve
{
    char nom[100]; // Le nom complet
    int age;  // Une donnée; ici leur age
    int moyenne; // Leur moyenne générale
    Eleve *suivant;  // Un pointeur qui pointe sur le prochain éleve (de même type) de 
                     // la liste
};


// Il nous faut aussi une structure de controle de la liste chainée
typedef struct Liste Liste;
struct Liste
{
    Eleve *premier; // Un pointeur qui pointe sur le premier éleve de la liste chainée
    int nbEleve;  // Le nombre d'éleves présent dans la liste
};


// Prototypes des fonctions qui va manipuler notre liste chainées
Liste *initialisation();
void insertion(Liste *liste, char nvNom[100], int nvAge, int nvNote);
void insertionMilieu(Liste *liste, char nvNom[100], int nvAge, int nvNote, int position);
void afficherListe(Liste *liste);
void suppression(Liste *liste);
void suppressionMilieu(Liste *liste, int position);
Liste *suppressionListe(Liste *liste);
void tailleListe(Liste *liste);