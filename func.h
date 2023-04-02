#ifndef LIBPRINT_H
#define LIBPRINT_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
typedef struct
{
	string nome;
	int idade;
	int indentificado;
} Paciente;

int menu();
void Cadastra(int &quantidadePacientes);

#endif
