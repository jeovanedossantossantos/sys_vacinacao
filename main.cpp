#include <iostream>
#include "func.cpp"
using namespace std;

int main(){
	
  int opcao = 1;
  int quantidadePacientes=0;
  
  do{

    
    
	switch (opcao)
    {
    case 1:
      Cadastra(quantidadePacientes);
     
      break;
    case 2:
      cout << opcao;
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
      cout << opcao;
      break;
    default:
      cout << opcao;
    }
    
  }while(opcao !=0);

    return 0;
}
