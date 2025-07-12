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
void distribuirImoveis(vector<Corretor*>& avaliadores, vector<Imovel*>& imoveis, vector<vector<Imovel*>>& imoveisDistribuidos);
string converterString(imovelTipo tipo);

double haversine(double lat1, double lon1, double lat2, double lon2);
#endif