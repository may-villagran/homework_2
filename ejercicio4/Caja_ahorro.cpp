#include "Caja_ahorro.hpp"
Caja_ahorro::Caja_ahorro(string titular_nombre): Cuenta(titular_nombre), contador_mostrar_info(0), descuento_balance_info(20){}
bool Caja_ahorro::control_contador(){
    return contador_mostrar_info>2? true:false;
}
void Caja_ahorro::retirar(double retiro_monto){
    if(balance == 0) cout<<"No hay dinero suficiente para realizar la operacion en la Caja de ahorro"<<endl;
    else{
        balance-=retiro_monto;
        cout<<"Caja de ahorro de:"<<titular_cuenta<<endl;
        cout<<setfill('-')<<setw(25)<<endl;
        cout<<"Se han retirado: -$"<<to_string(retiro_monto)<<endl;
    }
    
}
void Caja_ahorro::mostrar_info(){
    if(control_contador()){
        cout<<"Se realiza un descuento de $"<<to_string(descuento_balance_info)<<" balance de la cuenta de ahorro"<<endl;
        this->balance-= descuento_balance_info;//le descuento el dinero por mostrar la info, en este caso 20
    }
    cout<<"Tipo de cuenta: Caja de ahorro"<<endl;
    cout<<setfill('-')<<setw(25)<<endl;
    cout<<"Titular: "<<titular_cuenta<<endl;
    cout<<"Balance: "<<balance<<endl;
    contador_mostrar_info++;//incremento el contador de veces que mostre la info

}
