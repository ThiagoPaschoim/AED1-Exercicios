/* =================================================================================================
 * ÁRVORE BINÁRIA DE BUSCA [1]
 * =================================================================================================
 * ENUNCIADO:
 * Faça um programa que implemente uma Árvore Binária de Busca conforme o padrão de entrada a seguir:
 *
 * RESTRIÇÕES:
 * - valor será um número inteiro.
 * - Caso a operação tente incluir um valor que já existe na árvore, inclua-o na sub-árvore 
 * DIREITA do nó com a mesma chave.
 * - Caso a operação tente excluir um valor inexistente na árvore, ignore a operação.
 * - Caso a operação de exclusão seja em um valor com várias ocorrências, exclua a que aparecer 
 * primeiro, ou seja, aquela de nível mais próximo da raiz, ou ainda aquela que estiver a uma 
 * maior altura na árvore.
 * - Caso a operação de exclusão recaia sobre um nó com dois filhos, eleja como substituto o SUCESSOR.
 * - A cada operação de exclusão bem sucedida mostre o valor na tela e salte uma linha.
 *
 * EXEMPLO EXATO (UM POR LINHA):
 *
 * ENTRADA          SAÍDA
 * insert 77        77
 * insert 70        70
 * insert 83        67
 * insert 67        73
 * insert 73        83
 * insert 80        80
 * insert 87        87
 * pre-order        65
 * insert 65        67
 * insert 90        70
 * insert 78        73
 * in-order         77
 * delete 80        78
 * delete 77        80
 * post-order       83
 * delete 67        87
 * delete 73        90
 * delete 80        80
 * in-order         77
 * delete 87        65
 * delete 78        67
 * post-order       73
 * 70
 * 90
 * 87
 * 83
 * 78
 * 67
 * 73
 * 65
 * 70
 * 78
 * 83
 * 87
 * 90
 * 87
 * 78
 * 65
 * 70
 * 90
 * 83
 * =================================================================================================
 */

/* =================================================================================================
 * ÁRVORE BINÁRIA DE BUSCA [2]
 * =================================================================================================
 * ENUNCIADO:
 * Faça um programa que implemente uma Árvore Binária de Busca conforme o padrão de entrada a seguir:
 *
 * RESTRIÇÕES:
 * - valor será um número inteiro.
 * - Caso a operação tente incluir um valor que já existe na árvore, inclua-o na sub-árvore 
 * DIREITA do nó com a mesma chave.
 * - Caso a operação tente excluir um valor inexistente na árvore, ignore a operação.
 * - Caso a operação de exclusão seja em um valor com várias ocorrências, exclua a que aparecer 
 * primeiro (nível mais próximo da raiz).
 * - Caso a operação de exclusão recaia sobre um nó com dois filhos, eleja como substituto o SUCESSOR.
 * - A cada operação de exclusão bem sucedida mostre o valor na tela e salte uma linha.
 * - Impressão: Mostra os itens da árvore nos percursos SEPARADOS POR ESPAÇO EM BRANCO CADA. 
 * Após a impressão do último item, salte uma linha.
 *
 * EXEMPLO EXATO (SEPARADOS POR ESPAÇO):
 *
 * ENTRADA          SAÍDA
 * insert 77        77 70 67 73 83 80 87
 * insert 70        65 67 70 73 77 78 80 83 87 90
 * insert 83        80
 * insert 67        77
 * insert 73        65 67 73 70 90 87 83 78
 * insert 80        67
 * insert 87        73
 * pre-order        65 70 78 83 87 90
 * insert 65        87
 * insert 90        78
 * insert 78        65 70 90 83
 * in-order
 * delete 80
 * delete 77
 * post-order
 * delete 67
 * delete 73
 * delete 80
 * in-order
 * delete 87
 * delete 78
 * post-order
 * =================================================================================================
 */

/* =================================================================================================
 * ÁRVORE BINÁRIA DE BUSCA [3]
 * =================================================================================================
 * ENUNCIADO:
 * Faça um programa que implemente uma Árvore Binária de Busca conforme o padrão de entrada a seguir:
 *
 * RESTRIÇÕES:
 * - valor será um número inteiro.
 * - Caso a operação tente incluir um valor que já existe na árvore, inclua-o na sub-árvore 
 * DIREITA do nó com a mesma chave.
 * - Caso a operação tente excluir um valor inexistente na árvore, ignore a operação.
 * - Caso a operação de exclusão seja em um valor com várias ocorrências, exclua a primeira (mais alta).
 * - Caso a operação de exclusão recaia sobre um nó com dois filhos, eleja como substituto o ANTECESSOR.
 * - A cada operação de exclusão bem sucedida mostre o valor na tela e salte uma linha.
 * - Impressão: Mostra os itens da árvore nos percursos, UM POR LINHA.
 *
 * EXEMPLO EXATO (UM POR LINHA - MUDA O POST-ORDER DEVIDO AO ANTECESSOR):
 *
 * ENTRADA          SAÍDA
 * insert 77        77
 * insert 70        70
 * insert 83        67
 * insert 67        73
 * insert 73        83
 * insert 80        80
 * insert 87        87
 * pre-order        65
 * insert 65        67
 * insert 90        70
 * insert 78        73
 * in-order         77
 * delete 80        78
 * delete 77        80
 * post-order       83
 * delete 67        87
 * delete 73        90
 * delete 80        80
 * in-order         77
 * delete 87        65
 * delete 78        67
 * post-order       70
 * 78
 * 90
 * 87
 * 83
 * 73
 * 67
 * 73
 * 65
 * 70
 * 78
 * 83
 * 87
 * 90
 * 87
 * 78
 * 65
 * 90
 * 83
 * 70
 * =================================================================================================
 */

