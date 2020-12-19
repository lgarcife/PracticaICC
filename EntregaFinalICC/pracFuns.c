/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pracFuns.c
 * Author: laura
 * 
 * Created on December 18, 2020, 6:06 PM
 */
#include <stdio.h>
#include "pracFuns.h"
int resolTS (int n, double **A, double *b, double *x, double tol)
{
    x[n-1] = b[n-1]/A[n-1][n-1];
    
    int i,j;
    
    for (i=n-2; i>=0; i--){
        x[i] = b[i];
        for(j=n-1; j>i; j--){
            if (A[i][j] < 0) {
                if (-A[i][j] < tol) {
                    return 1;
                }
            } else {
                if (A[i][j] < tol) {
                    return 1;
                }
            }
            x[i] -= x[j] * A[i][j];
        }
        x[i] = x[i]/A[i][i];
    }
    return 0;
}
void prodMatVec (double **A, double *x, double *y, int n) {
    for(int i = 0; i < n; i++) {
        y[i] = 0.0;
        for(int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}
double norma2 (int n, double *z) {
    double norma, norma_2;
    norma = 0;
    norma_2 = 0;
    for (int i = 0; i < n; i++) {
        norma += z[i]*z[i];
    }
    for (double i = 0.00000; i*i < norma; i += 0.00001) {
        norma_2 = i;
    }
    printf("\n");
    return norma_2;
}