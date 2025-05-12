#include <stdio.h>   
#include <stdlib.h>
#include <string.h>

/*
Dans ce petit programme, on va manipuler davantage les chaînes de caractères
grâce à l'aide des fonctions.
*/

int main(int argc, const char * argv[]) {
    //Initialisation du tableau de char
    char chaine1[] = "Bonjour";

    // UTILISATION DE LA FONCTION strlen
    printf("--- Utilisation de la fonction : strlen -----\n");
    // La fonction strlen permet de calculer la longueur de la chaine
    int longueurchaine = 0;

    // On récupère la longueur de la chaine
    longueurchaine = strlen(chaine1);

    // On affiche le resultat
    printf("Le mot %s contient %d lettres\n", chaine1, longueurchaine);

    printf("--------------------------------------------\n");

    // UTILISATION DE LA FONCTION strcpy
    printf("--- Utilisation de la fonction : strcpy -----\n");
    // La fonction strcpy permet de copier le contenu d'une chaine vers une autre.
    // Par contre, il faut faire attention à la taille de la chaine où on va copier,
    // qu'il soit au moins supérieur à la taille de la chaine à copier.

    //Initialisation du tableau de char où on va copier
    char copy[100] = {0};  // Ici on lui donne une taille de 100 et la 1e valeur à zero

    strcpy(copy, chaine1); // On copie "chaine1" dans "copy"

    // On vérifie s'il s'est bien passé
    printf("Le texte original est : %s\n", chaine1);
    printf("Le texte copié est : %s\n", copy);

    printf("--------------------------------------------\n");

    // UTILISATION DE LA FONCTION strcat
    printf("--- Utilisation de la fonction : strcat -----\n");
    // La fonction strcat permet d'ajouter une chaine à la suite d'une autre.

    // Initialisation des 2 tableaux de char 
    char chaine3[100] = "Salut ", chaine4[] = "Mathias !";
    // Ici on va concatène la variable chaine4 dans la variable chaine3
    // D'où la taille de chaine3 grande pour pouvoir le mettre les valeurs du
    // tableau chaine4.

    strcat(chaine3, chaine4); // Chaine4 dans chaine3

    // On vérifie si tous s'est bien passé
    printf("Chaine3 vaut maintenant : %s\n", chaine3);
    printf("Par contre, chaine4 vaut toujours : %s\n", chaine4);

    printf("--------------------------------------------\n");

    // UTILISATION DE LA FONCTION strcmp
    printf("--- Utilisation de la fonction : strcmp -----\n");
    // La fonction strcmp permet de comparer 2 chaines de caractères entre elles
    // Initialisation des chaines
    char chaine5[] = "Tous en choeurs", chaine6[100] = "Tous en choeurs";
    char chaine7[] = "Fanstastique", chaine8[] = "fanstastique";
    
    // Si les 2 chaines de caractères sont identiques, la fonction renvoie 0
    printf("Les chaine5 et chaine6 sont identiques car strcmp renvoie : %d\n", strcmp(chaine5, chaine6));

    // Si elles ne sont pas identiques mais font la même taille
    printf("Les chaine7 et chaine8 ne sont pas identiques car strcmp renvoie : %d\n", strcmp(chaine7, chaine8));

    // Si la 1er chaine de carac est plus grande que la 2e
    printf("La chaine5 est plus grand que la chaine7 car strcmp renvoie un nombre +ve : %d\n", strcmp(chaine5, chaine7));

    // Si la 1er chaine de carac est plus petite que la 2e
    printf("La chaine1 est plus petit que la chaine6 car strcmp renvoie un nombre -ve : %d\n", strcmp(chaine1, chaine5));

    printf("--------------------------------------------\n");

    // UTILISATION DE LA FONCTION strchr
    printf("--- Utilisation de la fonction : strchr -----\n");
    /*
    La fonction strchr permet de rechercher un caractère dans une chaine.
    Cette fonction renvoie un pointeur vers le premier caractère qu'elle a trouvé, 
    c'est-à-dire qu'elle renvoie l'adresse de ce caractère dans la mémoire. 
    Elle renvoie NULL si elle n'a rien trouvé.
    */
     
    // Initialisation du tableau de char
    char *suitechaine = NULL;

    // On recherche une lettre dans la chaine5
    suitechaine = strchr(chaine5, 'e');
    if (suitechaine != NULL)
    {
        printf("La chaine5 est : %s\n", chaine5);
        printf("La fin de la chaine5 à partir de la première lettre e : %s \n", suitechaine);
    }

    // Il existe une autre fonction similaire à strchr : strrchr qui renvoie un pointeur 
    // vers le dernier caractère qu'elle a trouvé dans la chaîne, plutôt que vers le premier.

    char *suitechaine2 = NULL;
    suitechaine2 = strrchr(chaine5, 'e');
    if (suitechaine2 != NULL)
    {
        printf("La fin de la chaine5 à partir de la dernière lettre e : %s \n", suitechaine2);
    }
    printf("--------------------------------------------\n");

    // UTILISATION DE LA FONCTION strpbrk
    printf("--- Utilisation de la fonction : strpbrk ----\n");
    // La fonction strpbrk, comparé à strchr, va lui chercher un des caractères dans la liste que vous lui donnez sous forme de chaîne.
    // Initialisation du tableau de char
    char *suitechaine3;
    suitechaine3 = strpbrk(chaine5, "zns");
    // Ici on va vérifier la première occurrence de z, n ou s dans la chaine5.
    if (suitechaine3 != NULL)
    {
        printf("La chaine5 est : %s\n", chaine5);
        printf("La fin de la chaine5 à partir du premier des caractères trouvés : %s \n", suitechaine3);
        // On remarque qu'ici c'est la lettre "s" qui est en premier dans la chaine5
        // Donc, dans la fonction strpbrk, l'ordre des caractères dans la liste n'a pas
        // d'importance.
    }
    printf("--------------------------------------------\n");

    // UTILISATION DE LA FONCTION strstr
    printf("--- Utilisation de la fonction : strstr ----\n");
    // La fonction strstr permet de chercher une chaine dans une autre chaine plus grande.
    // Initialisation de la chaine 
    char *suitechaine4;
    suitechaine4 = strstr(chaine5, "en");
    if (suitechaine4 != NULL)
    {
        printf("La chaine5 est : %s\n", chaine5);
        printf("Première occurrence de 'en' dans la chaine5 : %s \n", suitechaine4);
    }
    printf("--------------------------------------------\n");

    // UTILISATION DE LA FONCTION sprintf
    printf("--- Utilisation de la fonction : sprintf ---\n");
    // La fonction sprintf, qui se trouve "stdio.h", contrairement aux autres qui se trouvent
    // dans "string.h", ressemble beaucoup à la fonction printf, sauf au lieu de l'afficher
    // sur l'écran, il va sauvegarder le contenu dans une chaine

    // Initialisation de la chaine
    char chaine9[100];
    int age = 10;

    // On écrit une phrase dans la chaine9
    sprintf(chaine9, "Tu vas avoir bientôt %d ans !", age);

    // On affiche la chaine9 pour vérifier qu'elle contient bien la phrase ci-dessus
    printf("La phrase dans la chaine9 est : '%s'\n", chaine9);

    printf("--------------------------------------------\n");

    return 0;
}