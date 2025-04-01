#include "Cuenta_corriente.hpp"

Cuenta_corriente::Cuenta_corriente(string titular_nombre, Caja_ahorro *caja_ahorro_asoc)
    : Cuenta(titular_nombre), caja_ahorro_asociada(caja_ahorro_asoc) {}

Cuenta_corriente::~Cuenta_corriente() {
    caja_ahorro_asociada = nullptr; 
}

void Cuenta_corriente::retirar(float retiro_monto) {
    if (retiro_monto > this->balance) {
        cout << "\nEl dinero en la cuenta corriente no es suficiente, el retiro se efectuará de la caja de ahorro" << endl;
        caja_ahorro_asociada->retirar(retiro_monto);
    } else {
        this->balance -= retiro_monto;
        cout << "\nCuenta corriente de:" << titular_cuenta << endl;
        cout << setfill('-') << setw(50) << endl;
        cout << fixed << setprecision(2)<< "\nSe han retirado: -$" << retiro_monto << endl;
        cout<<"Balance actualizado: $"<<balance<<endl;
    }
}

void Cuenta_corriente::mostrar_info() {
    cout << "\nTipo de cuenta: Cuenta corriente" << endl;
    cout << setfill('-') << setw(50);
    cout << "\nTitular: " << titular_cuenta << endl;
    cout << fixed << setprecision(2)<< "Balance: " << balance << endl;
}
