#pragma once
#include "Cuenta.hpp"
#include "Caja_ahorro.hpp" //necesito incluir la descripcion completa de la clase

class Cuenta_corriente : public Cuenta
{
public:
    /**
     * @brief Constructor de la clase Caja_ahorro.
     * @param titular_nombre Nombre del titular de la cuenta.
     * @param caja_ahorro_asoc Caja_ahorro pasado por referencia
     */
    Cuenta_corriente(string titular_nombre, Caja_ahorro* caja_ahorro_asoc);
    /**
     * @bried Realiza un retiro de la cuenta corriente
     * @note Si la cuenta no cuenta corriente no cuenta con el dinero suficiente, efectua el retiro de la caja de ahorro
     * @param retiro_monto monto a retirar de la cuenta
     */
    void retirar(float retiro_monto) override;
    /**
     * @brief Muestra la información de la cuenta.
     * Este método sobrescribe el comportamiento de mostrar información de la clase base.
     */
    void mostrar_info() override;

    ~Cuenta_corriente();

private:
    Caja_ahorro* caja_ahorro_asociada; ///< puntero a objeto caja de ahorro
};
