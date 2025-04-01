#include "Curso.hpp"

Curso::Curso(string nombre): nombre_curso(nombre){} //constructor de lista
//constructor de copia shallow
Curso::Curso(const Curso &curso_original, string nombre_curso_nuevo): nombre_curso(nombre_curso_nuevo), listado_estudiantes(curso_original.listado_estudiantes){}

bool comparar_estudiantes_desreferencia(const shared_ptr<Estudiante>& estudiante1, const shared_ptr<Estudiante>& estudiante2) {
    return *estudiante1< *estudiante2;
}

vector<int> Curso::legajos_estudiantes(){
    vector<int> legajos;
    for (const shared_ptr<Estudiante>& estudiante : listado_estudiantes) {
        legajos.push_back(estudiante->getLegajo());
    }
    return legajos;
}

void Curso::encontrar_estudiante(int numero_legajo_estudiante, int &pos){
    for (int i = 0; i < listado_estudiantes.size(); i++) {
        if (listado_estudiantes[i]->getLegajo() == numero_legajo_estudiante) {
            pos = i;//si lo encunetra devuleve la pos
            return;
        }
    }
    pos = listado_estudiantes.size(); //sino quiero que devuleva el tam del arreglo
}

bool Curso::curso_completo(){
    return listado_estudiantes.size() > 20;
}

bool Curso::verificacion_inscripcion(int numero_legajo_estudiante){
    int pos = 0;
    encontrar_estudiante(numero_legajo_estudiante, pos);
    return pos != listado_estudiantes.size(); //si se retorna una pos val está el estudiante
}

void Curso::incribir_estudiante(shared_ptr<Estudiante> estudiante){
    //manejo de caso de curso completo
    if (curso_completo()) throw runtime_error("El curso se encuentra completo, no se puede agregar el estudiante");
    if (verificacion_inscripcion(estudiante->num_legajo)) throw invalid_argument("El número de legajo corresponde a otro estudiante");
    listado_estudiantes.push_back(estudiante);//agrego el puntero a estudiante
    estudiante->incribir_curso(this->nombre_curso); //incribo al estudiante desde aca
}

void Curso::desinscribir_estudiante(int numero_legajo_estudiante){
    int pos = 0;
    encontrar_estudiante(numero_legajo_estudiante, pos);
    if (pos == listado_estudiantes.size()) throw("El estudiante que desea eliminar no se encuentra en el curso");
    listado_estudiantes.erase(listado_estudiantes.begin() + pos);
}

void Curso::imprimir_listado(){
    // en sort uso <, pero paso una funcion que me indica como comprar hacieno desreferencia de los punteros y usando la sobrecarga en la clase estudinate
    sort(listado_estudiantes.begin(), listado_estudiantes.end(), comparar_estudiantes_desreferencia);
    cout << "Listado de alumnos inscriptos al curso: " << nombre_curso << endl;
    for (const shared_ptr<Estudiante>& estudiante : listado_estudiantes) {
        cout << *estudiante << endl;
    }
}
