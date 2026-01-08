#include <stdint.h>
#define N 50

int main(void){
    volatile int a[N], b[N], c[N];

    for(int i=0;i<N;i++) 
			c[i]=a[i]+b[i];

    return 0;
}
