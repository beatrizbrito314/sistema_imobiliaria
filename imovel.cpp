#include <iostream>
#include <string>
#include "imovel.h"
int Imovel::nextId = 1;

Imovel::Imovel(imovelTipo tipo, float lat, float lng){
    this->tipo = tipo;
    this->lat = lat;
    this->lng = lng;
    id = nextId++;
}
void Imovel::setTipo(imovelTipo tipo){
    this->tipo = tipo;
}
void Imovel::setIdProprietario(int idProprietario){
    this->idProprietario = idProprietario;
}
void Imovel::setEndereco(std::string endereco){
    this->endereco = endereco;
}
void Imovel::setLocalizacao(float lat, float lng){
    this->lat = lat;
    this->lng = lng;
}
void Imovel::setPreco(double preco){
    this->preco = preco;
}
int Imovel::getId(){
    return id;
}
float Imovel::getLat(){
    return lat;
}
float Imovel::getLng(){
    return lng;
}
imovelTipo Imovel::getTipo(){
    return tipo;
};
string Imovel::getEndereco(){
    return endereco;
}
double Imovel::getPreco(){
    return preco;
}
int Imovel::getIdProprietario(){
    return idProprietario;
}

