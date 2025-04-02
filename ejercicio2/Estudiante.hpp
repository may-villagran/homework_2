#pragma once
#include <algorithm>
#include <bits/stdc++.h> // Biblio estándar de C++, incluye pair
#include <string>
#include <iostream>
using namespace std;

class Curso; // adelanto de la clase

class Estudiante
{
private:
    string nombre_completo;                   ///< Nombre completo del estudiante
    int num_legajo;                           ///< Número de legajo del estudiante, único
    float promedio_general;                   ///< Promedio general de las notas del estudiante
    vector<pair<string, float>> cursos_notas; ///< Vector de pares (curso, nota_curso)

    /**
     * @brief Calcula el promedio general de las notas del estudiante
     * @param cursos_notas Vector de pares que contiene los cursos y sus respectivas notas.
     * @note Este método es privado y se utiliza internamente para actualizar el promedio.
     * @note solo realiza un promedio de las notas validas != -1
     */
    void calcular_promedio_general();
    /**
     * @brief chequea si una materia existe en los cursos de los alumnos
     * Busca en el vector<pair<string, float>> si existe un string que coincida con el nombre
     * @param nombre_curso nombre del curso a buscar
     * @param pos Referencia de la posicion
     * @note si la pos no existe entonces pos = size(vector) de lo contrario pasa la posicion
     */
    void existe_curso(string nombre_curso, int&pos);
    /**
     * @brief Inscribe al estudiante en un curso específico.
     * Este método agrega un curso al vector de cursos del estudiante con una nota inicial de -1,
     * indicando que aún no se ha asignado una calificación.
     * @param curso_nombre El nombre del curso al que se inscribirá el estudiante.
     */
    void incribir_curso(string curso_nombre);

    /**
     * @brief Desinscribe al estudiante de un curso específico.
     * Este método elimina un curso del vector de cursos del estudiante.
     * @param curso_nombre El nombre del curso del que se desinscribirá el estudiante.
     */
    void desinscribir_curso(string curso_nombre);

public:
    /**
     * @brief Constructor de la clase Estudiante.
     * @param nombre Nombre del estudiante.
     * @param apellido Apellido del estudiante.
     * @param num_legajo Número de legajo único del estudiante.
     * @param cursos_notas Vector de pares (curso, nota_curso) que contiene las notas del estudiante.
     * @note Inicializa los atributos del estudiante y calcula el promedio general.
     */
    Estudiante(string nombre, string apellido, int num_legajo);

    /**
     * @brief Sobrecarga del operador < para comparar estudiantes.
     * @param otro_estudiante Referencia a otro objeto de tipo Estudiante.
     * @return `true` si el promedio del estudiante actual es menor que el del otro estudiante, `false` en caso contrario.
     */
    bool operator<(const Estudiante &otro_estudiante);

    /**
     * @brief Sobrecarga del operador << para imprimir los datos del estudiante.
     * @param os Flujo de salida (ostream).
     * @param estudiante Referencia al objeto Estudiante a imprimir.
     * @return Referencia al flujo de salida modificado.
     * @note Este método es `friend` para acceder a los atributos privados de la clase.
     */
    friend ostream &operator<<(ostream &os, const Estudiante &estudiante);

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
    float getPromedio();

      /**
     * @brief Asigna una nota a un curso específico para el estudiante.
     * Este método permite definir la calificación obtenida por el estudiante
     * en un curso identificado por su nombre.
     * @param curso_nombre El nombre del curso al que se le asignará la nota.
     * @param nota_curso La calificación obtenida en el curso (valor flotante).
     */
    void definir_nota_curso(string curso_nombre, float nota_curso);

    void imprimir_cursos();

    friend class Curso;
};