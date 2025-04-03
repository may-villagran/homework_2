#pragma once
#include "Numero.hpp"

class Complejo : public Numero
{
private:
    float real;
    float imaginario;

public:
    Complejo(float parte_real, float parte_imaginario);
    float getReal();
    float getImaginario();
        /**
     * @brief Realiza la suma entre dos numeross complejos
     * @note sobreescribe el método de la interfaz numero
     * @param otro_numero se pasa una referencia de un Numero para realizar la operacion
     * @return devuleve un puntero del tipo del numero resultante
     */
    unique_ptr<Numero>operator+(Numero& otro_numero) override;
    /**
     * @brief Realiza la resta entre dos numeross complejos
     * @note sobreescribe el método de la interfaz numero
     * @param otro_numero se pasa una referencia de un Numero para realizar la operacion
     * @return devuleve un puntero del tipo del numero resultante
     */
    unique_ptr<Numero>operator-(Numero& otro_numero) override;
    /**
     * @brief Realiza el producto entre dos numeross complejos
     * @note sobreescribe el método de la interfaz numero
     * @param otro_numero se pasa una referencia de un Numero para realizar la operacion
     * @return devuleve un puntero del tipo del numero resultante
     */
    unique_ptr<Numero>operator*(Numero& otro_numero) override;
       /**
     * @brief Muestra por consola el numero
     * @note sobreescribe el método de la interfaz numero
     */
    void to_string() override;
    ~Complejo() override;
};