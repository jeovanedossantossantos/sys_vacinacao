
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
	cout << "[8] - LISTAR: ORDENAR POR ORDEM ALFABETICA\n";
	cout << "[0] - SAIR DO SYSTEMA\n";

	cout << "================================================================\n";

	cin >> opcao;
	system("cls");

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
		cout << "================================================================\n";
		cout << "Paciente, cadastrado com sucesso\n";
		cout << "Nome: ------------" << pacientes[quantidadePacientes].nome << "\n";
		cout << "Idade: -----------" << pacientes[quantidadePacientes].idade << "\n";
		cout << "Indentificador: --" << pacientes[quantidadePacientes].indentificado << "\n";
		cout << "================================================================\n";

		SalvarDados(quantidadePacientes);
		system("pause");
		system("cls");
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
{ // funcao que ler o arquivo texto

	FILE *arq = fopen("dados.bin", "rb"); // abre o arquivo para leitura
	FILE *qtd = fopen("qtd.bin", "rb");
	if (arq == NULL || qtd == NULL)
	{
		cout << "\nErro ao abrir o arquivo para leitura!\n";

		exit(1); // aborta o programa
	}
	fread(&quantidadePacientes, sizeof(int), 1, qtd);

	// Complexibilidade n
	for (int i = 0; i < quantidadePacientes; i++)
	{
		fread(&pacientes[i], sizeof(Paciente), 1, arq);
	}
	fclose(arq); // fecha o arquivo
	fclose(qtd);
}

void Listar(int &quantidadePacientes, int tipo)
{

	cout << "================================================================\n";
	if (tipo == 2)
	{
		cout << "Listando por idade de forma crecente \n";

		MergeSort(pacientes, 0, quantidadePacientes - 1);
	}
	else if (tipo == 3)
	{
		QuickSort(pacientes, 0, quantidadePacientes - 1);
		cout << "       Listando por idade de forma Decrecente \n";
	}
	else if (tipo == 8)
	{
		QuickSortNome(pacientes, 0, quantidadePacientes - 1);
		cout << "       Listando por ordem alfabetica \n";
	}

	cout << "================================================================\n";
	for (int i = 0; i < quantidadePacientes; i++)
	{
		cout << "Nome: ------------- " << pacientes[i].nome << "\n";
		cout << "Idade: ------------ " << pacientes[i].idade << "\n";
		cout << "Indentificador: --- " << pacientes[i].indentificado << "\n";
		cout << "================================================================\n";
	}

	cout << "================================================================\n";
	system("pause");
	system("cls");
}

void MergeSort(Paciente pacientes[], int inicio, int fim)
{
	int meio;

	if (inicio < fim)
	{

		meio = (fim + inicio) / 2;

		MergeSort(pacientes, inicio, meio);
		MergeSort(pacientes, meio + 1, fim);
		Merge(pacientes, inicio, meio, fim);
	}
}
void Merge(Paciente pacientes[], int inicio, int meio, int fim)
{

	int i = inicio, j = meio + 1, k = 0;
	int juncao = fim - inicio + 1;
	Paciente temp[fim - inicio + 1];

	while (i <= meio && j <= fim)
	{
		if (pacientes[i].idade < pacientes[j].idade)
		{
			temp[k] = pacientes[i];
			i++;
		}
		else
		{
			temp[k] = pacientes[j];
			j++;
		}
		k++;
	}
	while (i <= meio)
	{
		temp[k] = pacientes[i];
		i++;
		k++;
	}

	while (j <= fim)
	{
		temp[k] = pacientes[j];
		j++;
		k++;
	}

	for (k = 0; k < juncao; k++)
	{
		pacientes[inicio + k] = temp[k];
	}
}

void QuickSort(Paciente pacientes[], int inicio, int fim)
{
	int p;

	if (inicio < fim)
	{
		p = Patition(pacientes, inicio, fim);
		QuickSort(pacientes, inicio, p - 1);
		QuickSort(pacientes, p + 1, fim);
	}
}
int Patition(Paciente pacientes[], int inicio, int fim)
{

	int pivot = pacientes[fim].idade;
	int i = inicio;
	Paciente paciente;

	for (int j = inicio; j < fim; j++)
	{
		if (pacientes[j].idade >= pivot)
		{
			paciente = pacientes[j];
			pacientes[j] = pacientes[i];
			pacientes[i] = paciente;
			i++;
		}
	}
	paciente = pacientes[fim];
	pacientes[fim] = pacientes[i];
	pacientes[i] = paciente;
	return i;
}

void QuickSortNome(Paciente pacientes[], int inicio, int fim)
{
	int p;

	if (inicio < fim)
	{
		p = PatitionNome(pacientes, inicio, fim);
		QuickSortNome(pacientes, inicio, p - 1);
		QuickSortNome(pacientes, p + 1, fim);
	}
}
int PatitionNome(Paciente pacientes[], int inicio, int fim)
{

	char *pivot = pacientes[fim].nome;
	int i = inicio;
	Paciente paciente;

	for (int j = inicio; j < fim; j++)
	{
		if (strcmp(pacientes[j].nome, pivot) < 0)
		{
			swap(pacientes[j], pacientes[i]);
			i++;
		}
	}
	swap(pacientes[fim], pacientes[i]);

	return i;
}
