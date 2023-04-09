#ifndef LIBPRINT_H
#define LIBPRINT_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

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
void ListarPorIdade(int &quantidadePacientes, int tipo);
void MergeSort(Paciente pacientes[], int inicio, int fim);
void Merge(Paciente pacientes[], int inicio, int meio, int fim);
void QuickSort(Paciente pacientes[], int inicio, int fim);
int Patition(Paciente pacientes[], int inicio, int fim);

#endif
