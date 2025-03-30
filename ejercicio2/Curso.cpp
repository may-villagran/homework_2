#include "Curso.h"
bool comparar_estudiantes_desreferencia(const shared_ptr<Estudiante>& estudiante1, const shared_ptr<Estudiante>& estudiante2) {
    return *estudiante1< *estudiante2;
}

vector<int> Curso::legajos_estudiantes(){
    vector<int> legajos;
    for (const shared_ptr<Estudiante>& estudiante : listado_estudiante) {
        legajos.push_back(estudiante->getLegajo());
    }
    return legajos;
}

void Curso::encontrar_estudiante(shared_ptr<Estudiante> estudiante, int &pos){
    for (int i = 0; i < listado_estudiante.size(); i++) {
        if (listado_estudiante[i]->getLegajo() == estudiante->getLegajo()) {
            pos = i;//si lo encunetra devuleve la pos
            return;
        }
    }
    pos = listado_estudiante.size(); //sino quiero que devuleva el tam del arreglo
}

bool Curso::curso_completo(){
    return listado_estudiante.size() > 20;
}

bool Curso::verificacion_inscripcion(shared_ptr<Estudiante> estudiante){
    int pos = 0;
    encontrar_estudiante(estudiante, pos);
    return pos != listado_estudiante.size(); //si se retorna una pos val está el estudiante
}

void Curso::incribir_estudiante(shared_ptr<Estudiante> estudiante){
    //manejo de caso de curso completo
    if (curso_completo()) throw runtime_error("El curso se encuentra completo, no se puede agregar el estudiante");
    if (verificacion_inscripcion(estudiante)) throw invalid_argument("El número de legajo corresponde a otro estudiante");
    listado_estudiante.push_back(estudiante);
}

void Curso::desinscribir_estudiante(shared_ptr<Estudiante> estudiante){
    int pos = 0;
    encontrar_estudiante(estudiante, pos);
    if (pos == listado_estudiante.size()) throw invalid_argument("El estudiante que desea eliminar no se encuentra en el curso");
    listado_estudiante.erase(listado_estudiante.begin() + pos);
}

void Curso::imprimir_listado(){
    // en sort uso <, pero paso una funcion que me indica como comprar hacieno desreferencia de los punteros y usando la sobrecarga en la clase estudinate
    sort(listado_estudiante.begin(), listado_estudiante.end(), comparar_estudiantes_desreferencia);
    cout << "Listado de alumnas inscriptos al curso: " << nombr_curso << endl;
    for (const shared_ptr<Estudiante>& estudiante : listado_estudiante) {
        cout << *estudiante << endl;
    }
}
