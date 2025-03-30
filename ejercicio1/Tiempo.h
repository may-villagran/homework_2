#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Tiempo {
    private:
        int horas; ///< Horas del dia (0-12)
        int minutos;///< Minutos (0-59)
        int segundos;///<Segundos (0-59) 
        string abrev; ///< Abreviatura que me indica si es a.m. o
        void validacion_entrada_horas(int horas);
        void validacion_entrada_min_segs(int minutos);
        void validacion_entrada_abrev(string s);
        string string_formato(int n, char c);

    public:
        Tiempo(); //constructor 1 sin parámetros
        Tiempo(int horas);
        Tiempo(int horas, int minutos, int ssegundos, string abrev);
        Tiempo(int horas, int minutos);
        Tiempo(int horas, int minutos, int segundos);
        void setHoras(int horas);
        void setMinutos(int minutos);
        void setSegundos(int segundos);
        void setAbrev(string abrev);
        void impresion_horas();
        void impresion_minutos();
        void impresion_segundos();
        void impresion_hora_completa();
        void impresion_hora_24hs();



    



};
