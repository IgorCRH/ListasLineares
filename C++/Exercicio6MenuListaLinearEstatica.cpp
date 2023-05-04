#include <iostream>
#include <cstdlib>

void insertElement(int** list, int* size, int element) {
    (*size)++;
    *list = (int*)realloc(*list, (*size) * sizeof(int));
    if (*list == nullptr) {
        std::cout << "Erro ao alocar memória." << std::endl;
        exit(1);
    }
    (*list)[(*size) - 1] = element;
    std::cout << element << " inserido na lista." << std::endl;
}

void printList(int* list, int size) {
    if (list == nullptr) {
        std::cout << "Erro ao acessar lista." << std::endl;
        exit(1);
    }
    std::cout << "Lista: ";
    for (int i = 0; i < size; i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

void removeList(int** list, int* size) {
    if (*list == nullptr) {
        std::cout << "Erro ao acessar lista." << std::endl;
        exit(1);
    } else {
        free(*list);
        *list = nullptr;
        *size = 0;
        std::cout << "Lista removida." << std::endl;
    }
}

void removeInitialNode(int** list, int* size) {
    if (*list == nullptr) {
        std::cout << "Erro ao acessar lista." << std::endl;
        exit(1);
    } else {
        for (int i = 0; i < (*size) - 1; i++) {
            (*list)[i] = (*list)[i + 1];
        }
        (*size)--;
        *list = (int*)realloc(*list, (*size) * sizeof(int));
        std::cout << "Elemento inicial removido." << std::endl;
    }
}

void removeFinalNode(int** list, int* size) {
    if (*list == nullptr) {
        std::cout << "Erro ao acessar lista." << std::endl;
        exit(1);
    } else {
        (*size)--;
        *list = (int*)realloc(*list, (*size) * sizeof(int));
        std::cout << "Elemento final removido." << std::endl;
    }
}

int main() {
    int* L1 = nullptr;
    int* L2 = nullptr;
    int sizeL1 = 0, sizeL2 = 0;
    int num;
    int opcao;

    while (true) {
        std::cout << "Escolha uma opcao:" << std::endl;
        std::cout << "1. Inserir na Lista 1" << std::endl;
        std::cout << "2. Inserir na Lista 2" << std::endl;
        std::cout << "3. Deletar Lista 1" << std::endl;
        std::cout << "4. Deletar Lista 2" << std::endl;
        std::cout << "5. Mostrar Lista 1" << std::endl;
        std::cout << "6. Mostrar Lista 2" << std::endl;
        std::cout << "7. Remover No ou Elemento Inicial da Lista 1" << std::endl;
        std::cout << "8. Remover No ou Elemento Inicial da Lista 2" << std::endl;
        std::cout << "9. Remover No ou Elemento Final da Lista 1" << std::endl;
        std::cout << "10. Remover No ou Elemento Final da Lista 2" << std::endl;
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Digite os numeros para inserir na Lista 1 (digite -1 para encerrar):" << std::endl;
                while (true) {
                    std::cout << "Digite um numero: ";
                    std::cin >> num;
                    if (num == -1) {
                        break;
                    }
                    insertElement(&L1, &sizeL1, num);
                }
                std::cout << "Lista 1 atual: ";
                printList(L1, sizeL1);
                break;
            case 2:
                std::cout << "Digite os numeros para inserir na Lista 2 (digite -1 para encerrar):" << std::endl;
                while (true) {
                    std::cout << "Digite um numero: ";
                    std::cin >> num;
                    if (num == -1) {
                        break;
                    }
                    insertElement(&L2, &sizeL2, num);
                }
                std::cout << "Lista 2 atual: ";
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
            default:
                std::cout << "Opcao invalida!" << std::endl;
                break;
        }
    }
}

