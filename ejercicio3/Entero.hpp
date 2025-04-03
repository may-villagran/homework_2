#pragma once
#include "Numero.hpp"

class Entero : public Numero
{
private:
    int entero;

public:
    Entero(int entero);
    int getEntero();
    /**
     * @brief Realiza la suma entre dos numeros enteros
     * @note sobreescribe el método de la interfaz numero
     * @param otro_numero se pasa una referencia de un Numero para realizar la operacion
     */
    unique_ptr<Numero>operator+(Numero& otro_numero) override;
            /**
     * @brief Realiza la resta entre dos numeros enteros
     * @note sobreescribe el método de la interfaz numero
     * @param otro_numero se pasa una referencia de un Numero para realizar la operacion
     */
    unique_ptr<Numero>operator-(Numero& otro_numero) override;
        /**
     * @brief Realiza el producto entre dos numeros enteros
     * @note sobreescribe el método de la interfaz numero
     * @param otro_numero se pasa una referencia de un Numero para realizar la operacion
     */   
    unique_ptr<Numero>operator*(Numero& otro_numero) override;
       /**
     * @brief Muestra por consola el numero
     * @note sobreescribe el método de la interfaz numero
     */
    void to_string() override;
    ~Entero() override;
}

;