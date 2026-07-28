#include <stdio.h>

int main() {
    // Declaração usando long long para suportar 64 bits (conforme restrição do PDF)
    long long n;

    // Leitura usando o especificador %lld
    // Verificamos se a leitura foi bem sucedida
    if (scanf("%lld", &n) != 1) return 0;

    // Impressão usando %lld
    // O PDF pede para "saltar uma linha após a impressão". 
    // Em problemas de linha única, geralmente um único \n basta.
    printf("%lld\n", n);

    return 0;
}


// =================================================================================================
// GUIA DEFINITIVO DE REVISÃO: ESTRUTURA DE DADOS E ALGORITMOS DE ORDENAÇÃO
// =================================================================================================
//
//
// -------------------------------------------------------------------------------------------------
// 1. INSERTION SORT (Ordenação por Inserção)
// Exercícios: OrdenaInsertion, InsertionCorretude, InsertionEficiencia
// -------------------------------------------------------------------------------------------------
// CONCEITO:
// O Insertion Sort funciona dividindo o vetor (logicamente) numa parte ordenada e noutra
	// desordenada[cite: 233]. A cada passo, ele pega o primeiro elemento da parte desordenada
	// e "puxa-o" para trás, inserindo-o na posição correta da parte ordenada[cite: 238, 239].
	// Funciona muito bem para listas pequenas ou quase ordenadas[cite: 260].
//
// FUNÇÕES PRINCIPAIS:
// - O laço externo (for i = 1 até N-1) seleciona a "chave" (o elemento atual).
// - O laço interno (while j >= 0 e vetor[j] > chave) é o motor do algoritmo: ele empurra
	//   os elementos maiores para a direita para abrir espaço para a chave[cite: 266].
//
// COMO ALTERAR NA PROVA:
// - Para ordem DECRESCENTE: Mude a condição do while de `vetor[j] > chave` para `vetor[j] < chave`.
// - Para contar operações (Eficiência): Crie uma variável `movimentos = 0`. Incremente-a
//   DENTRO do while, pois é lá que ocorrem os deslocamentos. O pior caso ocorre quando a
	//   lista está invertida [cite: 271][cite_start], resultando em T(N) = N(N-1)/2 movimentos[cite: 276].
// - Para parar antecipadamente: O Insertion Sort já para automaticamente de iterar no `while`
//   assim que encontra um elemento menor que a chave.
//
// -------------------------------------------------------------------------------------------------
// 2. SELECTION SORT (Ordenação por Seleção)
// Exercícios: SelectionSort, SelectionSort2
// -------------------------------------------------------------------------------------------------
// CONCEITO:
	// Baseia-se em procurar o menor valor do vetor e colocá-lo na primeira posição[cite: 30, 50].
	// Depois, procura o segundo menor e coloca-o na segunda posição, sucessivamente[cite: 30, 50].
// É um algoritmo que faz muitas comparações, mas poucas trocas de elementos na memória.
//
// FUNÇÕES PRINCIPAIS:
// - `selectionSort(int v[], int n)`: Usa dois laços `for`. O externo marca a posição atual que
//   estamos a preencher. O interno varre o resto do vetor para encontrar o "índice do menor".
// - `swap` (troca): Ocorre apenas no final do laço externo, se o menor não for o próprio elemento.
//
// COMO ALTERAR NA PROVA:
// - Para ordem DECRESCENTE: No laço interno, altere o `if (v[j] < v[indice_menor])`
//   para `if (v[j] > v[indice_maior])`. Procura-se o maior em vez do menor.
// - E se o professor pedir um Selection Sort ESTÁVEL? O Selection Sort nativo NÃO é estável
//   (ele pode trocar a ordem original de elementos iguais). Para o tornar estável numa prova,
//   em vez de trocar elementos fisicamente com `swap`, teria de "empurrar" todos os elementos
//   do `indice_menor` até `i` uma casa para a direita e inserir o menor na posição `i`.
//
// -------------------------------------------------------------------------------------------------
// 3. BUBBLE SORT (Ordenação Bolha - Char e String)
// Exercícios: OrdenacaoBubbleChar, OrdenacaoBubbleString
// -------------------------------------------------------------------------------------------------
// CONCEITO:
// Percorre o vetor repetidas vezes, comparando elementos adjacentes e trocando-os se
	// estiverem fora de ordem[cite: 162, 187]. A cada passagem, o maior elemento "flutua" 
