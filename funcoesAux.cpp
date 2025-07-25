#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "cliente.h"
#include "corretor.h"
#include "imovel.h"
#include "funcoesAux.h"
#include <iomanip>

using namespace std;
constexpr double EARTH_R = 6371.0; // Raio da Terra em km
string converterString(imovelTipo tipo) {
    if (tipo == Casa)
        return "Casa";
    else if (tipo == Apartamento)
        return "Apartamento";
    else if (tipo == Terreno)
        return "Terreno";
    else
        return "Desconhecido";
}

// ler dados do .txt e atribuir os valores as classes
Cliente* dadosCliente(){
    //[telefone] [nome]
    string nome, telefone;
    cin >> telefone;
    getline(cin >> ws, nome); // ler nome tipo nome sobrenome etc
    Cliente *novoCliente = new Cliente(nome, telefone);
    return novoCliente;
}

Imovel* dadosImovel(){
    //[tipo] [proprietarioId] [latitude] [longitude] [preco] [endereco]
    string tipoStr; int idProprietario; double lat, lng, preco;
    cin >> tipoStr >> idProprietario >> lat >> lng >> preco;
    string endereco;
    getline(cin >> ws, endereco); // ler endereco
    imovelTipo tipo;

    if (tipoStr == "Casa")
        tipo = Casa;
    else if (tipoStr == "Apartamento")
        tipo = Apartamento;
    else if (tipoStr == "Terreno")
        tipo = Terreno;
    else {
        cout<<"Tipo de imóvel inválido"<<endl;
    }
    Imovel *novoImovel = new Imovel(tipo, lat, lng);
    novoImovel->setIdProprietario(idProprietario);
    novoImovel->setEndereco(endereco);
    novoImovel->setPreco(preco);
    
    return novoImovel;
}
Corretor *dadosCorretor(){
    //[telefone] [avaliador] [latitude] [longitude] [nome]
    string nome, telefone; 
    bool avaliador;
    int intAvld;
    float lat, lng;
    cin>>telefone>>intAvld>>lat>>lng;

    getline(cin >> ws, nome);
    avaliador=intAvld;
    Corretor *novoCorretor = new Corretor(nome, telefone);
    novoCorretor->setAvaliador(avaliador);
    novoCorretor->setLocalizacao(lat, lng);

    return novoCorretor;
}
void cadastrarCliente(vector<Cliente*> &listaClientes){
    Cliente* cliente=dadosCliente();
    listaClientes.push_back(cliente);

}
void cadastrarImovel(vector<Imovel*> &listaImoveis){
    Imovel* imovel=dadosImovel();
    listaImoveis.push_back(imovel);
}
void cadastrarCorretor(vector<Corretor*> &listaCorretores, vector<Corretor*> &listaAvaliadores){
    Corretor* corretor=dadosCorretor();
    bool avaliador=corretor->isAvaliador();
    if(avaliador==false){
        listaCorretores.push_back(corretor);
    }else{
        listaAvaliadores.push_back(corretor);
        listaCorretores.push_back(corretor);
    }
}

void distribuirImoveis(vector<Corretor*>& avaliadores, vector<Imovel*>& imoveis, vector<vector<Imovel*>>& imoveisDistribuidos) {
    int pos = 0;
    for (Imovel* im : imoveis) {
        imoveisDistribuidos[pos].push_back(im);
        pos = (pos + 1) % avaliadores.size();
    }
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}
//Calcula para cada corretor o horário de cada visita e o imóvel corresppndente 
vector<vector<Agendamento>> gerarAgenda(vector<Corretor*>& avaliadores, vector<vector<Imovel*>>& imoveisDistribuidos) {
    vector<vector<Agendamento>> agendaFinal(avaliadores.size());
    int duracaoVisita = 60;   //A avaliação dura 1 hora
    double tempoPorKm = 2.0;  //2 minutos por km

    for (size_t i = 0; i < avaliadores.size(); i++) {
        Corretor* corretor = avaliadores[i];
        double latAtual = corretor->getLat();
        double lngAtual = corretor->getLng();

        int tempoMinutos = 9 * 60;  // O avaliador parte de localização inicial as 9:00 (540)

        for (Imovel* imovel : imoveisDistribuidos[i]) {
            //Calculando a distância
            double dist = haversine(latAtual, lngAtual, imovel->getLat(), imovel->getLng());

            //CAlculando o tempo de deslocamento
            int tempoDesloc = static_cast<int>(dist * tempoPorKm);

            //Atualizando o tempo com o deslocamento
            tempoMinutos += tempoDesloc;

            // Convertendo o horario
            double horarioDecimal = (tempoMinutos / 60.0);

            //Criando o agendamento
            Agendamento visita;
            visita.horario = horarioDecimal;
            visita.imovel = imovel;

            //Colocando o agendamento na agenda do corretor
            agendaFinal[i].push_back(visita);

            //Adicionando uma hora de visita
            tempoMinutos += duracaoVisita;

            //Atualizando a posição do crretor
            latAtual = imovel->getLat();
            lngAtual = imovel->getLng();
        }
    }

    //retorna a agenda completa
    return agendaFinal;
}

//Formata e exibe a agenda dos corretores
//Obs: modifiquei para evitar linhas a mais, a lógica é a mesma. Mas agora ela imprime apenaspara um corretor
void imprimirAgenda(Corretor* &avaliador, vector<Agendamento>&agenda) {
    cout << "Corretor " << avaliador->getId() << endl;

    for (Agendamento& a : agenda) {
        int hora = static_cast<int>(a.horario);
//Obs2: adicionei o round para corrigir o arredondamento
        int min = static_cast<int>(std::round((a.horario - hora) * 60));
        cout << setfill('0') << setw(2) << hora << ":" << setw(2) << min << " Imóvel " << a.imovel->getId() << endl;
    }
}
