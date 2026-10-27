#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacidade;
    
    if (scanf("%d", &capacidade) != 1) return 0;
    
    // CORREÇÃO: Lógica acadêmica clássica do "espaço sacrificado".
    // Alocamos capacidade + 1 para garantir que a fila consiga armazenar 
    // exatamente 'capacidade' elementos usando a fórmula (fim+1)%MAX
    int max = capacidade + 1;
    int *fila = (int *)malloc(max * sizeof(int));
    
    int inicio = 0;
    int fim = 0;
    
    char operacao;
    int valor;
    
    while (scanf(" %c", &operacao) != EOF) {
        if (operacao == 'E') {
            scanf("%d", &valor);
            
            // Fila Cheia acadêmica: o próximo índice após o fim é o próprio início
            if ((fim + 1) % max == inicio) {
                continue; // Ignora
            }
            
            fila[fim] = valor;
            fim = (fim + 1) % max;
            
        } else if (operacao == 'D') {
            
            // Fila Vazia: Início alcançou o fim
            if (inicio == fim) {
                continue; // Ignora
            }
            
            int valor_removido = fila[inicio];
            inicio = (inicio + 1) % max;
            
            printf("%d\n", valor_removido);
        }
    }
    
    free(fila);
    return 0;
}