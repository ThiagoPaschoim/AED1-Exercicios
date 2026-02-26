#include <stdio.h>

int main() {
    // Declaração das variáveis com os valores pedidos
    int inteiro = 7;
    float realSimples = 1.83;
    double realDuplo = 3.1415;
    char letra = 'K';
    char frase[] = "Variaveis";
    
    // Saída formatada
    printf("%d\n", inteiro);          // %d para inteiros
    printf("%.2f\n", realSimples);    // %.2f limita o float a 2 casas
    printf("%.4lf\n", realDuplo);     // %.4lf limita o double a 4 casas
    printf("%c\n", letra);            // %c para caractere único
    printf("%s\n", frase);            // %s para string (cadeia de caracteres)

    return 0;
}
