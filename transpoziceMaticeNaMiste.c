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

    if (matice == NULL || *matice == NULL || radky == NULL || sloupce == NULL || *radky <= 0 || *sloupce <= 0)
        return 0;

    int temp = *radky;
    *radky = *sloupce;
    *sloupce = temp;

    int **matice_temp = malloc(sizeof(*matice_temp) * *radky);
    if (matice_temp == NULL){
        uvolni_matici(*matice, *sloupce);
        return 0;
    }

    for (int i = 0; i < *radky; i++){
        matice_temp[i] = malloc(sizeof(*matice_temp[i]) * *sloupce);
        if (matice_temp[i] == NULL){
            uvolni_matici(*matice, *sloupce);
            uvolni_matici(matice_temp, i);
            return 0;
        }
    }

    for (int i = 0; i < *radky; i++){
        for (int j = 0; j < *sloupce; j++)
            matice_temp[i][j] = (*matice)[j][i];
    }

    uvolni_matici(*matice, *sloupce);
    *matice = matice_temp;

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
                uvolni_matici(matice, radky);
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