/* =================================================================================================
 * ÁRVORE BINÁRIA DE BUSCA [4]
 * =================================================================================================
 * ENUNCIADO:
 * Faça um programa que implemente uma Árvore Binária de Busca conforme o padrão de entrada a seguir:
 *
 * RESTRIÇÕES:
 * - valor será um número inteiro.
 * - Caso a operação tente incluir um valor que já existe na árvore, inclua-o na sub-árvore 
 * DIREITA do nó com a mesma chave.
 * - Caso a operação tente excluir um valor inexistente na árvore, ignore a operação.
 * - Caso a operação de exclusão seja em um valor com várias ocorrências, exclua a primeira (mais alta).
 * - Caso a operação de exclusão recaia sobre um nó com dois filhos, eleja como substituto o ANTECESSOR.
 * - A cada operação de exclusão bem sucedida mostre o valor na tela e salte uma linha.
 * - Impressão: Mostra os itens da árvore nos percursos SEPARADOS POR ESPAÇO EM BRANCO CADA.
 *
 * EXEMPLO EXATO (SEPARADOS POR ESPAÇO - MUDA O POST-ORDER DEVIDO AO ANTECESSOR):
 *
 * ENTRADA          SAÍDA
 * insert 77        77 70 67 73 83 80 87
 * insert 70        65 67 70 73 77 78 80 83 87 90
 * insert 83        80
 * insert 67        77
 * insert 73        65 67 70 78 90 87 83 73
 * insert 80        67
 * insert 87        73
 * pre-order        65 70 78 83 87 90
 * insert 65        87
 * insert 90        78
 * insert 78        65 90 83 70
 * in-order
 * delete 80
 * delete 77
 * post-order
 * delete 67
 * delete 73
 * delete 80
 * in-order
 * delete 87
 * delete 78
 * post-order
 * =================================================================================================
 */

/* =================================================================================================
 * ÁRVORE BINÁRIA DE BUSCA [5]
 * =================================================================================================
 * ENUNCIADO:
 * Faça um programa que implemente uma Árvore Binária de Busca conforme o padrão de entrada a seguir:
 *
 * RESTRIÇÕES:
 * - valor será um número inteiro.
 * - Caso a operação tente incluir um valor que já existe na árvore, inclua-o na sub-árvore 
 * ESQUERDA do nó com a mesma chave.
 * - Caso a operação tente excluir um valor inexistente na árvore, ignore a operação.
 * - Caso a operação de exclusão seja em um valor com várias ocorrências, exclua a primeira (mais alta).
 * - Caso a operação de exclusão recaia sobre um nó com dois filhos, eleja como substituto o SUCESSOR.
 * - A cada operação de exclusão bem sucedida mostre o valor na tela e salte uma linha.
 * - Impressão: Mostra os itens da árvore nos percursos, UM POR LINHA.
 *
 * EXEMPLO EXATO (UM POR LINHA - COMO NÃO HÁ REPETIDOS NA ENTRADA, A SAÍDA É IDÊNTICA À ARVORE 1):
 *
 * ENTRADA          SAÍDA
 * insert 77        77
 * insert 70        70
 * insert 83        67
 * insert 67        73
 * insert 73        83
 * insert 80        80
 * insert 87        87
 * pre-order        65
 * insert 65        67
 * insert 90        70
 * insert 78        73
 * in-order         77
 * delete 80        78
 * delete 77        80
 * post-order       83
 * delete 67        87
 * delete 73        90
 * delete 80        80
 * in-order         77
 * delete 87        65
 * delete 78        67
 * post-order       73
 * 70
 * 90
 * 87
 * 83
 * 78
 * 67
 * 73
 * 65
 * 70
 * 78
 * 83
 * 87
 * 90
 * 87
 * 78
 * 65
 * 70
 * 90
 * 83
 * =================================================================================================
 */

