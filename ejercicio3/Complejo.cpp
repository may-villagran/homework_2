#include "Complejo.hpp"
#include <memory> // Para unique_ptr
Complejo::~Complejo(){}
Complejo::Complejo(float parte_real, float parte_imaginario): real(parte_real), imaginario(parte_imaginario){}

float Complejo::getReal(){ return this->real;}
float Complejo::getImaginario(){return this->imaginario;}

unique_ptr<Numero> Complejo::operator+(Numero &otro_numero)
{
    Complejo *complejo_otro_numero = dynamic_cast<Complejo *>(&otro_numero);
    if (complejo_otro_numero)
        // sumo las partes reales y por el otro lado la imaginaria z = a+bi  w = c+di -> z+w = (a+c)+ (b+d)i
        return make_unique<Complejo>(this->real + complejo_otro_numero->real, this->imaginario + complejo_otro_numero->imaginario);
    throw invalid_argument("La operación no se puede realizar, no es un número Complejo.");
}

unique_ptr<Numero> Complejo::operator-(Numero &otro_numero)
{
    Complejo *complejo_otro_numero = dynamic_cast<Complejo *>(&otro_numero);
    if (complejo_otro_numero)
        // resto las partes reales y por el otro lado la imaginaria z = a-bi  w = c+di -> z-w = (a-c)+ (b-d)i
        return make_unique<Complejo>(this->real - complejo_otro_numero->real, this->imaginario - complejo_otro_numero->imaginario);
    throw invalid_argument("La operación no se puede realizar, no es un número Complejo.");
}

unique_ptr<Numero> Complejo::operator*(Numero &otro_numero)
{   
    Complejo *complejo_otro_numero = dynamic_cast<Complejo *>(&otro_numero);
    if (complejo_otro_numero){
        // z = (ac – bd) + (ad + bc)i
        float real_nuevo = (this->real * complejo_otro_numero->real) - (this->imaginario * complejo_otro_numero->imaginario);
        float imaginario_nuevo = (this->real * complejo_otro_numero->imaginario) + (this->imaginario * complejo_otro_numero->real);
        return make_unique<Complejo>(real_nuevo, imaginario_nuevo);
    } 
    throw invalid_argument("La operación no se puede realizar, no es un número Complejo.");
}

void Complejo::to_string()
{
    cout <<"("<< this->real << ")+(" << this->imaginario << ")i" << endl;
}
