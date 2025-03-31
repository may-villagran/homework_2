#include <iostream>
#include "Curso.h" // Asegúrate de que el archivo de encabezado esté correctamente incluido

void menu_inicial()
{
    cout << "Menú de opciones:" << endl;
    cout << "1. Inicializar curso" << endl;
    cout << "2. Mostrar curso" << endl;
    cout << "3. Crear estudiante" << endl;
    cout << "4. Salir" << endl;
}



int main()
{
    int opcion;
    try{
        











    }
    catch(const runtime_error &e){
        cerr<<e.what()<<endl; //curso lleno, no se pueden agregar más estudiantes
    }
    catch(const invalid_argument & e){
        cerr<<e.what()<<endl; //caso donde el legajo ya esta en el curso
    }
    catch(const char* msj_estudiante_invalido){
        cerr<<msj_estudiante_invalido;//caso donde se intenta borrar un estudiante que no está en el curso
    }


    return 0;
}
