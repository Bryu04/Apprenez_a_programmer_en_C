#include <stdio.h>   
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // Initiation de la variable choix
    int choix = 0;
    // On montre le menu au client
    printf("=== Menu ===\n");
    printf("1. Royal Cheese\n");
    printf("2. Mc Deluxe\n");
    printf("3. Mc Bacon\n");
    printf("4. Big Mac\n");
    printf("Votre choix ? : ");
    
    // On prend la commande du client
    scanf("%d", &choix);

    // On compare la commande du client au menu
    switch (choix)
    {
    case 1:
        printf("Vous avez commandE le menu Royal Chesse !\n");
        break;
    case 2:
        printf("Vous avez commandE le menu Mc Deluxe !\n");
        break;
    case 3:
        printf("Vous avez commandE le menu Mc Bacon !\n");
        break;
    case 4:
        printf("Vous avez commandE le menu Big Mac !\n");
        break;
    default:
        printf("DesolE, je n'ai pas compris votre commande !");
        break;
    }
    return 0;
}