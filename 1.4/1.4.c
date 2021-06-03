#include <stdio.h>
#include <stdlib.h>
void matrix_destroy(int** ptr, int height) {
    if (height > 0) {
        
            for (int i = 0; height > i; i++) {
                if (*(ptr + i) != NULL) {
                    free(*(ptr + i));
                }
            }
        
        free(ptr);
    }
}
int main()
{
    int height = 10;
    int width = 10;
    int** ptr = NULL;
    ptr = (int**)calloc(height, sizeof(int*)); //rzutownaie na wsakżnik na wskaźnik plus alokacaj pamięi dla kolejnych wierszy * ilość pamięci o wielkości wskażnika int
    if (ptr == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    for (int i = 0; height > i; i++) {
        *(ptr + i) = NULL;
        *(ptr + i) = calloc(width, sizeof(int));
        if (*(ptr + i) == NULL) {
            matrix_destroy(ptr, height);
            printf("Failed to allocate memory");
            return 8;
        }
    }

    for (int i = 0; height > i; i++) {
        for (int j = 0; width > j; j++) {
            int temp = (i+1) * (j+1);
            *(*(ptr + i) + j) = temp;
        }
    }
    
    for (int i = 0; height > i; i++) {
        if (*(ptr + i) != NULL) {
            
            for (int j = 0; width > j; j++) {
                
                    printf(" %3d", *(*(ptr + i) + j));
                
           
            }
            
                printf("\n");

            
        }
    }
    matrix_destroy(ptr, height);
    return 0;
}