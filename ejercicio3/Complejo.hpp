#pragma once
#include "Numero.hpp"

class Complejo : public Numero
{
private:
    float real;
    float imaginario;

public:
    Complejo(float parte_real, float parte_imaginario);
    float getReal();
    float getImaginario();

    unique_ptr<Numero>operator+(Numero& otro) override;
    unique_ptr<Numero>operator-(Numero& otro) override;
    unique_ptr<Numero>operator*(Numero& otro) override;
    void to_string() override;
    ~Complejo() override;
};