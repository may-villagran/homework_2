#include "Tiempo.h"
//validacion de los constructores
void Tiempo::validacion_entrada_horas(int horas){
    if(horas<0 || horas>12) throw out_of_range("Por lo menos hay un valor de la hora que se encuentran fuera del rango.");
}
void Tiempo::validacion_entrada_min_segs(int minutos_segundos){
    if(minutos_segundos<0 || minutos_segundos>59) throw out_of_range("Por lo menos hay un valor de la hora que se encuentran fuera del rango.");
}
void Tiempo::validacion_entrada_abrev(string s){
    if(s != "a.m." || s!= "p.m.") throw out_of_range("la abreviatura no corresponde a las solicitadas");
}

//constructores
Tiempo::Tiempo(): horas(0), minutos(0), segundos(0), abrev("a.m.") {} //constructor por lista
Tiempo::Tiempo(int horas){
    try{
        validacion_entrada_horas(horas);
        this -> horas= horas;
    } catch (const out_of_range &e) {
        cerr<<e.what()<<endl;
    }
}
Tiempo::Tiempo(int horas, int minutos){
    try{
        validacion_entrada_horas(horas);
        validacion_entrada_min_segs(minutos);
        this -> horas= horas;
        this-> minutos = minutos;
        //si tengo distintas ecxepciones agarra la primera
    } catch (const out_of_range &e) {
        cerr<<e.what()<<endl;
    }   
}
Tiempo::Tiempo(int horas, int minutos, int segundos){
    try{
        validacion_entrada_horas(horas);
        validacion_entrada_min_segs(minutos);
        validacion_entrada_min_segs(segundos);
        this -> horas= horas;
        this -> minutos = minutos;
        this -> segundos = segundos;
        //si tengo distintas ecxepciones agarra la primera
    } catch (const out_of_range &e) {
        cerr<<e.what()<<endl;
    }
}
Tiempo::Tiempo(int horas, int minutos, int segundos, string abrev){
    try{
        validacion_entrada_horas(horas);
        validacion_entrada_min_segs(minutos);
        validacion_entrada_min_segs(segundos);
        validacion_entrada_abrev(abrev);
        this -> horas= horas;
        this -> minutos = minutos;
        this -> segundos = segundos;
        this -> abrev = abrev;
        //si tengo distintas ecxepciones agarra la primera
    } catch (const out_of_range &e) {
        cerr<<e.what()<<endl;
    }
   
}

void Tiempo::setHoras(int horas){
    this->horas = horas;
}
void Tiempo::seyMinutos(int minutos){
    this->minutos = minutos;
}
void Tiempo::setSegundos(int segundos){
    this->segundos = segundos;
}

string Tiempo::string_formato(int n, char c){
    string str_num = to_string(n); //convierto el numero en una cadena de texto
    str_num += c;
    return str_num;
}

void Tiempo::impresion_horas(){
    string h = string_formato(horas, 'h');
    cout<<setfill('0')<<setw(3)<<h<<endl;
}
void Tiempo::impresion_minutos(){
    string m = string_formato(minutos, 'm');
    cout<<setfill('0')<<setw(3)<<m<<endl;
}
void Tiempo::impresion_segundos(){
    string s = string_formato(segundos, 's');
    cout<<setfill('0')<<setw(3)<<s<<endl;
}
void Tiempo::impresion_hora_completa(){
    string h = string_formato(horas, 'h');
    string m = string_formato(minutos, 'm');
    string s = string_formato(segundos, 's');
    cout<<setfill('0');
    cout<<setw(3)<<h<<":";
    cout<<setw(3)<<m<<":";
    cout<<setw(3)<<h<<endl;
}
void Tiempo::impresion_hora_24hs(){
    if(abrev == "p.m"){
        int horas = this->horas + 12;
    }
    string h = string_formato(horas, 'h');
    string m = string_formato(minutos, 'm');
    string s = string_formato(segundos, 's');
    cout<<setfill('0');
    cout<<setw(3)<<h<<":";
    cout<<setw(3)<<m<<":";
    cout<<setw(3)<<h<<endl;
    
}

