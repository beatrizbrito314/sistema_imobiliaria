#ifndef CORRETOR_h
#define CORRETOR_h
#include <iostream>
#include <string>
using namespace std;

class Corretor
{
private:
    string nome, telefone; // pega da entrada
    int id; // implementar função de auto-incremento
    bool avaliador;
    float lat, lng;
    static int nextId;

public:
    Corretor(string nome, string telefone);
    void setNome(string nome);
    void setTelefone(string tel);
    void setAvaliador(bool avld); //falso como padrao
    void setLocalizacao(float lat, float lng);

    int getId();
    string getNome();
    string getTel();
    bool isAvaliador();
    float getLat();
    float getLng();
};
#endif