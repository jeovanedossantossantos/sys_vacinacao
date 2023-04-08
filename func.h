#ifndef LIBPRINT_H
#define LIBPRINT_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
typedef struct
{
	char nome[100];
	int idade;
	int indentificado;
} Paciente;

struct No {
    Paciente paciente;
    No* esquerda;
    No* direita;
};

int menu();
void Cadastra(int &quantidadePacientes);
void SalvarDados(int &quantidadePacientes);
void CarregarDados(int &quantidadePacientes);
void BuscaPorNome(int &quantidadePacientes);


#endif
