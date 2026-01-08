#include <stdint.h>
#include <gem5/m5ops.h>

#define N 320
#define K 4

int input[N][N];
int kernel[K][K];
int output[N-K+1][N-K+1];


void init_data(int seed) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            input[i][j] = (i + j + seed) & 0xFF;

    for (int ki = 0; ki < K; ki++)
        for (int kj = 0; kj < K; kj++)
            kernel[ki][kj] = (ki + 2*kj + seed) & 0xF;
}

/* Convolution entière */
void convolution2D(void){
    int i, j, ki, kj;

    for (i = 0; i < N - K + 1; i++) {
        for (j = 0; j < N - K + 1; j++) {
            int sum = 0;

            for (int ki=0;ki<K;ki++){
                for (int kj=0;kj<K;kj++){
                    sum += input[i+ki][j+kj] * kernel[ki][kj];
                }
            }
            output[i][j] = sum;
        }
    }
}

int main(int argc, char **argv) {
    init_data(argc);              // hors ROI, donc non mesuré

    m5_reset_stats(0, 0);         // début ROI
    convolution2D();              // ce que tu veux mesurer
    m5_dump_stats(0, 0);          // fin ROI

    // ancrage minimal (évite suppression si le compilateur est agressif)
    volatile int sink = output[0][0];
    return sink & 0xFF;
}
