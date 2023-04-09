
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

// Função para fazer a fusão de duas sub-arrays ordenadas em um único array
void merge(Paciente v[], int a, int b, int c) {
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
    while (x < num_1 && y < num_2) {
        if (A[x].indentificado >= R[y].indentificado) { // Compara o elemento da sub-array A com o elemento da sub-array R
            v[z] = A[x]; // O elemento da sub-array A é maior ou igual ao elemento da sub-array R
            x++; // Incrementa o índice da sub-array A
        }
        else {
            v[z] = R[y]; // O elemento da sub-array R é maior do que o elemento da sub-array A
            y++; // Incrementa o índice da sub-array R
        }
        z++; // Incrementa o índice do array original arr
    }

    // Copia os elementos restantes da sub-array A, se houver
    while (x < num_1) {
        v[z] = A[x];
        x++;
        z++;
    }

    // Copia os elementos restantes da sub-array R, se houver
    while (y < num_2) {
        v[z] = R[y];
        y++;
        z++;
    }
}

// Função para dividir o array em sub-arrays menores e chamar a função merge para fazer a fusão
void merge_sort(Paciente v[], int a, int c, int n) {
    if (a < c) {
        int b = a + (c - a) / 2;

        // Chama a função merge_sort para a sub-array esquerda
        merge_sort(v, a, b, n);

        // Chama a função merge_sort para a sub-array direita
        merge_sort(v, b + 1, c, n);

        // Faz a fusão das sub-arrays esquerda e direita
        merge(v, a, b, c);
    }
}


void merge_imprimir(int &quantidadePacientes){
	// Chama a função merge_sort para ordenar o array de idades em ordem decrescente
    merge_sort(pacientes[], 0, quantidadePacientes - 1, quantidadePacientes);

    // Imprime o array ordenado em ordem decrescente

    for (int i = 0; i < quantidadePacientes; i++) {
        cout << pacientes[i] << " ";
    }
}
