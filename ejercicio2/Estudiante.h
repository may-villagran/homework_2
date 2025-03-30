#include <bits/stdc++.h> //biblio estandar de c++, pair
using namespace std;


class Estudiante{
    private:
        string nombre_completo; ///<nombre del estudiante
        int num_legajo; ///<numero de legajo del estudinate, único 
        double promedio_general; ///< promedio de las notas del estudiante
        vector<pair<string, int>> cursos_notas; ///<vector de pairs (curso, nota_curso)

        void calcular_promedio_general(); 
    public:
        string getNombre();
        int getLegajo();
        double getPromedio();
};