#include <stdio.h>
#include <stdlib.h>

int transponuj_matici(int ***matice, int *radky, int *sloupce){




    return 1;
}

int main(void){

    int radky, sloupce;

    printf("Zadej rozmery matice (radky sloupce):\n");
    if (scanf("%d %d", &radky, &sloupce) != 2 || radky <= 0 || sloupce <= 0){
        printf("Nespravny vstup.\n");
        return 1;
    }

    int **matice = malloc(sizeof(*matice) * radky);
    if (matice == NULL){
        printf("Nespravny vstup.\n");
        return 1;
    }

    



    return 0;
}