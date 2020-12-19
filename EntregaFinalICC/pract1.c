#include <stdio.h>
#include <stdlib.h>

#include "pracFuns.h"

int main (void){
    int n;
    printf("Dimensió de la matriu , (n,n) = \n");
    scanf("%d", &n);
    
    //Reservem memoria per la matriu
    double **A;
    A = (double **) malloc(n * sizeof(double *));
    if (A == NULL) {
        printf("No hi ha prou memoria");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        A[i] = (double *) malloc(n * sizeof(double));
        if (A[i] == NULL){
            printf("No hi ha prou memoria");
            return 1;
        }
    }
    //Reservem memoria per els vectors
    double *x, *b, *y;
    x = (double *) malloc(n * sizeof(double));
    b = (double *) malloc(n * sizeof(double));
    y = (double *) malloc(n * sizeof(double));
    if ( x == NULL || b == NULL || y == NULL) {
        printf("No hi ha prou memoria");
        return 3;
    }
    //Demana valors de la matriu
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("Valor (%d x %d) de la matriu A \n", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    //Imprimeix la matriu
    printf("\nLa matriu A:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++) {
        printf("Valor %d del vector b\n", i);
        scanf("%lf", &b[i]);
    }
    printf("\nVector b: \n");
    for (int i = 0; i < n; i++) {
        printf("%lf \n", b[i]);
    }
    //Cridem a la funcio resolTS
    resolTS(n, A, b, x, 0.00000001);
    
    printf("\nVector x: \n");
    for (int i = 0; i < n; i++) {
        printf("%lf \n", x[i]);
    }
    //Cridem a la funcio prodMatVec
    prodMatVec(A, x, y, n);
    printf("\nVector = Ax - b:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf - %lf = %lf\n", y[i], b[i], y[i]-b[i]);
    }
}