#include <iostream>
#include "func.cpp"
using namespace std;

int main()
{

  int opcao;
  int quantidadePacientes = 0;
  


  do
  {
    CarregarDados(quantidadePacientes);
    opcao = menu();

    switch (opcao)
    {
    case 1:
      Cadastra(quantidadePacientes);
      break;
    case 2:
      Listar(quantidadePacientes, 2);
      break;
    case 3:
      Listar(quantidadePacientes, 3);
      break;
    case 4:
      listarQuickCrescente(pacientes, quantidadePacientes);
      break;
    case 5:
     Listar(quantidadePacientes, 5);
      break;
    case 6:
      cout << opcao;
      break;
    case 7:
      cout << opcao;
      break;
    case 8:
      Listar(quantidadePacientes, 8);
      break;
    default:
      cout << opcao;
    }

  } while (opcao != 0);

  return 0;
}
