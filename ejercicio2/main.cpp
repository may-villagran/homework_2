#include <iostream>
#include "Curso.hpp" // Asegúrate de que el archivo de encabezado esté correctamente incluido

void mostrarMenu()
{
    cout << "\nMenu de opciones" << endl;
    cout << "1. Crear Estudiante" << endl;
    cout << "2. Crear Curso" << endl;
    cout << "3. Inscribir Estudiante a un Curso" << endl;
    cout << "4. Desinscribir Estudiante de un Curso" << endl;
    cout << "5. Cambiar nota del Estudiante" << endl;
    cout << "6. Mostrar info de un Estudiante" << endl;
    cout << "7. Mostrar info de Curso" << endl;
    cout << "8. Mostrar Estudiantes activos" << endl;
    cout << "9. Mostrar Cursos activos" << endl;
    cout << "10. Copiar Curso, cambiando el nombre" << endl;
    cout << "11. Salir" << endl;
    cout << "Seleccione una opción:";
}

// son repetitivas, se puede usar find de algorithm??
void buscar_estudiante(vector<shared_ptr<Estudiante>> estudiantes_activos, int numero_legajo_estudiante, int &pos)
{
    pos = static_cast<int>(estudiantes_activos.size()); // sino quiero que devuleva el tam del arreglo
    for (int i = 0; i < static_cast<int>(estudiantes_activos.size()); i++)
    {
        if (estudiantes_activos[i]->getLegajo() == numero_legajo_estudiante)
        {
            pos = i; // si lo encunetra devuleve la pos
            return;
        }
    }
}

void buscar_curso(vector<shared_ptr<Curso>> cursos_activos, string nombre_curso, int &pos)
{
    pos = static_cast<int>(cursos_activos.size()); // sino quiero que devuleva el tam del arreglo
    for (int i = 0; i < static_cast<int>(cursos_activos.size()); i++)
    {
        if (cursos_activos[i]->nombre_curso == nombre_curso)
        {
            pos = i; // si lo encunetra devuleve la pos
            return;
        }
    }
}

