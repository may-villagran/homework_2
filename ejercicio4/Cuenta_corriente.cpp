#include "Cuenta_corriente.hpp"

Cuenta_corriente::Cuenta_corriente(string titular_nombre, unique_ptr<Caja_ahorro>caja_ahorro):Cuenta(titular_nombre), caja_ahorro_asociada(move(caja_ahorro)){}

void Cuenta_corriente::retirar(double retiro_monto){
    if(retiro_monto>this->balance){
        cout<<"El dinero en la cuenta corriente no es suficiente, el retiro se efectuará de la caja de ahorro"<<endl;
        caja_ahorro_asociada->retirar(retiro_monto); //uso el metodo de caja de ahorro para descontar el dinero
        //caja de ahorro ya avisa si se está intentando retirar dinero que no hay 
    }
    else {
        this->balance -= retiro_monto;
        cout<<"Cuenta corriente de:"<<titular_cuenta<<endl;
        cout<<setfill('-')<<setw(25)<<endl;
        cout<<"Se han retirado: -$"<<to_string(retiro_monto)<<endl;
    }
}
void Cuenta_corriente::mostrar_info(){
    cout<<"Tipo de cuenta: Cuenta corriente"<<endl;
    cout<<setfill('-')<<setw(25)<<endl;
    cout<<"Titular: "<<titular_cuenta<<endl;
    cout<<"Balance: "<<balance<<endl;
}

