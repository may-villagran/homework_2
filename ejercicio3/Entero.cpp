#include "Entero.hpp"

Entero::Entero(int entero): entero(entero){}
Entero::~Entero(){}
int Entero::getEntero(){
    return this->entero;
}

unique_ptr<Numero> Entero::operator+(Numero &otro_numero)
{
    Entero *entero_otro_numero = dynamic_cast<Entero *>(&otro_numero);
    if (entero_otro_numero)
    {
        return make_unique<Entero>(this->entero + entero_otro_numero->entero);
    }
    throw invalid_argument("La operación no se puede realizar, no es un número Entero.");
}

unique_ptr<Numero> Entero::operator-(Numero &otro_numero)
{
    Entero *entero_otro_numero = dynamic_cast<Entero *>(&otro_numero);
    if (entero_otro_numero)
    {
        return make_unique<Entero>(this->entero - entero_otro_numero->entero);
    }
    throw invalid_argument("La operación no se puede realizar, no es un número Entero.");
}

unique_ptr<Numero> Entero::operator*(Numero &otro_numero)
{
    Entero *entero_otro_numero = dynamic_cast<Entero *>(&otro_numero);
    if (entero_otro_numero)
    {
        return make_unique<Entero>(this->entero * entero_otro_numero->entero);
    }
    throw invalid_argument("La operación no se puede realizar, no es un número Entero.");
}

void Entero::to_string()
{
    cout <<this->entero << endl;
}