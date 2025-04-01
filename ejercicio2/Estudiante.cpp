#include "Estudiante.hpp"


ostream& operator<<(std::ostream& os, const Estudiante& estudiante) {
    os << estudiante.nombre_completo; //el objeto os ahora es el nombre compl del estudiante con la sobrecaga
    return os;
}

double Estudiante::calcular_promedio_general(vector<pair<string, double>> cursos_notas){
    double promedio = 0;
    for(pair<string, double> datos: cursos_notas){
        double nota = datos.second;
        promedio+=nota;
    }
    promedio = promedio/ static_cast<double>(cursos_notas.size());
    return promedio;
}

Estudiante::Estudiante(string nombre, string apellido, int num_legajo, vector<pair<string,double>>cursos_notas){
    this->nombre_completo = apellido+", "+nombre;
    this->num_legajo = num_legajo;
    this->promedio_general = calcular_promedio_general(cursos_notas);
    this->cursos_notas = cursos_notas;
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
double Estudiante::getPromedio(){
    return promedio_general;

}
