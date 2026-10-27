#include <stdio.h>
#include <stdlib.h>

void constroiHeap(int *, int);
int ultimoPai(int);
void peneirar(int *, int, int);
int filhoEsquerda(int);
int filhoDireita(int);

int main()
{
    int n, i, *vet;
    // Lê o tamanho usando o mesmo padrão do seu MaxHeap.c
    scanf("%d", &n);
    while(n > 0)
    {
        vet = (int*) malloc(n*sizeof(int));
        for(i=0; i<n; i++)
        {
            scanf("%d", &vet[i]);
        }
        
        constroiHeap(vet, n);
        
        for(i=0; i<n; i++)
        {
            // Impressão idêntica à do professor
            printf("%d%s", vet[i], i<n-1?" ":"\n");
        }
        free(vet);
        scanf("%d", &n);
    }
    return 0;
}

int ultimoPai(int n)
{
    return n/2-1;
}

int filhoEsquerda(int pai)
{
    return 2*pai+1;
}

int filhoDireita(int pai)
{
    return 2*pai+2;
}

// A mágica ajustada para Min Heap
void peneirar(int *h, int pai, int n)
{
    int fDir = filhoDireita(pai), fEsq = filhoEsquerda(pai), iMenor = pai, aux;
    
    // A ordem do professor: verifica a DIREITA primeiro!
    // Para o Min Heap, verificamos se o filho é MENOR (<)
    if(fDir < n && h[fDir] < h[pai])
    {
        iMenor = fDir;
    }
    
    // Depois verifica a ESQUERDA
    if(fEsq < n && h[fEsq] < h[iMenor])
    {
        iMenor = fEsq;
    }
    
    if(iMenor != pai)
    {
        aux = h[pai];
        h[pai] = h[iMenor];
        h[iMenor] = aux;
        peneirar(h, iMenor, n);
    }
}

void constroiHeap(int *h, int n)
{
    int pai;
    for(pai=ultimoPai(n); pai>=0; pai--)
    {
        peneirar(h, pai, n);
    }
}