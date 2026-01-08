#include <stdio.h>

#define N 320  // Taille de la matrice d'entrée
#define K 4    // Taille du filtre

static int input[N][N];
static int kernel[K][K];
static int output[N-K+1][N-K+1];

// Fonction de convolution 
int convolution2D() {
    int i,j,ki,kj;

    for (i = 0; i < N - K + 1; i++) {
        for (j = 0; j < N - K + 1; j++) {
            volatile int sum = 0;

            // Boucles imbriquées pour appliquer le filtre
            for (ki = 0; ki < K; ki++) {
                for (kj = 0; kj < K; kj++) {
                    sum += input[i + ki][j + kj] * kernel[ki][kj];
                }
            }

            output[i][j] = sum;
        }
    }
}

// Fonction principale
int main() {
    convolution2D();
    return 0;
}
