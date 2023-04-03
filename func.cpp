
#include "func.h"

Paciente pacientes[10];
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

void Cadastra(int &quantidadePacientes)
{
	int unique = 0;
	string nome;

	if (quantidadePacientes >= 10)
	{
		cout << "Quantidade maxima alcansada\n";
	}
	else
	{
		cout << "Digite o nome do paciente\n";
		while (getline(cin, pacientes[quantidadePacientes].nome))
		{ // Garante que o nome sera preenchido
			if (pacientes[quantidadePacientes].nome != "")
			{
				break;
			}
		}

		cout << "Digite a idade do paciente\n";
		cin >> pacientes[quantidadePacientes].idade;

		do
		{
			cout << "Digite o numero de identificacao do paciente\n";
			cin >> pacientes[quantidadePacientes].indentificado;

			if (quantidadePacientes > 0)
			{
				unique = 0;
				for (int i = 0; i < quantidadePacientes; i++)
				{
					if (pacientes[quantidadePacientes].indentificado == pacientes[i].indentificado)
					{
						unique = 1;
						cout << "Indetificador invalido, tente outro\n";
						break;
					}
				}
			}

		} while (unique != 0);
		cout << "Paciente, cadastrado com sucesso\n";
		cout << "Nome: " << pacientes[quantidadePacientes].nome << "\n";
		cout << "Idade: " << pacientes[quantidadePacientes].idade << "\n";
		cout << "Indentificador: " << pacientes[quantidadePacientes].indentificado << "\n";
		quantidadePacientes++;
		SalvarDados(quantidadePacientes);
	}
}

void SalvarDados(int &quantidadePacientes)
{
	int i, qtd = 0;
	FILE *arq;

	arq = fopen("dados.bin", "wb"); // abre o arquivo para escrita

	if (arq == NULL)
	{
		cout << "\nErro ao abrir o arquivo para leitura!\n";
		exit(1);
	}

	fwrite(pacientes, sizeof(Paciente), quantidadePacientes, arq);
	fclose(arq);
}