
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
	cout << "[2] - LISTAR: ORDENAR PELA IDADE DE FORMA CRESCENTE\n";
	cout << "[3] - LISTAR: ORDENAR PELA IDADE DE FORMA DECRESCENTE\n";
	cout << "[4] - LISTAR: ORDENAR PELO INDENTIFICADOR DE FORMA CRESCENTE\n";
	cout << "[5] - LISTAR: ORDENAR PELO INDENTIFICADOR DE FORMA DECRESCENTE\n";
	cout << "[6] - BUSCAR PELO NOME\n";
	cout << "[7] - BUSCAR POR INDENTIFICADOR\n";
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
		getchar();
		cout << "Digite o nome do paciente\n";
		gets(pacientes[quantidadePacientes].nome);
		//		while (cin.getline(pacientes[quantidadePacientes].nome,100))
		//		{ // Garante que o nome sera preenchido
		//			if (pacientes[quantidadePacientes].nome != "")
		//			{
		//				break;
		//			}
		//		}

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

		SalvarDados(quantidadePacientes);
	}
}

void SalvarDados(int &quantidadePacientes)
{
	FILE *arq, *qtd;

	arq = fopen("dados.bin", "wb"); // abre o arquivo para escrita
	qtd = fopen("qtd.bin", "wb");
	if (arq == NULL || qtd == NULL)
	{
		cout << "\nErro ao abrir o arquivo para leitura!\n";
		exit(1);
	}
	fwrite(pacientes, sizeof(Paciente), quantidadePacientes + 1, arq);
	fclose(arq);
	quantidadePacientes++;
	fwrite(&quantidadePacientes, sizeof(int), 1, qtd);
	fclose(qtd);
}

void CarregarDados(int &quantidadePacientes)
{ // funcao que lera o arquivo texto

	FILE *arq = fopen("dados.bin", "rb"); // abre o arquivo para leitura
	FILE *qtd = fopen("qtd.bin", "rb");
	if (arq == NULL || qtd == NULL)
	{
		cout << "\nErro ao abrir o arquivo para leitura!\n";

		exit(1); // aborta o programa
	}
	fread(&quantidadePacientes, sizeof(int), 1, qtd);

	// o la�o vai repetir ate chegara a 10 porque n�o se sabe o tamanho do vetor por isso ira pegar 1 de cada vez
	// Complexibilidade n
	for (int i = 0; i < quantidadePacientes; i++)
	{
		fread(&pacientes[i], sizeof(Paciente), 1, arq);
	}
	fclose(arq); // fecha o arquivo
	fclose(qtd);
	// cout << "Carregando " << quantidadePacientes << "\n";
	// for (int i = 0; i < quantidadePacientes; i++)
	// {
	// 	cout << i << "Mostrando i\n";
	// 	cout << "Nome: " << pacientes[i].nome << "\n";
	// 	cout << "Idade: " << pacientes[i].idade << "\n";
	// 	cout << "Indentificador: " << pacientes[i].indentificado << "\n";
	// }
}

int buscaIndentificador(float v[], int n)
{
	string nome;
	int ini = 0, fim = n - 1, meio;
	while
		{
			cout << "Digite o numero de identificacao do paciente\n";
			cin >> pacientes[quantidadePacientes].indentificado;
            meio = (ini+fim)/2
			if (quantidadePacientes == v[meio]) return meio
            if (quantidadePacientes < v[meio]) return fim = meio-1
			if (quantidadePacientes > v[meio]) return ini = meio+1
		}
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