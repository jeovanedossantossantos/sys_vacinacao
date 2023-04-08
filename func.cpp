
#include <string>
#include "func.h"

Paciente pacientes[10];
using namespace std;


No* raiz = NULL;



No* Insere(No* raiz, Paciente paciente)
{
    // se a �rvore est� vazia, cria um novo n�
    if (raiz == NULL)
    {
        No* novoNo = new No;
        novoNo->paciente = paciente;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }

    // se o nome do paciente � menor que o nome da raiz, insere na sub�rvore esquerda
    if (string(paciente.nome) < string(raiz->paciente.nome))
    {
        raiz->esquerda = Insere(raiz->esquerda, paciente);
    }
    // se o nome do paciente � maior que o nome da raiz, insere na sub�rvore direita
    else if (string(paciente.nome) > string(raiz->paciente.nome))
    {
        raiz->direita = Insere(raiz->direita, paciente);
    }

    // retorna a raiz da �rvore atualizada
    return raiz;
}

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


// fun��o para buscar pacientes pelo nome usando �rvore de busca bin�ria
void BuscaPorNome(int &quantidadePacientes)
{
    char nomeBusca[100];
	int i=0;
	getchar();
    cout << "Digite o nome do paciente: ";
    gets(nomeBusca);
	// getchar();
	// 	cout << "Digite o nome do paciente\n";
	// 	gets(pacientes[quantidadePacientes].nome);
	

    No* atual = raiz;
	// cout << atual;
	
    while (i<quantidadePacientes)
    {
		// strcpy(destino, origem);
        if (strstr(pacientes[i].nome,nomeBusca))
        {
            // Paciente paciente = pacientes;
            cout << "Nome: " << pacientes[i].nome << "\n";
            return;
        }
        else if (strlen(pacientes[i].nome) > strlen(nomeBusca))
        {
            atual = atual->esquerda;
        }
        else
        {
            atual = atual->direita;
        }

		// if(i<quantidadePacientes){
		// 	break;
		// }
		i++;
    }

    // se n�o encontrou
    cout << "Paciente nao encontrado.\n";
}





