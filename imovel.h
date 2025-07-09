#ifndef IMOVEL_H
#define IMOVEL_H
#include <string>
using namespace std;

enum imovelTipo
{
    Casa,
    Apartamento,
    Terreno
};

class Imovel{
private:
    int id;
    imovelTipo tipo;
    int idProprietario;
    float lat, lng;
    string endereco;
    double preco;
    static int nextId;

public:
    Imovel(imovelTipo tipo, float lat = 0, float lng = 0);

    void setTipo(imovelTipo tipo);
    void setIdProprietario(int idProprietario);
    void setEndereco(std::string endereco);
    void setLocalizacao(float lat, float lng);
    void setPreco(double preco);

    int getId();
    imovelTipo getTipo();
    float getLat();
    float getLng();
    string getEndereco();
    double getPreco();
    int getIdProprietario();
};

#endif
