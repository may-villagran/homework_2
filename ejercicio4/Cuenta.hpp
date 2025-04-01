#pragma once
#include <bits/stdc++.h> // Biblio estándar de C++, incluye pair
#include <stdexcept>
#include <iomanip>
#include <memory>
using namespace std;
class Cuenta{
    public:
    string titular_cuenta;///< Cadena de texto con el nombre del titular
    /**
     * @brief Constructor de la clase Cuenta
     * @param titular_nombre Nombre del titular de la cuenta
         * @note inicializa el balance e n  0
         */
        Cuenta(const string &titular_nombre);
        /**
         * @brief Ingresa dinero a la cuenta
         * @param deposito_monto Monto a ingresar en la cuenta
         */
        void depositar(float deposito_monto);
        /**
         * @brief Constructor de la clase Cuenta
         * @param titular_nombre Nombre del titular de la cuenta
         * @note inicializa el balance e n  0
         */
        /**
         * @bried Realiza un retiro en la cuenta
         * El comportamiento se define en las clases derivadas
         */
        virtual void retirar(float retiro_monto) = 0;
        /**
         * @bried Muestra la informacion de la cuenta
         * El comportamiento varia en las clases bases
         * De forma general muestra:
         *  -Tipo de cuenta
         *  -Nombre del titular de la cuenta
         *  -Balance de la cuenta
         */
        virtual void mostrar_info() = 0;
    protected:
         float balance;  ///< Dinero disponible en la cuenta
    };