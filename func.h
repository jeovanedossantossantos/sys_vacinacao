#ifndef LIBPRINT_H
#define LIBPRINT_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
typedef struct
{
	char nome[100];
	int idade;
	int indentificado;
} Paciente

using namespace std;

int menu();
void Cadastra(int &quantidadePacientes);
void SalvarDados(int &quantidadePacientes);
void CarregarDados(int &quantidadePacientes);
void BuscarPeloNome(int &quantidadePacientes);




#endif
