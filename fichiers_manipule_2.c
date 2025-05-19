/*
  
Le fichier fichiers_manipule_2.c est un petit programme qui va renommer et supprimer des fichiers grace aux fonctions.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // Utilisation de la fonction rename
    // La fonction rename permet de renommer un fichier.

    // Ouverture du fichier test_read.txt
    FILE *monfichier = NULL;
    monfichier = fopen("test_read.txt", "r");

    printf("------------- Renommer un fichier ---------------\n");
    if (monfichier != NULL)
    {
        // D'abord on ferme le fichier
        fclose(monfichier);
        // Puis on peut renommer le fichier
        if (rename("test_read.txt", "test_renamed.txt")== 0)
        {
            printf("Le fichier a été modifié avec succes \n");
        }
        else
        {
            printf("Erreur sur la modification du nom du fichier\n");
        }
         
    }
    else
    {
        printf("Le fichier n'existe pas \n");
    }
    printf("-------------------------------------------------\n");
    
    // Utilisation de la fonction remove
    // La fonction remove permet de supprimer DEFINITIVEMENT un fichier.
    // On va supprimer le fichier test_renamed.txt
    monfichier = NULL;
    monfichier = fopen("test_renamed.txt", "r");

    printf("------------- Supprimer un fichier ---------------\n");
    if (monfichier != NULL)
    {
        // D'abord on ferme le fichier
        fclose(monfichier);
        // Puis on peut supprimer le fichier
        if (remove("test_renamed.txt")== 0)
        {
            printf("Le fichier a été supprimé avec succes \n");
        }
        else
        {
            printf("Erreur sur la suppression du nom du fichier\n");
        }
         
    }
    else
    {
        printf("Le fichier n'existe pas \n");
    }

    printf("--------------------------------------------------\n");

    return 0;
}