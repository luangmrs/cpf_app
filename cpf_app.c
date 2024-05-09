#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarcpf(){
    srand(time(NULL));
    int digitoscpf[10];
    for(int i = 0; i < 9; i++){ // 9 primeiros digitos
        digitoscpf[i] = rand() % 9 + 1;
        printf("%d", digitoscpf[i]);
    }
}

int main(){
    gerarcpf();
    return 0;
}