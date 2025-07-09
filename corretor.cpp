#include <iostream>
#include <string>
#include "corretor.h"
using namespace std;
int Corretor::nextId = 1;
Corretor::Corretor(string nome, string tel){
    this->nome = nome;
    this->telefone = tel;
    id = nextId++;
    avaliador = false;
    lat = 0;
    lng = 0;
}
// atribuir informações aos atributos
void Corretor::setNome(std::string nome){
    this->nome = nome;
}

void Corretor::setTelefone(std::string telefone){
    this->telefone = telefone;
}

void Corretor::setAvaliador(bool avld){
    this->avaliador = avld;
}
void Corretor::setLocalizacao(float lat, float lng){
    this->lat = lat;
    this->lng = lng;
}
// ler os valores dos atributos
int Corretor::getId(){
    return id;
}
bool Corretor::isAvaliador(){
    return avaliador;
}
float Corretor::getLat(){
    return lat;
}
float Corretor::getLng(){
    return lng;
}
string Corretor::getNome(){
    return nome;
}
string Corretor::getTel(){
    return telefone;
}