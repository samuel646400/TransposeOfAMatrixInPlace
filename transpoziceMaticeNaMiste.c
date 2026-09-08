#include <stdio.h>
#include <stdlib.h>

void uvolni_matici(int **matice, int radky){

    for (int i = 0; i < radky; i++){
        if (matice[i] != NULL)
            free(matice[i]);
    }

    free(matice);
}

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

    for (int i = 0; i < radky; i++){
        matice[i] = malloc(sizeof(*matice[i]) * sloupce);
        if (matice[i] == NULL){
            uvolni_matici(matice, i);
            printf("Nespravny vstup.\n");
            return 1;
        }
    }

    printf("Zadejte prvky matice:\n");
    for (int i = 0; i < radky; i++){
        for (int j = 0; j < sloupce; j++){
            if (scanf("%d", &matice[i][j]) != 1){
                uvolni_matici(matice, i);
                printf("Nespravny vstup.\n");
                return 1;
            }
        }
    }

    if (transponuj_matici(&matice, &radky, &sloupce)){
        printf("Transponovana matice:\n");
        for (int i = 0; i < radky; i++){
            for (int j = 0; j < sloupce; j++){
                if (j == sloupce - 1)
                    printf("%d\n", matice[i][j]);
                else
                    printf("%d ", matice[i][j]);
            }
        }

        uvolni_matici(matice, radky);
    }
    else {

        printf("Nespravny vstup.\n");
        return 1;
    }

    return 0;
}