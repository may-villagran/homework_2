#pragma once
#include "Cuenta.hpp"
#include "Caja_ahorro.hpp"

class Cuenta_corriente: public Cuenta{
    private:
        unique_ptr<Caja_ahorro> caja_ahorro_asociada;
    public:
    Cuenta_corriente(string titular_nombre, unique_ptr<Caja_ahorro> caja_ahorro);
    void retirar(double retiro_monto) override;
    void mostrar_info() override;
    
};
