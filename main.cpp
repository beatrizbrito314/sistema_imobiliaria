#include <iostream>
#include <string>
#include <vector>
#include "cliente.h"
#include "corretor.h"
#include "imovel.h"
#include "funcoesAux.h"
using namespace std;

int main() {
    vector<Cliente*> listaClientes;
    vector<Corretor*> listaCorretores;
    vector<Corretor*> listaAvaliadores;
    vector<Imovel*> listaImoveis;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cadastrarCorretor(listaCorretores, listaAvaliadores); 
    }

    cin>>n;
    for (int i = 0; i < n; i++){
        cadastrarCliente(listaClientes); 
    }

    cin>>n;
    for (int i = 0; i < n; i++){
        cadastrarImovel(listaImoveis); 
    }

    vector<vector<Imovel*>> imoveisDistribuidos(listaAvaliadores.size());
    distribuirImoveis(listaAvaliadores, listaImoveis, imoveisDistribuidos);
    
    //TESTES
   /* cout<<"Clientes"<<endl;
    for (Cliente* c : listaClientes) {
        cout << "Nome: " << c->getNome()
             << ", Telefone: " << c->getTelefone()
             << "ID: "<<c->getId()<<endl;
    }

    cout<<"Corretores"<<endl;
    for (Corretor* c : listaCorretores) {
        cout << " id: " << c->getId()
             << ", avaliado: " << c->isAvaliador() 
             <<" lat "<<c->getLat()
             <<" long "<<c->getLng()
             << endl;
    }

    cout<<"Imoveis"<<endl;
    for (Imovel* i : listaImoveis) {
        imovelTipo temp=i->getTipo();
        string tipo=converterString(temp);
        cout << " Tipo: " << tipo
             << ", Lat: " << i->getLat()
             << ", Long: " << i->getLng() << endl;
    }
    */

    //liberando memoria
    // NÃO USAR INT PARA O I PQ PODE TER PROBLEMA
    for (size_t i = 0; i < listaClientes.size(); i++) {
        delete listaClientes[i];
    }
    //apagar apenas os elementos dessa lista pq ela contem ambos(avaliador e n avaliador)
    for (size_t i = 0; i < listaCorretores.size(); i++) {
        delete listaCorretores[i];
    }
    for (size_t i = 0; i < listaImoveis.size(); i++) {
        delete listaImoveis[i];
    }
        return 0;

    }