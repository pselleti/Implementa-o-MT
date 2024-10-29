#include <stdio.h>
#include <string.h>

#define ESTADO_INICIAL 0
#define ESTADO_ACEITO 1
#define ESTADO_REJEITADO -1

#define DIREITA 1
#define ESQUERDA -1
#define PARADO 0

int maquina_turing(char fita[], int tamanho) {
    int estado = ESTADO_INICIAL; 
    int posicao = 0; 
    
    while (estado != ESTADO_ACEITO && estado != ESTADO_REJEITADO) {
        
        if (posicao < 0 || posicao >= tamanho) {
            estado = ESTADO_REJEITADO;
            break;
        }

        char simbolo_atual = fita[posicao];
        
        switch (estado) {
            case ESTADO_INICIAL:
                if (simbolo_atual == 'a') {
                    fita[posicao] = 'X'; 
                    posicao += DIREITA; 
                    estado = 2; 
                } else if (simbolo_atual == 'Y') {
                    estado = ESTADO_ACEITO; 
                } else {
                    estado = ESTADO_REJEITADO; 
                }
                break;
                
            case 2:
                if (simbolo_atual == 'a' || simbolo_atual == 'Y') {
                    posicao += DIREITA; 
                } else if (simbolo_atual == 'b') {
                    fita[posicao] = 'Y'; 
                    posicao += ESQUERDA; 
                    estado = 3; 
                } else {
                    estado = ESTADO_REJEITADO;
                }
                break;
                
            case 3:
                if (simbolo_atual == 'a' || simbolo_atual == 'Y') {
                    posicao += ESQUERDA; 
                } else if (simbolo_atual == 'X') {
                    posicao += DIREITA; 
                    estado = ESTADO_INICIAL; 
                } else {
                    estado = ESTADO_REJEITADO;
                }
                break;
                
            default:
                estado = ESTADO_REJEITADO;
                break;
        }
    }
    
    
    return estado == ESTADO_ACEITO;
}

int main() {
    char fita[100];
    printf("Digite a fita de entrada (apenas 'a' e 'b'): ");
    scanf("%s", fita);
    
    int tamanho = strlen(fita);
    if (maquina_turing(fita, tamanho)) {
        printf("A fita foi aceita!\n");
    } else {
        printf("A fita foi rejeitada.\n");
    }
    
    return 0;
}