#include "Estudiante.hpp"

Estudiante::Estudiante(string nombre, string apellido, int num_legajo){
    this->nombre_completo = apellido + ", " + nombre;
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
    int validos = 0;
    for(pair<string, float> datos: this->cursos_notas){
        float nota = datos.second;
        if(nota != -1) {
            promedio+=nota; //verifico que sea una nota valida
            validos++;
        }
    }
    promedio = promedio/validos;
    this->promedio_general = promedio;
}


void Estudiante::existe_curso(string nombre_curso, int&pos){
    pos = static_cast<int>(cursos_notas.size());
    for(int i=0; i<static_cast<int>(cursos_notas.size());i++){
        if(cursos_notas[i].first == nombre_curso) pos = i; 
    }
}


void Estudiante::definir_nota_curso(string curso_nombre, float nota_curso){
    int pos;
    existe_curso(curso_nombre, pos);
    if(pos != static_cast<int>(cursos_notas.size())) 
        cursos_notas[pos].second = nota_curso;
}

void Estudiante::incribir_curso(string curso_nombre){
    this->cursos_notas.push_back({curso_nombre, -1.0}); //agrego un pair
}

void Estudiante::desinscribir_curso(string curso_nombre){
    int pos;
    existe_curso(curso_nombre, pos);
    if(pos == static_cast<int>(cursos_notas.size())) throw invalid_argument("No se puede desiscribir, no se encontraba inscripto");
    else{
        cursos_notas.erase(cursos_notas.begin() + pos);//elimino el pair en la posicion
    }

        
}

bool Estudiante::operator<(const Estudiante& otro_estudiante){
    //comparo los nombres
    return this->nombre_completo<otro_estudiante.nombre_completo;

}

void Estudiante::imprimir_cursos(){
    cout<<"Cursos activos de: "<<nombre_completo<<endl;
    for(pair<string, float> curso : cursos_notas){
        cout<<"\t"<<curso.first<<":"<<curso.second<<endl;
    }
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
