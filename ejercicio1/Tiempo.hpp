#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * Clase Tiempo que representa una hora con formato y validación.
 */
class Tiempo
{
private:
    int horas;         ///< Horas en formato 12 horas (0-12).
    int minutos;       ///< Minutos en el rango permitido (0-59).
    int segundos;      ///< Segundos en el rango permitido (0-59).
    string abrev;      ///< Abreviatura para la hora ("a.m." o "p.m.").

    /**
     * Valida que las horas estén dentro del rango permitido.
     * @param horas Horas que deben estar entre 0 y 12.
     * @throw out_of_range Si las horas no están dentro del rango permitido.
     */
    void validacion_entrada_horas(int horas);

    /**
     * Valida que los minutos o segundos estén dentro del rango permitido.
     * @param minutos_segundos Minutos o segundos que deben estar entre 0 y 59.
     * @throw out_of_range Si los minutos o segundos no están dentro del rango permitido.
     */
    void validacion_entrada_min_segs(int minutos_segundos);

    /**
     * Valida que la abreviatura sea correcta ("a.m." o "p.m.").
     * @param s Abreviatura que debe ser "a.m." o "p.m.".
     * @throw out_of_range Si la abreviatura no corresponde a las solicitadas.
     */
    void validacion_entrada_abrev(string s);


        /**
     * Devuelve un número en formato de cadena seguido de un carácter.
     * @param n Número a convertir en cadena.
     * @param c Carácter que se añadirá al final.
     * @return Cadena formateada con el número y el carácter.
     */
    string string_formato(int n, char c);


public:
    /**
     * Constructor por defecto que inicializa la hora en 00:00:00 a.m.
     */
    Tiempo();

    /**
     * Constructor que inicializa solo las horas.
     * @param horas Horas en formato 12 horas.
     */
    Tiempo(int horas);

    /**
     * Constructor que inicializa las horas y minutos.
     * @param horas Horas en formato 12 horas.
     * @param minutos Minutos en el rango permitido (0-59).
     */
    Tiempo(int horas, int minutos);

    /**
     * Constructor que inicializa las horas, minutos y segundos.
     * @param horas Horas en formato 12 horas.
     * @param minutos Minutos en el rango permitido (0-59).
     * @param segundos Segundos en el rango permitido (0-59).
     */
    Tiempo(int horas, int minutos, int segundos);

    /**
     * Constructor que inicializa las horas, minutos, segundos y abreviatura.
     * @param horas Horas en formato 12 horas.
     * @param minutos Minutos en el rango permitido (0-59).
     * @param segundos Segundos en el rango permitido (0-59).
     * @param abrev Abreviatura ("a.m." o "p.m.").
     */
    Tiempo(int horas, int minutos, int segundos, string abrev);

    /**
     * Establece las horas después de validarlas.
     * @param horas Horas en formato 12 horas.
     */
    void setHoras(int horas);

    /**
     * Establece los minutos después de validarlos.
     * @param minutos Minutos en el rango permitido (0-59).
     */
    void setMinutos(int minutos);

    /**
     * Establece los segundos después de validarlos.
     * @param segundos Segundos en el rango permitido (0-59).
     */
    void setSegundos(int segundos);

    /**
     * Establece la abreviatura ("a.m." o "p.m.") después de validarla.
     * @param abrev Abreviatura que debe ser "a.m." o "p.m.".
     */
    void setAbrev(string abrev);

    /**
     * Imprime las horas formateadas.
     */
    void impresion_horas();

    /**
     * Imprime los minutos formateados.
     */
    void impresion_minutos();

    /**
     * Imprime los segundos formateados.
     */
    void impresion_segundos();

    /**
     * Imprime la hora completa en formato 12 horas con abreviatura.
     */
    void impresion_hora_completa();

    /**
     * Imprime la hora en formato de 24 horas.
     */
    void impresion_hora_24hs();
};

