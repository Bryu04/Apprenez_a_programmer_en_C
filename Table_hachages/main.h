/*

main.h
Dans ce fichier, on va créer une table de hachage à partir des structures qui seront utilisées dans le programme main.c

*/

// Création d'une structure pour créer une tableau qui contient des infos sur des 
// éleves (nom, age et leur moyenne générale)
// Ici chaque élément de ce tableau aura cette structure générique

typedef struct Eleve Eleve;
struct Eleve
{
    char nom[100]; // Le nom complet
    int age;  // Une donnée; ici leur age
    int moyenne; // Leur moyenne générale
    
};

// Constant pour le tableau
#define TABLE_SIZE 100

// Et on créer une structure pour la tableau de hachage
typedef struct TableHachage TableHachage;
struct TableHachage
{
    Eleve *table[TABLE_SIZE];
};



// Prototypes des fonctions qui va manipuler notre liste chainées
TableHachage *initialisation();
void insertion(TableHachage *tablehachage, char nvNom[100], int nvAge, int nvNote);
void afficherTable(TableHachage *tablehachage);
void suppression(TableHachage *tablehachage, char supNom[100]);
TableHachage *suppressionTable(TableHachage *tablehachage);
void nombreEleve(TableHachage *tablehachage);
int hachage(char *chaine);