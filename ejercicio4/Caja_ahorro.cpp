
#include "Caja_ahorro.hpp"
Caja_ahorro::Caja_ahorro(const string &titular_nombre): Cuenta(titular_nombre), contador_mostrar_info(0), descuento_balance_info(20){}

bool Caja_ahorro::control_contador(){
    return contador_mostrar_info>2? true:false;
}
void Caja_ahorro::retirar(float retiro_monto){
    if(retiro_monto>this->balance) cout<<"\nNo hay dinero suficiente para realizar la operacion en la Caja de ahorro"<<endl;
    else{
        balance-=retiro_monto;
        cout<<"Caja de ahorro de:"<<titular_cuenta<<endl;
        cout<<setfill('-')<<setw(50)<<endl;
        cout<< fixed << setprecision(2)<< "\nSe han retirado: -$"<<retiro_monto<<endl;
        cout<< fixed << setprecision(2)<< "Balance actualizado: $"<<balance<<endl;
    }
    
}
void Caja_ahorro::mostrar_info(){
    if(control_contador()){
        cout<< fixed << setprecision(2)<< "Se realiza un descuento de $"<<descuento_balance_info<<" balance de la cuenta de ahorro"<<endl;
        this->balance-= descuento_balance_info;//le descuento el dinero por mostrar la info, en este caso 20
    }
    cout<<"\nTipo de cuenta: Caja de ahorro"<<endl;
    cout<<setfill('-')<<setw(50);
    cout<<"\nTitular: "<<titular_cuenta<<endl;
    cout<< fixed << setprecision(2)<< "Balance: "<<balance<<endl;
    contador_mostrar_info++;//incremento el contador de veces que mostre la info

}
