#include "Cuenta.hpp"

//inicializo el balance de la cuenta en 0
Cuenta::Cuenta(const string &titular_nombre): titular_cuenta(titular_nombre), balance(0){}

void Cuenta::depositar(float deposito_monto){
    if(deposito_monto<0) throw invalid_argument("El valor del monto a depositar es negativo");
    this->balance += deposito_monto;
    cout << fixed << setprecision(2);
    cout << "\nSe han depositado: $" << deposito_monto<<endl;
    cout<<"Balance actualizado: $"<<balance<<endl;
}