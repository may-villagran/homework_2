#pragma once
#include "Estudiante.hpp"
#include <memory> 
using namespace std;

/**
 * @class Curso
 * @brief Representa un curso que contiene un listado de estudiantes y permite gestionar la inscripción y desinscripción de un estudiante,  verificar si un curso está completo, listar los estudiantes inscritos..
 * La clase Curso administra un conjunto de estudiantes usando shared_ptr.
 */
class Curso {
    private:
        string nombre_curso;///< string con el nombre que identidica el curso

        vector<shared_ptr<Estudiante>> listado_estudiantes;///< vector de tipo shared_ptr que apuntas a objetos de tipo Estudiante

        /**
         * @brief Obtiene los legajos de los estudiantes del curso.
         * @return vector<int> con los números de legajos de los estudiantes
         * @throw runtime_error si no hay estudiantes en el curso.
         */
        vector<int> legajos_estudiantes();

        /**
         * @brief Encuentra la posición de un estudiante en el listado.
         * Método privado que busca un estudiante en el vector de estudiantes y devuelve su posición.
         * @param estudiante shared_ptr al estudiante que se desea buscar.
         * @param pos Referencia a un entero donde se almacenará la posición del estudiante en el vector.
         * @throw invalid_argument si el estudiante no está inscrito en el curso.
         */
        void encontrar_estudiante(shared_ptr<Estudiante> estudiante, int &pos);

    public:
        /**
         * @brief Constructor de la clase Curso.
         * Inicializa un curso con un nombre específico.
         * @param nombre Nombre del curso.
         * @throw invalid_argument si el nombre del curso está vacío.
         */
        Curso(string nombre);

        /**
         * @brief Constructor de copia superficial (Shallow Copy).
         * Crea un nuevo curso copiando el listado de estudiantes de otro curso existente.
         * Este constructor utiliza copia superficial ya que los estudiantes son gestionados mediante shared_ptr,
         * lo que permite compartir la misma instancia de Estudiante entre múltiples cursos sin duplicar objetos.
         * Ya que no necesitamos distintas instancias para un mismo objeto, ademas no tenemos problemas si se desea 
         * borrar una clase, ya que el shared ptr permite borrar cuando nadie apunta hacia el objeto
         * @param curso_original Referencia constante al curso original del cual se copiarán los estudiantes.
         * @param nombre_curso_nuevo Nombre del nuevo curso.
         * @throw invalid_argument si el nombre del nuevo curso está vacío.
         */
        Curso(const Curso &curso_original, string nombre_curso_nuevo);

        /**
         * @brief Verifica si el curso está completo.
         * Devuelve true si el curso ha alcanzado su capacidad máxima de estudiantes, false en caso contrario.
         * @note el curso tiene una capacidad máxima de 20 estudiantes
         * @return Booleano indicando si el curso está completo.
         * @throw runtime_error si no hay estudiantes en el curso.
         */
        bool curso_completo();

        /**
         * @brief Verifica si un estudiante ya está inscrito en el curso.
         * Comprueba si un estudiante específico ya forma parte del listado de estudiantes del curso.
         * @param estudiante Puntero inteligente al estudiante que se desea verificar.
         * @return Booleano indicando si el estudiante está inscrito.
         * @throw invalid_argument si el estudiante es un puntero nulo.
         */
        bool verificacion_inscripcion(shared_ptr<Estudiante> estudiante);

        /**
         * @brief Inscribe un estudiante en el curso.
         * Agrega un estudiante al listado de estudiantes del curso, siempre que no se encuentre el legajo registrado.
         * @param estudiante Puntero inteligente al estudiante que se desea inscribir.
         * @throw invalid_argument si el estudiante a agregar tiene un número de legajo ya registrado
         * @throw runtime_error si el curso ya está completo.
         */
        void incribir_estudiante(shared_ptr<Estudiante> estudiante);

        /**
         * @brief Desinscribe un estudiante del curso.
         * Elimina un estudiante del listado de estudiantes del curso, si está inscrito.
         * @param estudiante Puntero inteligente al estudiante que se desea desinscribir.
         * @throw invalid_argument si el estudiante es un puntero nulo.
         * @throw runtime_error si el estudiante no está inscrito en el curso.
         */
        void desinscribir_estudiante(shared_ptr<Estudiante> estudiante);

        /**
         * @brief Imprime el listado de estudiantes inscritos en el curso.
         * Muestra en consola el listado de estudiantes ordenados alfabéticamente por su nombre.
         * @throw runtime_error si no hay estudiantes en el curso.
         */
        void imprimir_listado();
};