int main()
{
    // estudiantes y cursos activos
    vector<shared_ptr<Estudiante>> estudiantes_activos;
    vector<shared_ptr<Curso>> cursos_activos;
    // Inicialización del curso
    cursos_activos.push_back(make_shared<Curso>("curso1"));
    // Creación de 19 estudiantes e inscripción en el curso
    for (int i = 1; i <= 19; i++)
    {
        shared_ptr<Estudiante> estudiante = make_shared<Estudiante>("nombre" + to_string(i), "apellido" + to_string(i), i);
        estudiantes_activos.push_back(estudiante);
        cursos_activos[0]->incribir_estudiante(estudiante);
    }
    cout << "El programa se encuentra con un curso, con nombre \"curso1\" inicializado con 19 estudiantes" << endl;

    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            string nombre, apellido;
            int num_legajo;
            cout << "Introduce el nombre del Estudiante: ";
            cin >> nombre;
            cout << "Introduce el apellido del Estudiante: ";
            cin >> apellido;
            cout << "Introduce el numero de legajo del Estudiante: ";
            cin >> num_legajo;
            estudiantes_activos.push_back(make_shared<Estudiante>(nombre, apellido, num_legajo));
            cout << "El estudiante se ha inicializado.\n";
            break;
        }
        case 2:
        {
            string nombre_curso;
            cout << "Introduce el nombre del curso: ";
            cin >> nombre_curso;
            cursos_activos.push_back(make_shared<Curso>(nombre_curso));
            cout << "El curso se ha inicializado.\n";
            break;
        }

        case 3:
        {
            try
            {
                int num_legajo;
                string nombre_curso;
                cout << "Introduce el numero de legajo del Estudiante a inscribir: ";
                cin >> num_legajo;
                cout << "Introduce el nombre del curso a inscribir: ";
                cin >> nombre_curso;
                int pos_e, pos_c;
                buscar_curso(cursos_activos, nombre_curso, pos_c);
                buscar_estudiante(estudiantes_activos, num_legajo, pos_e);

                if (pos_c == static_cast<int>(cursos_activos.size()) || pos_e == static_cast<int>(estudiantes_activos.size()))
                    cout << "El estudiante o el curso no existe, no se pudo agregar el estudiante" << endl;
                else
                {
                    cursos_activos[pos_c]->incribir_estudiante(estudiantes_activos[pos_e]); // si esta paso el ptr del estudiante
                    // la funncion se encarga de ajustar en estudiante y en el curso
                    cout << "Se inscribio el estudiante al curso" << endl;
                }
            }

            catch (const runtime_error &e)
            {
                cout << e.what(); // caso donde el curso se encuentra completo
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl; // se intenta crear un estudiante con un numero de legajo existemte
                continue;
            }

            break;
        }

        case 4:
        {
            try
            {
                int num_legajo;
                string nombre_curso;
                cout << "Introduce el numero de legajo del Estudiante a desinscribir: ";
                cin >> num_legajo;
                cout << "Introduce el nombre del curso a desincribir: ";
                cin >> nombre_curso;
                int pos_e, pos_c;
                buscar_curso(cursos_activos, nombre_curso, pos_c);
                buscar_estudiante(estudiantes_activos, num_legajo, pos_e);

                if (pos_c == static_cast<int>(cursos_activos.size()) || pos_e == static_cast<int>(estudiantes_activos.size()))
                    cout << "El estudiante o el curso no existe, no se pudo agregar el estudiante" << endl;
                else
                {
                    cursos_activos[pos_c]->desinscribir_estudiante(estudiantes_activos[pos_e]->getLegajo()); // si esta paso el num de legajo del estudiante
                    // la funncion se encarga de ajustar en estudiante y en el curso
                    cout << "Se desincribio el estudiante al curso" << endl;
                }
                break;
            }
            catch (const char *mensaje)
            {
                cout << mensaje << endl; // caso donde intento desinscribir y no existe el alumno en el curso
                continue;
            }
        }

        case 5:
        {
            int num_legajo;
            string nombre_curso;
            float nueva_nota;
            cout << "Introduce el numero de legajo del Estudiante: ";
            cin >> num_legajo;
            cout << "Introduce el nombre del curso: ";
            cin >> nombre_curso;
            cout << "Introduce la nueva nota: ";
            cin >> nueva_nota;

            int pos_e, pos_c;
            buscar_curso(cursos_activos, nombre_curso, pos_c);
            buscar_estudiante(estudiantes_activos, num_legajo, pos_e);

            if (pos_c == static_cast<int>(cursos_activos.size()) || pos_e == static_cast<int>(estudiantes_activos.size()))
                cout << "El estudiante o el curso no existe, no se pudo cambiar la nota" << endl;
            else
                estudiantes_activos[pos_e]->definir_nota_curso(cursos_activos[pos_c]->nombre_curso, nueva_nota);
            break;
        }
        case 6:
        {
            int num_legajo;
            cout << "Ingrese numero de legajo del estudiante: ";
            cin >> num_legajo;
            int pos_e;
            buscar_estudiante(estudiantes_activos, num_legajo, pos_e);
            if (pos_e == static_cast<int>(estudiantes_activos.size()))
                cout << "El estudiante no existe." << endl;
            else
            {
                cout << "Informacion del estudiante:" << endl;
                // uso de los metodos de obtener datos
                cout << "Nombre: " << estudiantes_activos[pos_e]->getNombre() << endl;
                cout << "Legajo: " << estudiantes_activos[pos_e]->getLegajo() << endl;
                cout << "Promedio: " << estudiantes_activos[pos_e]->getPromedio() << endl;
                estudiantes_activos[pos_e]->imprimir_cursos(); // uso el metodo que me las materias
                cout << endl;
            }
            break;
        }
        case 7:
        {
            string nombre_curso;
            cout << "Ingrese el nombre del curso: ";
            cin >> nombre_curso;
            int pos_c;
            buscar_curso(cursos_activos, nombre_curso, pos_c);
            if (pos_c == static_cast<int>(cursos_activos.size()))
                cout << "El curso no existe." << endl;
            else
                cursos_activos[pos_c]->imprimir_listado();
            break;
        }
        case 8:
        {
            cout << "Listado de estudiantes activos:\n";
            for (const auto &estudiante : estudiantes_activos)
                cout << estudiante->getNombre() << " con numero de legajo: " << estudiante->getLegajo() << endl;
            break;
        }
        case 9:
        {
            cout << "Listado de cursos activos:\n";
            for (const auto &curso : cursos_activos)
                cout << curso->nombre_curso << endl;
            break;
        }
        case 10:
        {
            string nombre_curso;
            cout << "Ingrese el nombre del curso a copiar estudiantes: ";
            cin >> nombre_curso;

            string nombre_nuevo;
            cout << "Ingrese el nombre del neuvo curso: ";
            cin >> nombre_nuevo;

            int pos_c;
            buscar_curso(cursos_activos, nombre_curso, pos_c);
            if (pos_c == static_cast<int>(cursos_activos.size()))
                cout << "El curso no existe." << endl;
            else
            {
                cursos_activos.push_back(make_shared<Curso>(*cursos_activos[pos_c], nombre_nuevo));
            }
            break;
        }

        case 11:
        {
            cout << "Saliendo del programa" << endl;
            break;
        }
        default:
            cout << "Opción no válida" << endl;
        }
    } while (opcion != 11);

    return 0;
}