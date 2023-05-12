#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

void insertElement(std::vector<std::string>& list, std::string element) {
    list.push_back(element);
    std::cout << element << " inserido na lista." << std::endl;
}

void printList(const std::vector<std::string>& list) {
    std::cout << "Lista: ";
    for (const std::string& str : list) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

void removeList(std::vector<std::string>& list) {
    list.clear();
    std::cout << "Lista removida." << std::endl;
}

void removeInitialNode(std::vector<std::string>& list) {
    if (!list.empty()) {
        std::cout << "Elemento inicial removido: " << list.front() << std::endl;
        list.erase(list.begin());
    } else {
        std::cout << "Lista vazia." << std::endl;
    }
}

void removeFinalNode(std::vector<std::string>& list) {
    if (!list.empty()) {
        std::cout << "Elemento final removido: " << list.back() << std::endl;
        list.pop_back();
    } else {
        std::cout << "Lista vazia." << std::endl;
    }
}

bool compareStrings(const std::string& a, const std::string& b) {
    return a < b;
}

void sortList(std::vector<std::string>& list) {
    std::sort(list.begin(), list.end(), compareStrings);
    std::cout << "Lista ordenada por ordem alfabética." << std::endl;
}

int main() {
    std::vector<std::string> L1;
    std::vector<std::string> L2;
    std::string element;
    int opcao;

    while (true) {
        std::cout << "Escolha uma opção:" << std::endl;
        std::cout << "1. Inserir na Lista 1" << std::endl;
        std::cout << "2. Inserir na Lista 2" << std::endl;
        std::cout << "3. Deletar Lista 1" << std::endl;
        std::cout << "4. Deletar Lista 2" << std::endl;
        std::cout << "5. Mostrar Lista 1" << std::endl;
        std::cout << "6. Mostrar Lista 2" << std::endl;
        std::cout << "7. Remover Nó ou Elemento Inicial da Lista 1" << std::endl;
        std::cout << "8. Remover Nó ou Elemento Inicial da Lista 2" << std::endl;
        std::cout << "9. Remover Nó ou Elemento Final da Lista 1" << std::endl;
        std::cout << "10. Remover Nó ou Elemento Inicial da Lista 2" << std::endl;
        std::cout << "11. Ordenar Lista 1" << std::endl;
        std::cout << "12. Ordenar Lista 2" << std::endl;
        std::cout << "13. Sair" << std::endl;
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                                std::cout << "Digite as strings para inserir na Lista 1 (digite '0' para encerrar):\n";
                while (true) {
                    std::cout << "Digite uma string: ";
                    std::cin >> element;
                    if (element == "0") {
                        break;
                    }
                    insertElement(L1, element);
                }
                std::cout << "Lista 1 atual: ";
                printList(L1);
                break;
            case 2:
                std::cout << "Digite as strings para inserir na Lista 2 (digite '0' para encerrar):\n";
                while (true) {
                    std::cout << "Digite uma string: ";
                    std::cin >> element;
                    if (element == "0") {
                        break;
                    }
                    insertElement(L2, element);
                }
                std::cout << "Lista 2 atual: ";
                printList(L2);
                break;
            case 3:
                removeList(L1);
                break;
            case 4:
                removeList(L2);
                break;
            case 5:
                printList(L1);
                break;
            case 6:
                printList(L2);
                break;
            case 7:
                removeInitialNode(L1);
                break;
            case 8:
                removeInitialNode(L2);
                break;
            case 9:
                removeFinalNode(L1);
                break;
            case 10:
                removeFinalNode(L2);
                break;
            case 11:
                sortList(L1);
                break;
            case 12:
                sortList(L2);
                break;
            case 13:
                removeList(L1);
                removeList(L2);
                std::cout << "Programa encerrado." << std::endl;
                return 0;
            default:
                std::cout << "Opção inválida!" << std::endl;
                break;
        }
    }
}

