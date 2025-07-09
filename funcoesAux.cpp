#include <iostream>
#include <string>
#include <vector>
#include "cliente.h"
#include "corretor.h"
#include "imovel.h"
using namespace std;
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
Cliente* dadosCliente()
{
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