/* =================================================================================================
 * ÁRVORE BINÁRIA DE BUSCA [6]
 * =================================================================================================
 * ENUNCIADO:
 * Faça um programa que implemente uma Árvore Binária de Busca conforme o padrão de entrada a seguir:
 *
 * RESTRIÇÕES:
 * - valor será um número inteiro.
 * - Caso a operação tente incluir um valor que já existe na árvore, inclua-o na sub-árvore 
 * ESQUERDA do nó com a mesma chave.
 * - Caso a operação tente excluir um valor inexistente na árvore, ignore a operação.
 * - Caso a operação de exclusão seja em um valor com várias ocorrências, exclua a primeira (mais alta).
 * - Caso a operação de exclusão recaia sobre um nó com dois filhos, eleja como substituto o SUCESSOR.
 * - A cada operação de exclusão bem sucedida mostre o valor na tela e salte uma linha.
 * - Impressão: Mostra os itens da árvore nos percursos SEPARADOS POR ESPAÇO EM BRANCO CADA.
 *
 * EXEMPLO EXATO (SEPARADOS POR ESPAÇO - COMO NÃO HÁ REPETIDOS, A SAÍDA É IDÊNTICA À ARVORE 2):
 *
 * ENTRADA          SAÍDA
 * insert 77        77 70 67 73 83 80 87
 * insert 70        65 67 70 73 77 78 80 83 87 90
 * insert 83        80
 * insert 67        77
 * insert 73        65 67 73 70 90 87 83 78
 * insert 80        67
 * insert 87        73
 * pre-order        65 70 78 83 87 90
 * insert 65        87
 * insert 90        78
 * insert 78        65 70 90 83
 * in-order
 * delete 80
 * delete 77
 * post-order
 * delete 67
 * delete 73
 * delete 80
 * in-order
 * delete 87
 * delete 78
 * post-order
 * =================================================================================================
 */

/* =================================================================================================
 * ÁRVORE BINÁRIA DE BUSCA [7]
 * =================================================================================================
 * ENUNCIADO:
 * Faça um programa que implemente uma Árvore Binária de Busca conforme o padrão de entrada a seguir:
 *
 * RESTRIÇÕES:
 * - valor será um número inteiro.
 * - Caso a operação tente incluir um valor que já existe na árvore, inclua-o na sub-árvore 
 * ESQUERDA do nó com a mesma chave.
 * - Caso a operação tente excluir um valor inexistente na árvore, ignore a operação.
 * - Caso a operação de exclusão seja em um valor com várias ocorrências, exclua a primeira (mais alta).
 * - Caso a operação de exclusão recaia sobre um nó com dois filhos, eleja como substituto o ANTECESSOR.
 * - A cada operação de exclusão bem sucedida mostre o valor na tela e salte uma linha.
 * - Impressão: Mostra os itens da árvore nos percursos, UM POR LINHA.
 *
 * EXEMPLO EXATO (UM POR LINHA - COMO NÃO HÁ REPETIDOS, A SAÍDA É IDÊNTICA À ARVORE 3):
 *
 * ENTRADA          SAÍDA
 * insert 77        77
 * insert 70        70
 * insert 83        67
 * insert 67        73
 * insert 73        83
 * insert 80        80
 * insert 87        87
 * pre-order        65
 * insert 65        67
 * insert 90        70
 * insert 78        73
 * in-order         77
 * delete 80        78
 * delete 77        80
 * post-order       83
 * delete 67        87
 * delete 73        90
 * delete 80        80
 * in-order         77
 * delete 87        65
 * delete 78        67
 * post-order       70
 * 78
 * 90
 * 87
 * 83
 * 73
 * 67
 * 73
 * 65
 * 70
 * 78
 * 83
 * 87
 * 90
 * 87
 * 78
 * 65
 * 90
 * 83
 * 70
 * =================================================================================================
 */

/* =================================================================================================
 * ÁRVORE BINÁRIA DE BUSCA [8]
 * =================================================================================================
 * ENUNCIADO:
 * Faça um programa que implemente uma Árvore Binária de Busca conforme o padrão de entrada a seguir:
 *
 * RESTRIÇÕES:
 * - valor será um número inteiro.
 * - Caso a operação tente incluir um valor que já existe na árvore, inclua-o na sub-árvore 
 * ESQUERDA do nó com a mesma chave.
 * - Caso a operação tente excluir um valor inexistente na árvore, ignore a operação.
 * - Caso a operação de exclusão seja em um valor com várias ocorrências, exclua a primeira (mais alta).
 * - Caso a operação de exclusão recaia sobre um nó com dois filhos, eleja como substituto o ANTECESSOR.
 * - A cada operação de exclusão bem sucedida mostre o valor na tela e salte uma linha.
 * - Impressão: Mostra os itens da árvore nos percursos SEPARADOS POR ESPAÇO EM BRANCO CADA.
 *
 * EXEMPLO EXATO (SEPARADOS POR ESPAÇO - COMO NÃO HÁ REPETIDOS, A SAÍDA É IDÊNTICA À ARVORE 4):
 *
 * ENTRADA          SAÍDA
 * insert 77        77 70 67 73 83 80 87
 * insert 70        65 67 70 73 77 78 80 83 87 90
 * insert 83        80
 * insert 67        77
 * insert 73        65 67 70 78 90 87 83 73
 * insert 80        67
 * insert 87        73
 * pre-order        65 70 78 83 87 90
 * insert 65        87
 * insert 90        78
 * insert 78        65 90 83 70
 * in-order
 * delete 80
 * delete 77
 * post-order
 * delete 67
 * delete 73
 * delete 80
 * in-order
 * delete 87
 * delete 78
 * post-order
 * =================================================================================================
 */