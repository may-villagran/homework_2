#pragma once
#include "Estudiante.h"
#include <memory> // Para shared_ptr

class Curso {
    private:
        string nombr_curso;
        vector<shared_ptr<Estudiante>> listado_estudiante;
        vector<int> legajos_estudiantes();
        void encontrar_estudiante(shared_ptr<Estudiante> estudiante, int &pos);
    public:
        bool curso_completo();
        bool verificacion_inscripcion(shared_ptr<Estudiante> estudiante);
        void incribir_estudiante(shared_ptr<Estudiante> estudiante);
        void desinscribir_estudiante(shared_ptr<Estudiante> estudiante);
        void imprimir_listado(); // necesita sobreescribir los operadores
        // Constructor de copia con deep copy
};