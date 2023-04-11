#include <algorithm>
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

      break;
    case 3:
      cout << opcao;
      break;
    case 4:
      cout << opcao;
      break;
    case 5:
      cout << opcao;
      break;
    case 6:
       BuscarPeloNome(quantidadePacientes);
      break;
    default:
      cout << opcao;
    }

  } while (opcao != 0);

  return 0;
}
