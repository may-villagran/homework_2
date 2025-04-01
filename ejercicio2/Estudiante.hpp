#pragma once
#include <algorithm>
#include <bits/stdc++.h> // Biblio estándar de C++, incluye pair
#include <string>
#include <iostream>
using namespace std;

class Estudiante {
    private:
        string nombre_completo; ///< Nombre completo del estudiante
        int num_legajo; ///< Número de legajo del estudiante, único
        double promedio_general; ///< Promedio general de las notas del estudiante
        vector<pair<string, double>> cursos_notas; ///< Vector de pares (curso, nota_curso)

        /**
         * @brief Calcula el promedio general de las notas del estudiante.
         * @param cursos_notas Vector de pares que contiene los cursos y sus respectivas notas.
         * @return El promedio general de las notas.
         * @note Este método es privado y se utiliza internamente para actualizar el promedio.
         */
        double calcular_promedio_general(vector<pair<string, double>> cursos_notas);

    public:
        /**
         * @brief Constructor de la clase Estudiante.
         * @param nombre Nombre del estudiante.
         * @param apellido Apellido del estudiante.
         * @param num_legajo Número de legajo único del estudiante.
         * @param cursos_notas Vector de pares (curso, nota_curso) que contiene las notas del estudiante.
         * @note Inicializa los atributos del estudiante y calcula el promedio general.
         */
        Estudiante(string nombre, string apellido, int num_legajo, vector<pair<string, double>> cursos_notas);

        /**
         * @brief Sobrecarga del operador < para comparar estudiantes.
         * @param otro_estudiante Referencia a otro objeto de tipo Estudiante.
         * @return `true` si el promedio del estudiante actual es menor que el del otro estudiante, `false` en caso contrario.
         */
        bool operator<(const Estudiante& otro_estudiante);

        /**
         * @brief Sobrecarga del operador << para imprimir los datos del estudiante.
         * @param os Flujo de salida (ostream).
         * @param estudiante Referencia al objeto Estudiante a imprimir.
         * @return Referencia al flujo de salida modificado.
         * @note Este método es `friend` para acceder a los atributos privados de la clase.
         */
        friend ostream& operator<<(ostream& os, const Estudiante& estudiante);

        // Métodos para obtener los datos

        /**
         * @brief Obtiene el nombre completo del estudiante.
         * @return El nombre completo del estudiante.
         */
        string getNombre();

        /**
         * @brief Obtiene el número de legajo del estudiante.
         * @return El número de legajo del estudiante.
         */
        int getLegajo();

        /**
         * @brief Obtiene el promedio general del estudiante.
         * @return El promedio general del estudiante.
         */
        double getPromedio();
};