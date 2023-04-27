#ifndef LIBPRINT_H
#define LIBPRINT_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

typedef struct
{
	char nome[254];
	int idade;
	int identificador;
} Paciente;

using namespace std;

int menu();
void Cadastra(int &quantidadePacientes);
void SalvarDados(int &quantidadePacientes);
void CarregarDados(int &quantidadePacientes);

int BuscarPeloNome(int &quantidadePacientes);

void Listar(int &quantidadePacientes, int tipo);
void MergeSort(Paciente pacientes[], int inicio, int fim);
void Merge(Paciente pacientes[], int inicio, int meio, int fim);
void QuickSort(Paciente pacientes[], int inicio, int fim);
int Patition(Paciente pacientes[], int inicio, int fim);
void QuickSortNome(Paciente pacientes[], int inicio, int fim);
int PatitionNome(Paciente pacientes[], int inicio, int fim);

void quicksortCrescente(Paciente lista[], int inicio, int fim);

void MergeIdentificador(Paciente v[], int a, int b, int c);
void MergeSortIdendificador(Paciente v[], int a, int c, int n);

int buscaIdentificador(int &quantidadePacientes);

#endif

