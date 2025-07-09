#ifndef CLIENTE_h
#define CLIENTE_h
#include <iostream>
#include <string>
using namespace std;

class Cliente{
    private:
        string nome, telefone; //pega da entrada
        int id; //implementar função de auto-incremento
        static int nextId;
    public:
        Cliente(string nome, string telefone);
        void setNome(string nome);
        void setTelefone(string tel);
        string getNome();
        string getTelefone();
        int getId();
    };
#endif