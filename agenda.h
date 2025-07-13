#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include <vector>
#include "corretor.h"
#include "imovel.h"

using namespace std;


struct Agendamento {
    string horario;
    Imovel* imovel;
};

vector<vector<Agendamento>> gerarAgenda(
    vector<Corretor*>& avaliadores,
    vector<vector<Imovel*>>& imoveisDistribuidos
);

void imprimirAgenda(
    vector<Corretor*>& avaliadores,
    vector<vector<Agendamento>>& agendas
);


#endif

