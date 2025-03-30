#pragma once
#include <algorithm>
#include <bits/stdc++.h> //biblio estandar de c++, pair
#include <string>
#include <iostream>
using namespace std;


class Estudiante{
    private:
        string nombre_completo; ///<nombre del estudiante
        int num_legajo; ///<numero de legajo del estudinate, único 
        double promedio_general; ///< promedio de las notas del estudiante
        vector<pair<string, double>> cursos_notas; ///<vector de pairs (curso, nota_curso)
        
        double calcular_promedio_general(vector<pair<string, double>> cursos_notas); 
    public:
        //sobrecarga de operadores:
        Estudiante(string nombre, string apellido, int num_legajo, vector<pair<string,double>>cursos_notas);
        bool operator<(const Estudiante& otro_estudiante);
        //sobrecraga del operador <<, como pertece al cout, debo ponerlo como friend para que tenga acceso al atributo del nombre que es privado
        friend ostream& operator<<(ostream& os, const Estudiante& estudiante);
        

        //Métodos para obtener los datos
        
        string getNombre();
        int getLegajo();
        double getPromedio();
};