#pragma once
#include "Numero.hpp"

class Real: public Numero{
    private:
    float real;
    public:
    Real(float real);
    float getReal();
    /**
     * @brief Realiza la suma entre dos numeros reales
     * @note sobreescribe el método de la interfaz numero
     * @param otro_numero se pasa una referencia de un Numero para realizar la operacion
     */
    unique_ptr<Numero> operator+(Numero& otro_numero)override; 
        /**
     * @brief Realiza la resta entre dos numeros reales
     * @note sobreescribe el método de la interfaz numero
     * @param otro_numero se pasa una referencia de un Numero para realizar la operacion
     */
    unique_ptr<Numero> operator-(Numero& otro_numero)override; 
        /**
     * @brief Realiza el producto entre dos numeros reales
     * @note sobreescribe el método de la interfaz numero
     * @param otro_numero se pasa una referencia de un Numero para realizar la operacion
     */
    unique_ptr<Numero> operator*(Numero& otro_numero)override;
    ~Real()override;
    /**
     * @brief Muestra por consola el numero
     * @note sobreescribe el método de la interfaz numero
     */
    void to_string() override;
}

;