#pragma once
#include "Numero.hpp"

class Real: public Numero{
    private:
    float real;
    public:
    Real(float real);
    float getReal();

    unique_ptr<Numero> operator+(Numero& otro)override; 
    unique_ptr<Numero> operator-(Numero& otro)override; 
    unique_ptr<Numero> operator*(Numero& otro)override;
    ~Real()override;
     
    void to_string() override;
}

;