#include "Estudiante.hpp"

Estudiante::Estudiante(string nombre, string apellido, int num_legajo){
    this->nombre_completo = apellido+", "+nombre;
    this->num_legajo = num_legajo;
    this->promedio_general = 0;
}


//Metodo internos
ostream& operator<<(std::ostream& os, const Estudiante& estudiante) {
    os << estudiante.nombre_completo; //el objeto os ahora es el nombre compl del estudiante con la sobrecaga
    return os;
}

void Estudiante::calcular_promedio_general(){
    float promedio = 0;
    for(pair<string, float> datos: this->cursos_notas){
        float nota = datos.second;
        if(nota != -1) promedio+=nota; //verifico que sea una nota valida
    }
    promedio = promedio/ static_cast<float>(cursos_notas.size());
    this->promedio_general = promedio;
}

void Estudiante::definir_nota_curso(string curso_nombre, float nota_curso){
    for(pair<string, float> &datos: this->cursos_notas){
        if(curso_nombre == datos.first){
            //encontro el curso
            datos.second = nota_curso; //seteo la nota para el curso
        }
    }
}

void Estudiante::incribir_curso(string curso_nombre){
    this->cursos_notas.push_back({curso_nombre, -1.0}); //agrego un pair
}

bool Estudiante::operator<(const Estudiante& otro_estudiante){
    //comparo los nombres
    return this->nombre_completo<otro_estudiante.nombre_completo;

}

string Estudiante::getNombre(){
    return nombre_completo;
}
int Estudiante::getLegajo(){
    return num_legajo;
}
float Estudiante::getPromedio(){
    calcular_promedio_general();//actualizo el promedio antes
    return promedio_general;

}
