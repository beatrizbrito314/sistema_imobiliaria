#ifndef FUNCOESAUX_h
#define FUNCOESAUX_h
#include <iostream>
#include <string>
#include <vector>
#include "cliente.h"
#include "corretor.h"
#include "imovel.h"
using namespace std;

Cliente* dadosCliente();
Imovel* dadosImovel();
Corretor *dadosCorretor();
void cadastrarCliente(vector<Cliente*>& listaClientes);
void cadastrarImovel(vector<Imovel*>& listaImoveis);
void cadastrarCorretor(vector<Corretor*>& listaCorretores, vector<Corretor*>& listaAvaliadores);
string converterString(imovelTipo tipo);
#endif