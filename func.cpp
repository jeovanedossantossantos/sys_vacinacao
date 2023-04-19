#include <iostream>
#include <string>
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
		strcpy(pacientes[quantidadePacientes].nome, strupr(pacientes[quantidadePacientes].nome));
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

int BuscarPeloNome(int &quantidadePacientes)
{
	char nomeBuscado[254];

	cout << "Digite o nome que deseja buscar: ";
	getchar();
	// getline(cin, nomeBuscado);
	gets(nomeBuscado);
	strcpy(nomeBuscado, strupr(nomeBuscado));

	// Ordena o vetor de pacientes pelo nome
	// sort(pacientes, pacientes + quantidadePacientes, [](Paciente p1, Paciente p2)
	// 	 { return p1.nome < p2.nome; });
	QuickSortNome(pacientes, 0, quantidadePacientes - 1);

	int inicio = 0, fim = quantidadePacientes - 1, meio;
	

	while (inicio <= fim)
	{
		meio = (inicio + fim) / 2;

		if (strcmp(nomeBuscado, pacientes[meio].nome) == 0)
		{

			return meio;
		}
		else if (strcmp(pacientes[meio].nome, nomeBuscado) < 0)
		{
			inicio = meio + 1;
		}
		else
		{
			fim = meio - 1;
		}
	}
	return -1;
}

void Listar(int &quantidadePacientes, int tipo)
{

	cout << "================================================================\n";
	if (quantidadePacientes == 0)
	{
		cout << "Nenhum paciente cadastrado\n";
		return;
	}
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
	else if (tipo == 4)
	{
		quicksortCrescente(pacientes, 0, quantidadePacientes - 1);
		cout << "       Listando por identificador de forma Crescente \n";
	}
	else if (tipo == 5)
	{
		cout << "       Listando por Indentificador de forma Decrecente \n";
		MergeSortIndendificado(pacientes, 0, quantidadePacientes - 1, quantidadePacientes);
	}
	else if (tipo == 6)
	{
		int pos = BuscarPeloNome(quantidadePacientes);
		if (pos > -1)
		{
			cout << "Paciente encontrado:\n";
			cout << "Nome: ------------- " << pacientes[pos].nome << "\n";
			cout << "Idade: ------------ " << pacientes[pos].idade << "\n";
			cout << "Indentificador: --- " << pacientes[pos].indentificado << "\n";
			return;
		}
		cout << "Paciente nao encontrado...\n";
		return;
	}
	else if(tipo==7){
		
		int pos = buscaIndentificador(quantidadePacientes);
		if (pos > -1)
		{
			cout << "Paciente encontrado:\n";
			cout << "Nome: ------------- " << pacientes[pos].nome << "\n";
			cout << "Idade: ------------ " << pacientes[pos].idade << "\n";
			cout << "Indentificador: --- " << pacientes[pos].indentificado << "\n";
			return;
		}
		cout << "Paciente nao encontrado...\n";
		return;
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

//A complexibilidade do algoritmo MergeSort O(n log n), n = números de elementos a serem ordenados
//A complexibilidade de espaço dessa função é O(n), n = tamanhos de subvetores a serem mesclados
// Função para fazer a fusão de duas sub-arrays ordenadas em um único array
void MergeIndentificador(Paciente v[], int a, int b, int c)
{
	int x, y, z;
	int num_1 = b - a + 1;
	int num_2 = c - b;

	// Criação de arrays temporários A e R
	Paciente A[num_1], R[num_2];

	// Copia os elementos das duas sub-arrays para os arrays temporários A e R
	for (x = 0; x < num_1; x++)
		A[x] = v[a + x];
	for (y = 0; y < num_2; y++)
		R[y] = v[b + 1 + y];

	// Inicialização dos índices x, y e z para fazer a fusão
	x = 0; // Índice para a sub-array A
	y = 0; // Índice para a sub-array R
	z = a; // Índice para o array original z

	// Faz a fusão das duas sub-arrays em um único array em ordem decrescente
	while (x < num_1 && y < num_2)
	{
		if (A[x].indentificado >= R[y].indentificado)
		{				 // Compara o elemento da sub-array A com o elemento da sub-array R
			v[z] = A[x]; // O elemento da sub-array A é maior ou igual ao elemento da sub-array R
			x++;		 // Incrementa o índice da sub-array A
		}
		else
		{
			v[z] = R[y]; // O elemento da sub-array R é maior do que o elemento da sub-array A
			y++;		 // Incrementa o índice da sub-array R
		}
		z++; // Incrementa o índice do array original arr
	}

	// Copia os elementos restantes da sub-array A, se houver
	while (x < num_1)
	{
		v[z] = A[x];
		x++;
		z++;
	}

	// Copia os elementos restantes da sub-array R, se houver
	while (y < num_2)
	{
		v[z] = R[y];
		y++;
		z++;
	}
}

// Função para dividir o array em sub-arrays menores e chamar a função merge para fazer a fusão
void MergeSortIndendificado(Paciente v[], int a, int c, int n)
{
	if (a < c)
	{
		int b = a + (c - a) / 2;

		// Chama a função merge_sort para a sub-array esquerda
		MergeSortIndendificado(v, a, b, n);

		// Chama a função merge_sort para a sub-array direita
		MergeSortIndendificado(v, b + 1, c, n);

		// Faz a fusão das sub-arrays esquerda e direita
		MergeIndentificador(v, a, b, c);
	}
}

void quicksortCrescente(Paciente lista[], int inicio, int fim)
{
	// A complexidade de ordenação quicksort é O(n log n) no caso médio e O(n^2) no pior caso.
	if (inicio < fim)
	{
		// Escolhendo o último elemento como pivô
		int pivo = lista[fim].indentificado;
		int i = inicio - 1;

		// Particionando a lista em sub-listas menores
		for (int j = inicio; j < fim; j++)
		{
			if (lista[j].indentificado <= pivo)
			{
				i++;
				Paciente temp = lista[i];
				lista[i] = lista[j];
				lista[j] = temp;
			}
		}

		// Colocando o pivô em sua posição final
		Paciente temp = lista[i + 1];
		lista[i + 1] = lista[fim];
		lista[fim] = temp;

		// Chamando a função quicksort recursivamente para ordenar as sub-listas
		quicksortCrescente(lista, inicio, i);
		quicksortCrescente(lista, i + 2, fim);
	}
}
int buscaIndentificador(int &quantidadePacientes){
	int indentificador;
	cout << "Digite o numero de identificacao do paciente\n";
	cin >> indentificador;
	quicksortCrescente(pacientes, 0, quantidadePacientes - 1);
	int inicio = 0, fim = quantidadePacientes - 1, meio;
	
	
	while(inicio <= fim){
            meio = (inicio+fim)/2;
			if (indentificador == pacientes[meio].indentificado){ 
				return meio;
			}
            else if (indentificador < pacientes[meio].indentificado){  
				fim = meio-1;
			}
			else{  
				inicio = meio+1;
			}
		
	}
	return -1;
}