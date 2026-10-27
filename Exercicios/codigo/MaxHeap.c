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

void peneirar(int *h, int pai, int n)
{
    int fDir = filhoDireita(pai), fEsq = filhoEsquerda(pai), iMaior = pai, aux;
    if(fDir < n && h[fDir] > h[pai])
    {
        iMaior = fDir;
    }
    if(fEsq < n && h[fEsq] > h[iMaior])
    {
        iMaior = fEsq;
    }
    if(iMaior != pai)
    {
        aux = h[pai];
        h[pai] = h[iMaior];
        h[iMaior] = aux;
        peneirar(h, iMaior, n);
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