#pragma once
#include "Cuenta.hpp"
#include "Cuenta_corriente.hpp"

class Caja_ahorro : public Cuenta
{
private:
    int contador_mostrar_info;  ///< Contador que lleva el registro de cuántas veces se ha mostrado la información de la cuenta.
    int descuento_balance_info; ///< Descuento aplicado al balance cada vez que se muestra la información de la cuenta.
    /**
     * @brief Controla la cantidad de veces que se muestra la información de la cuenta
     * @return true si el contador llego al limite, false si todavia no pasó.
     */
    bool control_contador();

public:
    /**
     * @brief Constructor de la clase Caja_ahorro.
     * @param titular_nombre Nombre del titular de la cuenta.
     */
    Caja_ahorro(string titular_nombre);
    /**
     * @brief Realiza un retiro de la cuenta de ahorro.
     * Este método sobrescribe el comportamiento de retiro de la clase base Cuenta.
     * Si el monto a retirar es mayor al balance disponible, no se realiza el retiro.
     * @param retiro_monto Monto a retirar de la cuenta.
     */
    void retirar(double retiro_monto) override;
    /**
     * @brief Muestra la información de la cuenta.
     * Este método sobrescribe el comportamiento de mostrar información de la clase base.
     * Cada vez que se llama, incrementa el contador y aplica un descuento al balance.
     */
    void mostrar_info() override;
        /**
     * @brief Clase firend
     * Le permite a la clase Cuenta_corriente acceder a todos los métodos y atributos de la clase Caja_ahorro
     */
    friend class Cuenta_corriente;
};