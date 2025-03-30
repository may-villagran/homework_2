#include "Curso.h"

vector<int> Curso::legajos_estudiantes(){
    vector<int> legajos;
    for(Estudiante &estudiante : listado_estudiante) legajos.push_back(estudiante.getLegajo());
    return legajos;
}

void Curso::encontrar_estudiante(Estudiante estudiante, int &pos){
    for (int i = 0; i < listado_estudiante.size(); i++) {
        if (listado_estudiante[i].getLegajo() == estudiante.getLegajo()) {
            pos = i;
            return;
        }
    }
    pos = listado_estudiante.size();
}

bool Curso::curso_completo(){
    return listado_estudiante.size() > 20;
}

bool Curso::verificacion_inscripcion(Estudiante estudiante){
    int pos = 0;
    encontrar_estudiante(estudiante, pos);
    return pos != listado_estudiante.size();
}

void Curso::incribir_estudiante(Estudiante estudiante){
    if (curso_completo()) throw runtime_error("El curso se encuentra completo, no se puede agregar el estudiante");
    if (verificacion_inscripcion(estudiante)) throw invalid_argument("El número de legajo corresponde a otro estudiante");
    listado_estudiante.push_back(estudiante);
}

void Curso::desinscribir_estudiante(Estudiante estudiante){
    int pos = 0;
    encontrar_estudiante(estudiante, pos);
    if (pos == listado_estudiante.size()) throw invalid_argument("El estudiante que desea eliminar no se encuentra en el curso");
    listado_estudiante.erase(listado_estudiante.begin() + pos);
}

void Curso::imprimir_listado(){
    

}






