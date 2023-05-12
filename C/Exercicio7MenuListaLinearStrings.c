#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Recebe a lista (ponteiro para um ponteiro de ponteiro de char), seu tamanho (um ponteiro para um inteiro)
e o elemento a ser inserido por argumento (ponteiro para um char).
*/
void insertElement(char*** list, int* size, char* element) {
    (*size)++; // Incrementa o tamanho da lista
    *list = (char**)realloc(*list, (*size) * sizeof(char*)); // Realoca a mem�ria dinamicamente para acomodar o novo tamanho
    if (*list == NULL) { // Tenta garantir que a realoca��o de mem�ria foi bem-sucedida
        printf("Erro ao alocar mem�ria.\n");
        exit(1);
    }
    (*list)[(*size) - 1] = strdup(element); // Faz uma c�pia alocada dinamicamente do novo elemento (element da main) e atribui ao �ltimo elemento da lista e garante que a lista armazene uma c�pia independente do elemento inserido
    printf("%s inserido na lista.\n", element);
}

void printList(char** list, int size) {
    if (list == NULL) {
        printf("Erro ao acessar lista.\n");
        exit(1);
    }
    printf("Lista: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", list[i]);
    }
    printf("\n");
}

void removeList(char*** list, int* size) {
    if (*list == NULL) {
        printf("Erro ao acessar lista.\n");
        exit(1);
    }
    for (int i = 0; i < *size; i++) { // Percorre a lista
        free((*list)[i]); // Libera a mem�ria alocada para todos os elementos da lista
    }
    free(*list); // Libera a mem�ria alocada para a lista
    *list = NULL;
    *size = 0; // Seta o tamanho para 0 novamente
    printf("Lista removida.\n");
}

void removeInitialNode(char*** list, int* size) {
    if (*list == NULL) {
        printf("Erro ao acessar lista.\n");
        exit(1);
    }
    if (*size > 0) { // Verifica se o tamanho da lista � maior que zero, ou seja, se a lista cont�m elementos.
        free((*list)[0]); // Libera mem�ria alocada para o primeiro elemento da lista, posi��o 0
        for (int i = 1; i < *size; i++) { // For percorre toda a lista, a partir da posi��o 1, visto que a 0 vai ser/ser� removida
            (*list)[i - 1] = (*list)[i]; // Desloca todos os elementos uma posi��o para tr�s, substituindo o elemento atual pelo pr�ximo elemento na lista.
        }
        (*size)--; // Decrementa o tamanho
        *list = (char**)realloc(*list, (*size) * sizeof(char*)); // Altera dinamicamente a aloca��o de mem�ria mem�ria da lista para acomodar o novo tamanho
        if (*list == NULL && *size > 0) {
            printf("Erro ao realocar mem�ria.\n");
            exit(1);
        }
        printf("Elemento inicial removido.\n");
    } else {
        printf("Lista vazia.\n");
    }
}

void removeFinalNode(char*** list, int* size) {
    if (*list == NULL) {
        printf("Erro ao acessar lista.\n");
        exit(1);
    }
    if (*size > 0) { // Verifica se o tamanho da lista � maior que zero, ou seja, se a lista cont�m elementos.
        free((*list)[(*size) - 1]); // Libera a mem�ria alocada para a string do �ltimo elemento da lista.
        (*size)--; // Decrementa o tamanho
        *list = (char**)realloc(*list, (*size) * sizeof(char*)); // Altera dinamicamente a aloca��o de mem�ria mem�ria da lista para acomodar o novo tamanho
        if (*list == NULL && *size > 0) {
            printf("Erro ao realocar mem�ria.\n");
            exit(1);
        }
        printf("Elemento final removido.\n");
    } else {
        printf("Lista vazia.\n");
    }
}

