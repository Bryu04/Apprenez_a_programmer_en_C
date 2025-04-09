#include <stdio.h>   
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // Utilisation du boucles while
    int compteur = 0;

    printf("Boucles while\n");
    while (compteur < 5)
    {
        printf("Compter vaut %d\n", compteur);
        compteur++;
    }
    

    // Boucles do.. while
    int counter2 = 10;
    printf("Engine sequences start\n");
    do
    { 
        if (counter2 == 10)
        {
            printf("T minus %d\n", counter2);
        }
        else
        {
            printf("%d\n", counter2);
        }
        counter2--;
    } while (counter2 != 0);
    printf("Zero, Ignition and lift off\n");

    // Boucles for
    for (int counter3 = 0; counter3 <= 10; counter3 += 2)
    {
        printf("Counter equal %d\n", counter3);
    }

    return 0;
}