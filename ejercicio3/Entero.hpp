#pragma once
#include "Numero.hpp"

class Entero : public Numero
{
private:
    int entero;

public:
    Entero(int entero);
    int getEntero();

    unique_ptr<Numero>operator+(Numero& otro) override;
    unique_ptr<Numero>operator-(Numero& otro) override;
    unique_ptr<Numero>operator*(Numero& otro) override;
    void to_string() override;
    ~Entero() override;
}

;