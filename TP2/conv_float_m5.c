#include <stdio.h>
#include <gem5/m5ops.h>

#define N 320
#define K 4

static float input[N][N];
static float kernel[K][K];
static float output[N-K+1][N-K+1];


void init_data(int seed) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            input[i][j] = (float)((i + j + seed) & 0xFF);

    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            kernel[i][j] = (float)((i + 2*j + seed) & 0xF);
}

/* Convolution flottante */
void convolution2D(void) {
    int i, j, ki, kj;

    for (i = 0; i < N - K + 1; i++) {
        for (j = 0; j < N - K + 1; j++) {
            float sum = 0.0f;

            for (ki = 0; ki < K; ki++) {
                for (kj = 0; kj < K; kj++) {
                    sum += input[i + ki][j + kj] * kernel[ki][kj];
                }
            }

            output[i][j] = sum;
        }
    }
}

int main(int argc, char **argv) {
    init_data(argc);          // hors ROI

    m5_reset_stats(0, 0);     // début ROI
    convolution2D();          // code mesuré
    m5_dump_stats(0, 0);      // fin ROI

    /* Ancrage minimal pour éviter toute élimination tardive */
    volatile float sink = output[0][0];
    return (int)sink;
}
