#include <iostream>
#include <string>
#include "cliente.h"
using namespace std;
int Cliente::nextId = 1;
Cliente::Cliente(string nome, string tel){
    this->nome=nome;
    this->telefone=tel;
    id = nextId++;
}
//atribuir informações aos atributos
void Cliente::setNome(std::string nome){
    this->nome = nome;
}
void Cliente::setTelefone(std::string telefone){
    this->telefone = telefone;
}
string Cliente::getNome(){
    return nome;
}
string Cliente::getTelefone(){
    return telefone;
}
int Cliente::getId(){
    return id;
}