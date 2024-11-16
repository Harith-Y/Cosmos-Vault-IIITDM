#include <stdio.h>
#include <stdlib.h>

void readInput(char *filename, int **arr, int *n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file!\n");
        exit(1);
    }

    fscanf(file, "%d", n);
    *arr = (int*)malloc((*n) * sizeof(int));

    for (int i = 0; i < *n; i++)
        fscanf(file, "%d", (*arr) + i);

    fclose(file);
}

