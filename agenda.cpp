#include <iostream>
#include <iomanip>
#include <sstream>
#include "agenda.h"
#include "funcoesAux.h"  
using namespace std;

vector<vector<Agendamento>> gerarAgenda( //Calcula para cada corretor o horário de cada visita e o imóvel corresppndente 
    vector<Corretor*>& avaliadores,
    vector<vector<Imovel*>>& imoveisDistribuidos,
    vector<Cliente*>& clientes
) {
    vector<vector<Agendamento>> agendaFinal(avaliadores.size());

    const int duracaoVisita = 60;   //A avaliação dura 1 hora
    const double tempoPorKm = 2.0;  //2 minutos por km

    for (size_t i = 0; i < avaliadores.size(); i++) {
        Corretor* corretor = avaliadores[i];
        double latAtual = corretor->getLat();
        double lngAtual = corretor->getLng();

        int hora = 9;  //O avaliador parte de localização inicial as 9:00
        int minuto = 0;

        for (Imovel* imovel : imoveisDistribuidos[i]) {
            //Calculando a distância
            double dist = haversine(latAtual, lngAtual, imovel->getLat(), imovel->getLng());

            //CAlculando o tempo de deslocamento
            int tempoMin = static_cast<int>(dist * tempoPorKm);

            //Atualizando o tempo com o deslocamento
            minuto += tempoMin;
            hora += minuto / 60;
            minuto %= 60;

            //Formatando o horário
            stringstream horarioStr;
            horarioStr << setfill('0') << setw(2) << hora << ":" << setw(2) << minuto;

            //Criando o agendamento
            Agendamento evento;
            evento.horario = horarioStr.str();
            evento.imovel = imovel;

            //Associando o cliente
            int idCliente = imovel->getIdProprietario();
            for (Cliente* c : clientes) {
                if (c->getId() == idCliente) {
                    evento.cliente = c;
                    break;
                }
            }

            //Colocando o agendamento na agenda do corretor
            agendaFinal[i].push_back(evento);

            //Adicionando uma hora de visita
            minuto += duracaoVisita;
            hora += minuto / 60;
            minuto %= 60;

            //Atualizando a posição do crretor
            latAtual = imovel->getLat();
            lngAtual = imovel->getLng();
        }
    }

    return agendaFinal;
}

void imprimirAgenda( //Formata e exibe a agenda dos corretores
    vector<Corretor*>& avaliadores,
    vector<vector<Agendamento>>& agendas
) {
    for (size_t i = 0; i < avaliadores.size(); i++) {
        Corretor* c = avaliadores[i];
        cout << "Corretor " << c->getId() << endl;

        for (Agendamento e : agendas[i]) {
            cout << e.horario << " Imóvel " << e.imovel->getId() << endl;
        }

        cout << endl;
    }

}

