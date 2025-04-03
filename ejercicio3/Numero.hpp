#pragma once
#include <iostream>
#include <memory>
using namespace std;
//defino una interfaz, solo defino las funciones que deben desarrollar las clases derivadas
class Numero{
    public:
    virtual unique_ptr<Numero> operator+(Numero& otro)= 0; 
    virtual unique_ptr<Numero> operator-(Numero& otro)= 0; 
    virtual unique_ptr<Numero> operator*(Numero& otro)= 0; 
    virtual void to_string() = 0;
    virtual ~Numero() = 0; //no teiene destructor es interfaz, entonces debo implementarlo si o si en las derivadas
};