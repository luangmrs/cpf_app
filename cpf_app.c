#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarcpf(int n){ // n = quantidade CPFS pra serem gerados.
    for(int i = 0; i < n; i++){
        int digitoscpf[11];
        int resto, soma = 0;
        
        for(int i = 0; i < 9; i++){ // 9 primeiros digitos
            digitoscpf[i] = rand() % 10;
        }
        for(int i = 0; i < 9; i++){
            soma += digitoscpf[i] * (10-i);
        }
        // primeiro digito verificador.
        resto = soma % 11;
        digitoscpf[9] = (resto < 2) ? 0 : (11 - resto);
        
        soma = 0;
        for(int i = 0; i < 10; i++){
            soma += digitoscpf[i] * (11-i);
        }
        // segundo digito verificador.
        resto = soma % 11;
        digitoscpf[10] = (resto < 2) ? 0 : (11 - resto);

        for(int i = 0; i < 11; i++){
            printf("%d", digitoscpf[i]);
        }
    printf("\n");
}}

int main(){
    srand(time(NULL));
    
    gerarcpf(0);
    
    return 0;
}