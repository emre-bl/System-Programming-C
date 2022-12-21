#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int *tensor;
    int m, n, q;
    printf("Sirasiyla M, N, Q degerlerini giriniz: ");
    scanf("%d %d %d", &m, &n, &q);
    tensor = (int *)malloc(m * n * q * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < q; k++){
                tensor[i * n * q + j * q + k] = rand() % 11;
            }
        }
    }
    printf("Baslangic degerleri:\n\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < q; k++){
                printf("%d ", tensor[i * n * q + j * q + k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    int random = rand() % 11 - 5;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < q; k++){
                tensor[i * n * q + j * q + k] += random;
            }
        }
    }
    printf("[-5, 5] arasinda bir sayi ekledikten sonra:\n\n");

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < q; k++){
                printf("%d ", tensor[i * n * q + j * q + k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    free(tensor);
    return 0;
}

