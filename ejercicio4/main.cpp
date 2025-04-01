#include "Cuenta_corriente.hpp"

int main(){
    map<string, pair<Cuenta_corriente, Caja_ahorro>> cuentas;



    string nombre_titular = "Nombre Apellido";
    //inicializacion caa ahorro
    Caja_ahorro caja_ahorro(nombre_titular);
    cout<<"Se ha creado la Caja de ahorro:"<<endl;
    caja_ahorro.mostrar_info();
    //inicializacion cuenta corriente
    Cuenta_corriente cuenta_corriente(nombre_titular, &caja_ahorro); //paso por referencia
    cout<<"Se ha creado la Cuenta corriente"<<endl;
    cuenta_corriente.mostrar_info();

    caja_ahorro.depositar(200000.14);
    caja_ahorro.mostrar_info();
    cuenta_corriente.retirar(90000); //debe sacar de la cuenta de ahorro
    cuenta_corriente.depositar(3000);
    cuenta_corriente.retirar(2500); //debe retirar de la corrinete


    //Descuneto por mostrar info en caja de ahorro, el contador esta en 1 por la linea 9 cuando se llama al metodo
    caja_ahorro.mostrar_info();
    caja_ahorro.mostrar_info();
    caja_ahorro.mostrar_info();



    return 0;
}