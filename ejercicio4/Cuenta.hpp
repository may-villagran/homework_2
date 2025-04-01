#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <memory>
using namespace std;
class Cuenta{
    protected:
        double balance; 
    public:
        string titular_cuenta;
        
        Cuenta(string titular_nombre);
        void depositar(double deposito_monto);
        virtual void retirar(double retiro_monto) = 0;
        virtual void mostrar_info() = 0;
};