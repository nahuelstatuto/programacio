#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double **crear_matriz(int); /* Función para asignar memoria a una matriz de tamaño n */
void liberar_matriz(double **, int);/* Función para liberar memoria de una matriz */


/* Programa principal */
int main() {
    int n;
    double **A;

    /* Solicitar el tamaño de la matriz y el orden de la expansión */
    printf("Ingrese la dimensión de la matriz: ");
    scanf("%d", &n);
    
    /* Asignar memoria a las matrices */
    A = crear_matriz(n);
    liberar_matriz(A, n);
    
    return 0;
}

double **crear_matriz(int n) {
    int i;
    double **matriz = (double **)malloc(n * sizeof(double *));
    if (matriz == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        matriz[i] = (double *)malloc(n * sizeof(double));
        if (matriz[i] == NULL) {
            printf("Error: No se pudo asignar memoria.\n");
            exit(1);
        }
    }
    return matriz;
}

void liberar_matriz(double **matriz, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}