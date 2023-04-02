#include "func.h"


Paciente pacientes[10];
using namespace std;
void Cadastra(int  &quantidadePacientes){
	int unique = 0;
	string nome;
	
	if(quantidadePacientes>=10){
		cout << "Quantidade maxima alcansada\n";
		
	}else{
		cout << "Digite o nome do paciente\n";
		while(getline(cin, pacientes[quantidadePacientes].nome)){ //Garante que o nome sera preenchido
				if(pacientes[quantidadePacientes].nome != ""){
	 			break;
			}
		}	 
		
		cout << "Digite a idade do paciente\n";
		cin >> pacientes[quantidadePacientes].idade;
		
		do{
			cout << "Digite o numero de identificacao do paciente\n";
			cin >> pacientes[quantidadePacientes].indentificado;
			
			if(quantidadePacientes > 0){
				unique=0;
				for(int i=0; i<quantidadePacientes; i++){
					if(pacientes[quantidadePacientes].indentificado == pacientes[i].indentificado){
						unique=1;
						cout << "Indetificador invalido, tente outro\n";
						break;
					}
				}
			}
			
		}while(unique !=0);
		cout << "Paciente, cadastrado com sucesso\n";
		cout <<pacientes[quantidadePacientes].nome << "\n";
		cout <<pacientes[quantidadePacientes].idade << "\n";
		cout <<pacientes[quantidadePacientes].indentificado << "\n";
		quantidadePacientes++;
		
		
		
	}
	
}
