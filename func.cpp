
#include "func.h"

using namespace std;

int menu()
{
    int opcao;
    cout << "================================================================\n";
    cout << "       SYSTEMA DE CADASTRO PARA A VACINACAO DO COVID19\n";
    cout << "================================================================\n";
    cout << "[1] - CADASTRA UM NOVO PACIENTE\n";
    cout << "[2] - LISTAR: ORDENAR PELA IDADE DE FORMA CRECENTE\n";
    cout << "[3] - LISTAR: ORDENAR PELA IDADE DEFORMA DECRECENTE\n";
    cout << "[4] - LISTAR: ORDENAR PELO INDENTIFICADOR DE FORMA CRECENTE\n";
    cout << "[5] - LISTAR: ORDENAR PELO INDENTIFICADOR DECRECENTE\n";
    cout << "[6] - BUSCAR PELO NOME\n";
    cout << "[7] - BUSCAR POR INDENTIFICADO\n";
    cout << "[0] - SAIR DO SYSTEMA\n";

    cout << "================================================================\n";

    cin >> opcao;

    return opcao;
}
