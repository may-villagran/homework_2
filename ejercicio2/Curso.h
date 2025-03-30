#pragma once
#include "Estudiante.h"
class Curso{
    private:
        string nombr_curso;
        vector<Estudiante>listado_estudiante;
        vector<int>legajos_estudiantes();
        void encontrar_estudiante(Estudiante estudiante, int &pos);
    public:
        bool curso_completo();
        bool verificacion_inscripcion(Estudiante Estudiante);
        void incribir_estudiante(Estudiante estudiante);
        void desinscribir_estudiante(Estudiante estudiante);
        void imprimir_listado(); //necesita sobreescribir los operadores
        //necesito un constructor de copia, que use deep copia por el uso de estudiantes y los string (manejo de memo dinamica)
};