#include <stdio.h>   
#include <stdlib.h>

int main(int argc, const char * argv[]) {

    // Utilisation des conditions if et else
    int age = 50;

    if (age >= 21)
    {
        printf("Vous etes majeur et vous pouvez rentrer dans un casino !\n");
    }
    else if (age >= 18) 
    {
        printf("Vous etes majeur mais vous ne pouvez pas rentrer dans un casino !\n");
    }
    else
    {
        printf("Dommage, Vous etes mineur !\n");
    }

    return 0;
}