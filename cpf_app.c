#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

void gerarCPF(char* cpf){ // n = quantidade CPFS pra serem gerados.
    int digitoscpf[11];
    int resto, soma = 0;

    for(int i = 0; i < 9; i++){ // 9 primeiros digitos
        digitoscpf[i] = rand() % 10;
    }
    for(int i = 0; i < 9; i++){
        soma += digitoscpf[i] * (10-i);
    }
    // Primeiro digito verificador.
    resto = soma % 11;
    digitoscpf[9] = (resto < 2) ? 0 : (11 - resto);

    soma = 0;
    for(int i = 0; i < 10; i++){
        soma += digitoscpf[i] * (11-i);
    }
    // Segundo digito verificador.
    resto = soma % 11;
    digitoscpf[10] = (resto < 2) ? 0 : (11 - resto);

    for(int i = 0; i < 11; i++){ // Formatando como string;
        cpf[i] = digitoscpf[i] + '0';
    }
    cpf[11] = '\0'; 
}

int validarCPF(const char cpf[]){

    int dv1, dv2, resto = 0, soma = 0;

    if(strlen(cpf) != 11){// Validação do tamanho
        return 0;
    }

    for(int i = 0; i < 9; i++){ // Validação primeiro digito verificador
        soma+= (cpf[i]-'0')*(10-i);
    }
    resto = (soma % 11) < 2? 0 : 11-(soma%11);
    dv1 = resto;
    if(dv1 != cpf[9]-'0'){
        return 0;
    }

    soma = 0;
    resto = 0;
    for(int i = 0; i < 10; i++){// Validação segundo digito verificador
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
    char opcao, cpf[12];
    int qtdcpfs;
    FILE *arq;

    printf("Seja bem vindo ao CPF APP!\n");
    printf("Atencao as observacoes:\n(1) - Os CPFs gerados sairao no arquivo 'output.txt'.\n");
    printf("(2) - Os CPFs a serem validados devem estar no arquivo 'input.txt'.\n");
    printf("(3) - Os CPFs a serem validados devem ser apenas numeros, sem caracteres.\n");
    printf("Pressione enter para continuar...");
    getchar();
    
    printf("\n1 - Gerador de CPF.\n");
    printf("2 - Validador de CPF.\n");
    printf("Escolha a opcao desejada: ");
    scanf("%c", &opcao);
    getchar();
    
    switch (opcao)
    {
    case '1':
        printf("\nDigite quantos CPFs a serem gerados: ");
        scanf("%d", &qtdcpfs);
        arq = fopen("output.txt", "w");
        if(arq == NULL){
            printf("Problema ao criar o arquivo.");
            return 1;
        }
         for (int i = 0; i < qtdcpfs; i++){
            gerarCPF(cpf);
            fprintf(arq, "%s\n", cpf);
        }
        printf("%d CPFs gerados e salvos em 'output.txt'.\n", qtdcpfs);
        break;

    case '2':
        printf("Digite o CPF a ser validado: ");
        scanf("%11s", cpf);
        if(validarCPF(cpf)){
            printf("CPF valido: %s\n", cpf);
        }else{
            printf("CPF invalido: %s\n", cpf);
        }
        break;
    
    default:
        printf("Opcao invalida.");
        break;
    }
    printf("\nPressione enter para fechar o programa.");
    getch();
    return 0;
}