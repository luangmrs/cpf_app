#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarcpf(){
    srand(time(NULL));
    int digitoscpf[10];
    int decimodigito;
    int somadigitos = 0;
    for(int i = 0; i < 9; i++){ // 9 primeiros digitos
        digitoscpf[i] = rand() % 9 + 1;
        printf("%d", digitoscpf[i]);
    }
    for(int i = 0; i < 9; i++){
        int m = 10;
        somadigitos = digitoscpf[i * m] + somadigitos;
        m--;
    }
    decimodigito = 11 - (somadigitos % 11);
    printf("%d", decimodigito);
    
}

int main(){
    gerarcpf();
    return 0;
}