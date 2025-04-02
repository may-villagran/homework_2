#pragma once
#include <iostream>
//defino una interfaz, solo defino las funciones que deben desarrollar las clases derivadas
class Numero{
    public:
    virtual Numero* operator+()= 0; 
    virtual Numero* operator-()= 0; 
    virtual Numero* operator*()= 0; 
    virtual void to_string() = 0;
};