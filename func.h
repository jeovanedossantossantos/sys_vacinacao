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

int menu();
void Cadastra(int &quantidadePacientes);
void SalvarDados(int &quantidadePacientes);
void CarregarDados(int &quantidadePacientes);
void merge(Paciente v[], int a, int b, int c);
void merge_sort(Paciente v[], int a, int c, int n);

#endif