// para o fim.
//
// FUNÇÕES PRINCIPAIS:
// - Laço duplo: O laço externo define quantas vezes vamos varrer. O laço interno faz as trocas.
//   Nota de otimização: O limite do laço interno diminui a cada rodada (`n - 1 - i`), porque 
//   os últimos `i` elementos já estão ordenados no fim do vetor.
// - `strcmp` e `strcpy`: Essenciais para o BubbleString. `strcmp(a, b) > 0` significa que
//   a string `a` vem depois da `b` na ordem alfabética.
//
// COMO ALTERAR NA PROVA:
// - Otimização com FLAG: O professor pode pedir a versão otimizada. Crie uma variável
//   `int houve_troca = 0;` no início do laço externo. Dentro do `if` da troca, faça
//   `houve_troca = 1;`. No final do laço externo, coloque `if (houve_troca == 0) break;`.
//   Isso faz o algoritmo parar imediatamente se o vetor já estiver ordenado.
// - Ordenação de Strings por TAMANHO (e não alfabeto): Troque o `strcmp(v[j], v[j+1])`
//   por `if (strlen(v[j]) > strlen(v[j+1]))`.
//
// -------------------------------------------------------------------------------------------------
// 4. ALGORITMOS DE INTERCALAÇÃO E MERGE SORT
// Exercícios: Intercala, Intercala2, Merge
// -------------------------------------------------------------------------------------------------
// CONCEITO:
// O Merge Sort usa a estratégia "Dividir para Conquistar". Ele divide o vetor até ter
// pedaços de tamanho 1 e, de seguida, intercala-os usando dois ponteiros (i e j) garantindo
// complexidade de tempo O(N log N). A função base de intercalar une vetores já ordenados
	// em tempo linear O(N)[cite: 70].
//
// FUNÇÕES PRINCIPAIS:
// - `merge(arr, l, m, r)`: Cria dois vetores temporários (esquerda e direita), copia os dados
//   e usa um `while(i < n1 && j < n2)` para comparar quem é menor, colocando no vetor original.
//   No final, possui mais dois `while` para copiar as "sobras" de quem não terminou.
// - `mergeSort`: Função recursiva. Acha o meio, chama-se a si mesma para a esquerda, depois
//   para a direita, e finalmente chama a função `merge` para juntar as metades.
	//   Para o BOCA, a impressão era feita ANTES da intercalação[cite: 114].
//
// COMO ALTERAR NA PROVA:
// - Intercala In-Place / Vetor Único: Como no Intercala2, se tiver de intercalar as metades de
	//   um único vetor `Vu` já alocado[cite: 95], use um único vetor auxiliar `Vaux` do tamanho
	//   total[cite: 96], faça o merge lá dentro e depois copie tudo de volta para `Vu`.
// - Merge Sort Decrescente: Na função `merge`, no momento de comparar L[i] e R[j], mude
//   `if (L[i] <= R[j])` para `if (L[i] >= R[j])`.
//
// -------------------------------------------------------------------------------------------------
// 5. ESTRUTURA HEAP (MaxHeap e MinHeap)
// Exercícios: MaxHeap, MinHeap
// -------------------------------------------------------------------------------------------------
// CONCEITO:
// Um Heap é uma árvore binária quase completa representada num vetor. Num Max Heap, o pai 
// é sempre maior ou igual aos filhos. Num Min Heap, o pai é sempre menor ou igual aos filhos.
//
// FUNÇÕES PRINCIPAIS E A PEGADINHA DA PROVA:
// - Índices: O pai de um índice `i` está em `(i - 1) / 2`. O filho da esquerda em `2*i + 1` 
//   e o da direita em `2*i + 2`.
// - `peneirar / heapify`: Afunda um nó que viola a propriedade do Heap.
//   ATENÇÃO MÁXIMA PARA A PROVA: O seu professor implementou a função `peneirar`
//   verificando PRIMEIRO o filho da DIREITA, e só depois o da ESQUERDA. Se esquecer
//   esta ordem num caso com elementos repetidos, a sua árvore terá um formato diferente
//   e o BOCA dará "Wrong Answer".
// - `buildHeap`: Vai do meio do vetor (`n/2 - 1`, ou seja, o último nó com filhos) até ao
//   índice 0, chamando `peneirar`.
//
// COMO ALTERAR NA PROVA:
// - Do MaxHeap para MinHeap: Dentro do `peneirar`, altere `h[fDir] > h[pai]` para 
//   `h[fDir] < h[pai]` (o menor assume o topo).
// - Fazer o "Heap Sort" completo: Se o professor pedir não apenas para construir o Heap, 
//   mas ordenar o vetor usando o Heap Sort:
//   1. Construa o Max Heap.
//   2. Faça um laço com `i` indo de `n-1` até 1.
//   3. Troque a raiz (maior elemento no índice 0) com o último elemento `i` (swap(v[0], v[i])).
//   4. Chame `peneirar(v, 0, i)` reduzindo o tamanho `i` a cada passo para restaurar o heap.
//
// -------------------------------------------------------------------------------------------------
// 6. PROBLEMAS COM COMPLEXIDADE E STRUCTS (qsort)
// Exercícios: Atendimento_Docente, PosicaoNoGrid, OrdenacaoMarciana
// -------------------------------------------------------------------------------------------------
// CONCEITO:
	// Quando o problema tem restrições gigantescas como N = 100.000[cite: 317], algoritmos como
