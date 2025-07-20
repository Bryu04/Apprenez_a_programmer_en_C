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



// Prototypes des fonctions qui va manipuler notre table de hachage
TableHachage *initialisation();
void insertion(TableHachage *tablehachage, char nvNom[100], int nvAge, int nvNote);
void afficherTable(TableHachage *tablehachage);
void suppression(TableHachage *tablehachage, char supNom[100]);
TableHachage *suppressionTable(TableHachage *tablehachage);
void nombreEleve(TableHachage *tablehachage);
int hachage(char *chaine);

/////////////////////// GESTION DES COLLISIONS //////////////////////

// Méthode 1 : Adressage ouvert

typedef enum { LIBRE, OCCUPE, SUPPRIME} EtatCase;

typedef struct TableHachage_OpenAddressing TabHacOA;
struct TableHachage_OpenAddressing
{
    Eleve table[TABLE_SIZE];
    EtatCase etats[TABLE_SIZE];
};

// Prototypes des fonctions pour l'adressage ouvert
TabHacOA *initiation();
void insertionOA(TabHacOA *tabhacoa, char nvNom[100], int nvAge, int nvNote);
void afficherTableOA(TabHacOA *tabhacoa);
void suppressionOA(TabHacOA *tabhacoa, char supNom[100]);
TabHacOA *suppressionTableOA(TabHacOA *tabhacoa);
void nombreEleveOA(TabHacOA *tabhacoa);


// Méthode 2 : Chaînage

typedef struct Eleve_Chain ChainEleve;
struct Eleve_Chain
{
    char nom[100]; // Le nom complet
    int age;  // Une donnée; ici leur age
    int moyenne; // Leur moyenne générale
    ChainEleve *suivant; // Un pointeur qui pointe sur le prochain élément (de même 
                         // type) de la liste
    
};

typedef struct TableHachage_Chainage TabHacChain;
struct TableHachage_Chainage
{
    ChainEleve *table[TABLE_SIZE];
};

// Prototypes des fonctions pour les chaînages
TabHacChain *initialiser();
void insertionchain(TabHacChain *tabhachain, char nvNom[100], int nvAge, int nvNote);
void afficherChainTable(TabHacChain *tabhachain);
void suppressionchain(TabHacChain *tabhachain, char supNom[100]);
TabHacChain *suppressionChainTable(TabHacChain *tabhachain);
void nombreEleveChain(TabHacChain *tabhachain);
