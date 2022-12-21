#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int ***tensor;
    int m, n, q;
    printf("Sirasiyla M, N, Q degerlerini giriniz: ");
    scanf("%d %d %d", &m, &n, &q);
    tensor = (int ***)malloc(m * sizeof(int **));
    for (int i = 0; i < m; i++){
        tensor[i] = (int **)malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++){
            tensor[i][j] = (int *)malloc(q * sizeof(int));
        }
    }
    srand(time(NULL));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < q; k++){
                tensor[i][j][k] = rand() % 11;
            }
        }
    }
    printf("Baslangic degerleri:\n\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < q; k++){
                printf("%d ", tensor[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    int random = rand() % 11 - 5;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < q; k++){
                tensor[i][j][k] += random;
            }
        }
    }
    printf("[-5, 5] arasinda bir sayi ekledikten sonra:\n\n");

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < q; k++){
                printf("%d ", tensor[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            free(tensor[i][j]);
        }
        free(tensor[i]);
    }
    free(tensor);
    return 0;
}

