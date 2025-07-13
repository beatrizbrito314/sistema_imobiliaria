#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include "imovel.h"
#include "cliente.h"
#include "corretor.h"
using namespace std;

struct Agendamento {
    string horario;
    Imovel* imovel;
    Cliente* cliente;
};

vector<vector<Agendamento>> gerarAgenda(
    vector<Corretor*>& avaliadores,
    vector<vector<Imovel*>>& imoveisDistribuidos,
    vector<Cliente*>& clientes
);

void imprimirAgenda(
    vector<Corretor*>& avaliadores,
    vector<vector<Agendamento>>& agendas
);


#endif

