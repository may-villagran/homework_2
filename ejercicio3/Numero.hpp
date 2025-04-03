#pragma once
#include <iostream>
#include <memory>
using namespace std;
//defino una interfaz, solo defino las funciones que deben desarrollar las clases derivadas
class Numero{
    public:
    /**
     * Método virtual puro que sobreescribe el operador + para la suma de numeros dependiendo su tipo
     * @param otro
     */
    virtual unique_ptr<Numero> operator+(Numero& otro_numero)= 0; 
    virtual unique_ptr<Numero> operator-(Numero& otro_numero)= 0; 
    virtual unique_ptr<Numero> operator*(Numero& otro_numero)= 0; 
    virtual void to_string() = 0;
    virtual ~Numero() = 0; //no teiene destructor es interfaz, entonces debo implementarlo si o si en las derivadas
};