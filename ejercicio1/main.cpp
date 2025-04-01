#include "Tiempo.hpp"

void menu_inicial()
{
    cout << "Menú de opciones:" << endl;
    cout << "1. Inicializar sin parámetros" << endl;
    cout << "2. Inicializar con hora (0-12)" << endl;
    cout << "3. Inicializar con hora y minutos(0-59)" << endl;
    cout << "4. Inicializar con hora(0-12), minutos(0-59) y segundos (0-59)" << endl;
    cout << "5. Inicializar con hora(0-12), minutos(0-59), segundos (0-59) y parte del día (a.m. | p.m.) " << endl;
    cout << "Seleccione una opción:" << endl;
    
}

void menu_funcionalidades()
{
    cout << "Menú de opciones del tiempo creado:" << endl;
    cout << "1. Setear hora (0-12)" << endl;
    cout << "2. Setear minutos (0-59)" << endl;
    cout << "3. Setear segundos (0-59)" << endl;
    cout << "4. Setear parte del día (a.m. | p.m.)" << endl;
    cout << "5. Imprimir hora" << endl;
    cout << "6. Imprimir minutos" << endl;
    cout << "7. Imprimir segundos" << endl;
    cout << "8. Imprimir formato 12 hrs" << endl;
    cout << "9. Imprimir formato 24 hrs" << endl;
    cout << "10. Salir" << endl;
    cout << "Seleccione una opción: " << endl;
}

void menu_error_rango()
{
    cout << "Ingrese una opción:" << endl;
    cout << "1. volver a ingresar los valores" << endl;
    cout << "2. salir del programa" << endl;
}

int main()
{
    Tiempo tiempo;
    int opcion = 0;
    do
    {
        menu_inicial();
        cin >> opcion;
        int horas, minutos, segundos;
        string abrev;
        // intenta crear cualquiera sean las opciones
        try
        {
            // opciones principales
            switch (opcion)
            {
            case 1:
                tiempo = Tiempo();
                break;

            case 2:
            {
                cout << "Ingrese las horas: ";
                cin >> horas;
                tiempo = Tiempo(horas);
                break;
            }

            case 3:
            {
                cout << "Ingrese las horas: ";
                cin >> horas;
                cout << "Ingrese los minutos: ";
                cin >> minutos;
                tiempo = Tiempo(horas, minutos);
                break;
            }

            case 4:
            {
                cout << "Ingrese las horas: ";
                cin >> horas;
                cout << "Ingrese los minutos: ";
                cin >> minutos;
                cout << "Ingrese los segundos: ";
                cin >> segundos;
                tiempo = Tiempo(horas, minutos, segundos);
                break;
            }

            case 5:
            {
                cout << "Ingrese las horas: ";
                cin >> horas;
                cout << "Ingrese los minutos: ";
                cin >> minutos;
                cout << "Ingrese los segundos: ";
                cin >> segundos;
                cout << "Ingrese el periodo (a.m./p.m.): ";
                cin >> abrev;
                tiempo = Tiempo(horas, minutos, segundos, abrev);
                break;
            }
            }

            do
            {
                menu_funcionalidades();
                cin >> opcion;
                // opciones con el tiempo inicializado
                switch (opcion)
                {
                case 1:
                {
                    cout << "Ingrese las horas: ";
                    cin >> horas;
                    tiempo.setHoras(horas);
                    break;
                }
                case 2:
                {
                    cout << "Ingrese los minutos: ";
                    cin >> minutos;
                    tiempo.setMinutos(minutos);
                    break;
                }
                case 3:
                {
                    cout << "Ingrese los segundos: ";
                    cin >> segundos;
                    tiempo.setSegundos(segundos);
                    break;
                }
                case 4:
                {
                    cout << "Ingrese la abreviatura (AM/PM): ";
                    cin >> abrev;
                    tiempo.setAbrev(abrev);
                    break;
                }
                case 5:
                {
                    cout<<"Horas: ";
                    tiempo.impresion_horas();
                    break;
                }
                case 6:
                {
                    cout<<"Minutos: ";
                    tiempo.impresion_minutos();
                    break;
                }
                case 7:
                {
                    cout<<"Segundos: ";
                    tiempo.impresion_segundos();
                    break;
                }
                case 8:
                {
                    cout<<"Hora en formato 12hrs: ";
                    tiempo.impresion_hora_completa();
                    break;
                }
                case 9:
                {
                    cout<<"Hora en formato 24hrs: ";
                    tiempo.impresion_hora_24hs();
                    break;
                }
                }
                cout << setfill('-') << setw(50) << "" << endl; 

            } while (opcion < 10 && opcion > 0);
            break;
        }
        // si en alguno de los casos salta de out of range de los métodos de validación de datoss, vuelvo a pedir los datos
        catch (const out_of_range &e)
        {
            cout << e.what() << endl;

            menu_error_rango();
            cin >> opcion;
            if (opcion == 1)
                continue; // vuelvo a darle las opciones
            else if (opcion == 2)
                break; // rompo el ciclo y salgo
        }
    } while (true);

    return 0;
}
