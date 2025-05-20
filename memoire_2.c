/*

memoire_2.c
Dans ce petit programme, on va decouvrir davantage comment le programme C alloue dynamiquement de la mémoire
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // L'age de mes amis
    int nombreAmis = 0, i = 0;
    // Création d'un pointeur pour l'age des amis qui sera servi pour créer un tableau
    int *ageAmis = NULL;

    printf("Combien d'amis avez-vous ? : ");
    scanf("%d", &nombreAmis);

    if (nombreAmis > 0)
    {
        ageAmis = malloc(nombreAmis * sizeof(int));
        if (ageAmis == NULL)
        {
            printf("L'allocation de la memoire ne s'est pas fait \n");
            exit(0);
        }
        else
        {
            // On veut connaitre l'age de tes amis
            for (i = 0; i < nombreAmis; i++)
            {
                printf("Quel est l'age de ton ami numero %d ? ", i+1);
                scanf("%d", &ageAmis[i]);
            }
            
            // On affiche l'age de tes amis un à un
            if (nombreAmis == 1)
            {
                printf("Votre ami a l'age suivant : \n");
            }
            else
            {
                printf("Vos amis ont les ages suivants : \n");
            }
            
            for (i = 0; i < nombreAmis; i++)
            {
                printf("%d ans \n", ageAmis[i]);
            }
            
            // On libere l'espace de la mémoire quand on a fini
            free(ageAmis);
        }
    }
    else
    {
        printf("Je suis desole :( \n");
        printf("Mais courage !! Continuer de perseverer !! \n");
    }
    
    return 0;
}