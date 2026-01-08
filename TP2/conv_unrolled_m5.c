#include <stdio.h>
#include <gem5/m5ops.h>

#define N 320  // Taille de la matrice d'entrée
#define K 4    // Taille du filtre

static float input[N][N];
static float kernel[K][K];
static float output[N-K+1][N-K+1];


static void init_data(int seed) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            input[i][j] = (float)((i + j + seed) & 0xFF);

    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            kernel[i][j] = (float)((i + 2*j + seed) & 0xF);
}

// Convolution 2D float avec loop unrolling 4x4 (K=4)
void convolution2D(void) {
    int i, j;

    for (i = 0; i < N - K + 1; i++) {
        for (j = 0; j < N - K + 1; j++) {
            float sum = 0.0f;

            // Unrolling complet du filtre 4x4 (pas besoin de boucles ki/kj)
            sum += input[i+0][j+0] * kernel[0][0];
            sum += input[i+0][j+1] * kernel[0][1];
            sum += input[i+0][j+2] * kernel[0][2];
            sum += input[i+0][j+3] * kernel[0][3];

            sum += input[i+1][j+0] * kernel[1][0];
            sum += input[i+1][j+1] * kernel[1][1];
            sum += input[i+1][j+2] * kernel[1][2];
            sum += input[i+1][j+3] * kernel[1][3];

            sum += input[i+2][j+0] * kernel[2][0];
            sum += input[i+2][j+1] * kernel[2][1];
            sum += input[i+2][j+2] * kernel[2][2];
            sum += input[i+2][j+3] * kernel[2][3];

            sum += input[i+3][j+0] * kernel[3][0];
            sum += input[i+3][j+1] * kernel[3][1];
            sum += input[i+3][j+2] * kernel[3][2];
            sum += input[i+3][j+3] * kernel[3][3];

            output[i][j] = sum;
        }
    }
}

int main(int argc, char **argv) {
    init_data(argc);          // hors ROI

    m5_reset_stats(0, 0);     // début ROI
    convolution2D();          // code mesuré
    m5_dump_stats(0, 0);      // fin ROI

    volatile float sink = output[0][0];
    return (int)sink;
}
