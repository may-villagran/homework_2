#include "Real.hpp"
#include <memory> // Para std::unique_ptr

Real::Real(float real) : real(real) {}
Real::~Real(){}
float Real::getReal() { return this->real; }

unique_ptr<Numero> Real::operator+(Numero &otro_numero)
{
    Real *real_otro_numero = dynamic_cast<Real *>(&otro_numero);
    if (real_otro_numero)
    {
        return make_unique<Real>(this->real + real_otro_numero->real);
    }
    throw invalid_argument("La operación no se puede realizar, no es un número real.");
}

unique_ptr<Numero> Real::operator-(Numero &otro_numero)
{
    Real *real_otro_numero = dynamic_cast<Real *>(&otro_numero);
    if (real_otro_numero)
    {
        return make_unique<Real>(this->real - real_otro_numero->real);
    }
    throw invalid_argument("La operación no se puede realizar, no es un número real.");
}

unique_ptr<Numero> Real::operator*(Numero &otro_numero)
{
    Real *real_otro_numero = dynamic_cast<Real *>(&otro_numero);
    if (real_otro_numero)
    {
        return make_unique<Real>(this->real * real_otro_numero->real);
    }
    throw invalid_argument("La operación no se puede realizar, no es un número real.");
}

void Real::to_string()
{
    cout << this->real << endl;
}