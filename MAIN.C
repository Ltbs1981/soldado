#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char sexo;
    int idade;
    float altura;
} Alistamento;

Alistamento* DadosAlistamento(char* nome, char sexo, int idade, float altura) {
    Alistamento* NovoAlistamento = (Alistamento*)malloc(sizeof(Alistamento));
    if (NovoAlistamento == NULL) {
        printf("Erro ao alocar na memória.");
        exit(1);
    }
    strcpy(NovoAlistamento->nome, nome);
    NovoAlistamento->altura = altura;
    NovoAlistamento->idade = idade;
    NovoAlistamento->sexo = sexo;
    return NovoAlistamento;
}

int main() {
    char nome[30];
    char sexo;
    int idade;
    float altura;

    printf("Qual o seu nome? ");
    scanf("%s", nome);

    printf("Qual o seu sexo (M/F)? ");
    scanf(" %c", &sexo);  // Note o espaço antes do %c para consumir o caractere de nova linha pendente

    printf("Qual a sua idade? ");
    scanf("%d", &idade);

    printf("Qual a sua altura? ");
    scanf("%f", &altura);

    Alistamento* pessoa1 = DadosAlistamento(nome, sexo, idade, altura);

    if (pessoa1->idade >= 18 && pessoa1->altura >= 1.75) {
        printf("Parabéns, %s! Você já pode se alistar.\n", pessoa1->nome);
    } else {
        printf("Desculpe, %s, você ainda não pode se alistar.\n", pessoa1->nome);
    }

    free(pessoa1);

    return 0;
}
