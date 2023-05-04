#include <stdio.h>
#include <stdlib.h>

// Passa o endereço do ponteiro do parâmetro da lista e para realocar memória para aumentar o tamanho da lista dinamicamente
void insertElement(int** list, int* size, int element) {
// Aumentar o tamanho da lista em 1
(*size)++;
// Realocar memória para o novo tamanho da lista (tamanho dinâmico)
*list = (int*)realloc(*list, (*size) * sizeof(int));
if (*list == NULL) {
printf("Erro ao alocar memória.\n");
exit(1);
}
// Inserir o elemento no final da lista
(*list)[(*size) - 1] = element;
printf("%d inserido na lista.\n", element);
}

// Ponteiro para int do parâmetro list para acessar os elementos da lista
void printList(int *list, int size){
if (
    list == NULL) {
printf("Erro ao acessar lista.\n");
exit(1);
}
printf("Lista: ");
for (int i=0;i < size;i++){
printf(",%d",list[i]);
}
}

// Passa o endereço do ponteiro do parâmetro da lista para remover os elementos e a lista
void removeList(int** list, int* size){
if (*list == NULL) { // Se a lista não tiver elementos
printf("Erro ao acessar lista.\n");
exit(1);
} else {
free(*list); // Libera a memória dos elementos e da lista
*size = 0; // Determina o tamanho da lista para 0
printf("Lista removida.\n");
}
}

void removeInitialNode(int** list, int* size){
if (*list == NULL) { // Se a lista não tiver elementos
printf("Erro ao acessar lista.\n");
exit(1);
} else {
for (int i= 0;i<(*size);i++){ // For da posição inicial até o tamanho da lista pelo ponteiro int size
(*list)[i] = (*list)[i+1]; // Dentro do ponteiro list, move todos os elementos uma posição para trás, deslizando a lista para a esquerda para ocupar a posição do elemento que será retirado
}
(*size)--; // Redimensiona o tamanho da lista para ter menos um elemento
*list = (int*)realloc(*list, (*size) * sizeof(int)); // Realoca a memoria com a mudância do tamanho dinâmico da lista
printf("Elemento inicial removido.\n");
}
}

void removeFinalNode(int** list, int* size){
if (*list == NULL) { // Se a lista não tiver elementos
printf("Erro ao acessar lista.\n");
exit(1);
} else {
(*size)--; // Redimensiona o tamanho da lista para ter menos um elemento, desta vez não precisa ser feito reordenação da lista, apenas o decremento
*list = (int*)realloc(*list, (*size) * sizeof(int)); // Realoca a memoria com a mudância do tamanho dinâmico da lista
printf("Elemento final removido.\n");
}
}

int main() {
    int* L1 = NULL;
    int* L2 = NULL;
    int sizeL1 = 0, sizeL2 = 0;
    int num;
    int opcao;

    while (1) {
        printf("Escolha uma opcao:\n");
        printf("1. Inserir na Lista 1\n");
        printf("2. Inserir na Lista 2\n");
        printf("3. Deletar Lista 1\n");
        printf("4. Deletar Lista 2\n");
        printf("5. Mostrar Lista 1\n");
        printf("6. Mostrar Lista 2\n");
        printf("7. Remover No ou Elemento Inicial da Lista 1\n");
        printf("8. Remover No ou Elemento Inicial da Lista 2\n");
        printf("9. Remover No ou Elemento Final da Lista 1\n");
        printf("10. Remover No ou Elemento Inicial da Lista 2\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite os numeros para inserir na Lista 1 (digite -1 para encerrar):\n");
                while (1) {
                    printf("Digite um numero: ");
                    scanf("%d", &num);
                    if (num == -1) {
                        break;
                    }
                    insertElement(&L1, &sizeL1, num);
                }
                printf("Lista 1 atual: ");
                printList(L1,sizeL1);
                break;
            case 2:
                printf("Digite os numeros para inserir na Lista 2 (digite -1 para encerrar):\n");
                while (1) {
                    printf("Digite um numero: ");
                    scanf("%d", &num);
                    if (num == -1) {
                        break;
                    }
                    insertElement(&L2, &sizeL2, num);
                }
                printf("Lista 2 atual: ");
                printList(L2,sizeL2);
                break;
            case 3:
                removeList(&L1,&sizeL1);
                break;
            case 4:
                removeList(&L2,&sizeL2);
                break;
            case 5:
                printList(L1,sizeL1);
                break;
            case 6:
                printList(L2,sizeL2);
                break;
            case 7:
                removeInitialNode(&L1,&sizeL1);
                break;
            case 8:
                removeInitialNode(&L2,&sizeL2);
                break;
            case 9:
                removeFinalNode(&L1,&sizeL1);
                break;
            case 10:
                removeFinalNode(&L2,&sizeL2);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}