// Insertion ou Bubble resultam em Time Limit Exceeded (TLE). A solução é usar a função `qsort`
// (Quick Sort) da biblioteca `<stdlib.h>` que possui eficiência O(N log N).
//
// FUNÇÕES PRINCIPAIS:
// - `qsort(vetor, tamanho, sizeof(TipoDoVetor), funcaoDeComparacao)`
// - `int comparar(const void *a, const void *b)`: É a alma do negócio. Deve devolver
//   um número negativo se `a` deve vir antes de `b`, positivo se `b` vem antes, e 0 se forem iguais.
//
// COMO RESOLVER OS DESAFIOS CLÁSSICOS DESTES EXERCÍCIOS:
// - Critérios Múltiplos e Estabilidade (Atendimento_Docente): O problema pedia para ordenar
	//   do maior tempo para o menor[cite: 134]. Em caso de empate, a prioridade era de quem
	//   chegou primeiro[cite: 153]. Como o `qsort` não é estável nativamente, a melhor técnica
//   foi criar um `int id_original` na struct do aluno, preenchido com o índice `i` no momento
//   da leitura do `scanf`. No `if` do desempate da função `comparar`, faz-se:
//   `return alunoA->id_original - alunoB->id_original;`.
// - Tempo que cruza a meia-noite: O professor indicou que um atendimento pode começar num dia
	//   e terminar no seguinte[cite: 152]. A tática é converter tudo para segundos. Se o
//   tempo final for menor que o inicial (duração negativa), soma-se as 24h em segundos:
//   `duracao += 24 * 3600;`.
// - Ordenação Marciana (Pesos arbitrários): Os marcianos utilizam a regra 
	//   0<5<6<4<8<9<7<3<1<2[cite: 335]. Se o professor inventar algo como "Ordenação Jupiteriana"
//   na prova, basta manter a lógica do vetor de conversão. Se ele disser que a letra 'Z' vale
//   menos que a letra 'A', crie uma função de tradução onde 'Z' mapeia para 1 e 'A' mapeia
//   para 26. Grave o "valor_traduzido" na struct e passe isso para o `qsort` comparar.
//
// -------------------------------------------------------------------------------------------------
// DICAS FINAIS PARA A PROVA:
// 1. Leia as restrições de N. Se N for até 1.000, você pode usar quase qualquer algoritmo (O(N^2)).
//    Se N for 100.000 ou mais, use O(N log N) (como `qsort` ou `Merge Sort`) senão terá TLE.
// 2. Se a entrada puder ser muito grande, evite "VLA" (`int vetor[n];`). Use `malloc` e `free`.
// 3. Presentation Errors são resolvidos controlando severamente os espaços e os `\n`. Em C,
//    gerir espaços finais faz-se perfeitamente com `printf("%d%s", v[i], i < n - 1 ? " " : "\n");`.
//
// Mantenha a calma! Você dominou a implementação na prática e sabe o porquê de cada
// linha de código estar lá. Boa prova!
// =================================================================================================