int compareStrings(const void* a, const void* b) { // Ponteiros a e b apontam para os elementos a serem comparados
    const char* str1 = *(const char**)a; // Ponteiros void s�o convertidos em ponteiros de char por meio do uso de *(const char**).
    const char* str2 = *(const char**)b; // Atribui-se esses ponteiros a str1 e str2 que s�o ponteiros de const char
    return strcmp(str1, str2); // strcmp compara as duas strings
    /** A fun��o CompareStrings retorna o valor de retorno do strcmp:
    Se o valor de retorno for menor que zero, isso indica que str1 vem antes de str2 em ordem alfab�tica.
    Se for maior que zero, isso indica que str1 vem depois de str2 em ordem alfab�tica.
    Se for igual a zero, isso indica que str1 e str2 s�o consideradas iguais em termos de ordem alfab�tica.
    */
}

void sortList(char*** list, int size) { // Recebe a lista de strings e seu tamanho como argumentos, a partir da main
    if (*list == NULL) { // Verifica se a lista � nula ou n�o tem elementos
        printf("Erro ao acessar lista.\n");
        exit(1);
    }
    // Utiliza a fun��o qsort para ordenar a lista de strings em ordem alfab�tica
    qsort(*list, size, sizeof(char*), compareStrings); // Recebe como argumentos a lista, seu tamanho, o tamanho de cada elemento da lista, e a fun��o CompareStrings como crit�rio de compara��o durante a ordena��o
    printf("Lista ordenada por ordem alfab�tica.\n");
}

int main() {
char** L1 = NULL;
char** L2 = NULL;
int sizeL1 = 0, sizeL2 = 0;
char element[100];
int opcao;

while (1) {
    printf("Escolha uma op��o:\n");
    printf("1. Inserir na Lista 1\n");
    printf("2. Inserir na Lista 2\n");
    printf("3. Deletar Lista 1\n");
    printf("4. Deletar Lista 2\n");
    printf("5. Mostrar Lista 1\n");
    printf("6. Mostrar Lista 2\n");
    printf("7. Remover N� ou Elemento Inicial da Lista 1\n");
    printf("8. Remover N� ou Elemento Inicial da Lista 2\n");
    printf("9. Remover N� ou Elemento Final da Lista 1\n");
    printf("10. Remover N� ou Elemento Inicial da Lista 2\n");
    printf("11. Ordenar Lista 1\n");
    printf("12. Ordenar Lista 2\n");
    printf("13. Sair\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite as strings para inserir na Lista 1 (digite '0' para encerrar):\n");
            while (1) {
                printf("Digite uma string: ");
                scanf("%s", element);
                if (strcmp(element, "0") == 0) {
                    break;
                }
                insertElement(&L1, &sizeL1, element);
            }
            printf("Lista 1 atual: ");
            printList(L1, sizeL1);
            break;
        case 2:
            printf("Digite as strings para inserir na Lista 2 (digite '0' para encerrar):\n");
            while (1) {
                printf("Digite uma string: ");
                scanf("%s", element);
                if (strcmp(element, "0") == 0) {
                    break;
                }
                insertElement(&L2, &sizeL2, element);
            }
            printf("Lista 2 atual: ");
            printList(L2, sizeL2);
            break;
        case 3:
            removeList(&L1, &sizeL1);
            break;
        case 4:
            removeList(&L2, &sizeL2);
            break;
        case 5:
            printList(L1, sizeL1);
            break;
        case 6:
            printList(L2, sizeL2);
            break;
        case 7:
            removeInitialNode(&L1, &sizeL1);
            break;
        case 8:
            removeInitialNode(&L2, &sizeL2);
            break;
        case 9:
            removeFinalNode(&L1, &sizeL1);
            break;
        case 10:
            removeFinalNode(&L2, &sizeL2);
            break;
        case 11:
            sortList(&L1, sizeL1);
            break;
        case 12:
            sortList(&L2, sizeL2);
            break;
        case 13:
            removeList(&L1, &sizeL1);
            removeList(&L2, &sizeL2);
            printf("Programa encerrado.\n");
            return 0;
        default:
            printf("Op��o inv�lida!\n");
            break;
    }
}
}
