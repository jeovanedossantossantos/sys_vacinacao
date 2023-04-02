#ifndef LIBPRINT_H
#define LIBPRINT_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
   //Aqui vai os protótipos e as declarações das strucs 
using namespace std;
typedef struct {
	string nome;
	int idade;
	int indentificado;
}Paciente;

void Cadastra(int  &quantidadePacientes);

#endif
