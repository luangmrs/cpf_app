#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

int validarCPF(const char cpf[]){
    int dv1, dv2, resto = 0, soma = 0;

    if(strlen(cpf) != 11){//validação do tamanho
        return 0;
    }

    for(int i = 0; i < 9; i++){ //validação primeiro digito verificador
        soma+= (cpf[i]-'0')*(10-i);
    }
    resto = (soma % 11) < 2? 0 : 11-(soma%11);
    dv1 = resto;
    if(dv1 != cpf[9]-'0'){
        return 0;
    }

    soma = 0;
    resto = 0;
    for(int i = 0; i < 10; i++){//validação segundo digito verificador
        soma+= (cpf[i]-'0')*(11-i);
    }
    resto = (soma % 11) < 2? 0 : 11-(soma%11);
    dv2 = resto;
    if(dv2 != cpf[10]-'0'){
        return 0;
    }
    
    return 1;
}
int main(){
    srand(time(NULL));
    
    char cpf[12] = "0713838819";
    if(validarCPF(cpf)){
        printf("CPF valido: %s\n", cpf);
    }else{
        printf("CPF invalido: %s\n", cpf);
    }

    return 0;
}