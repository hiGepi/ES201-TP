#include <stdio.h>

#define N 320  // Taille de la matrice d'entrée
#define K 4    // Taille du filtre

static float input[N][N];
static float kernel[K][K];
static float output[N-K+1][N-K+1];

// Fonction de convolution avec loop unrolling
void convolution2D() {
    int i,j,ki,kj;

    for (i = 0; i < N - K + 1; i++) {
        for (j = 0; j < N - K + 1; j++) {
            float sum = 0.0f;

            // Unrolling par bloc de 4x4 pour accélérer les calculs
            for (ki = 0; ki < K; ki += 4) {
                for (kj = 0; kj < K; kj += 4) {
                    sum += input[i + ki][j + kj] * kernel[ki][kj] +
                           input[i + ki][j + kj + 1] * kernel[ki][kj + 1] +
                           input[i + ki][j + kj + 2] * kernel[ki][kj + 2] +
                           input[i + ki][j + kj + 3] * kernel[ki][kj + 3];

                    sum += input[i + ki + 1][j + kj] * kernel[ki + 1][kj] +
                           input[i + ki + 1][j + kj + 1] * kernel[ki + 1][kj + 1] +
                           input[i + ki + 1][j + kj + 2] * kernel[ki + 1][kj + 2] +
                           input[i + ki + 1][j + kj + 3] * kernel[ki + 1][kj + 3];

                    sum += input[i + ki + 2][j + kj] * kernel[ki + 2][kj] +
                           input[i + ki + 2][j + kj + 1] * kernel[ki + 2][kj + 1] +
                           input[i + ki + 2][j + kj + 2] * kernel[ki + 2][kj + 2] +
                           input[i + ki + 2][j + kj + 3] * kernel[ki + 2][kj + 3];

                    sum += input[i + ki + 3][j + kj] * kernel[ki + 3][kj] +
                           input[i + ki + 3][j + kj + 1] * kernel[ki + 3][kj + 1] +
                           input[i + ki + 3][j + kj + 2] * kernel[ki + 3][kj + 2] +
                           input[i + ki + 3][j + kj + 3] * kernel[ki + 3][kj + 3];
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
