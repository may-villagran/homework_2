#include "Numero.hpp"
#include "Real.hpp"
#include "Entero.hpp"
#include "Complejo.hpp"



int main(){
    cout << "Enteros:" << endl;
    unique_ptr<Numero> num1 = make_unique<Entero>(23);
    unique_ptr<Numero> num2 = make_unique<Entero>(12);
    num2->to_string();
    num1->to_string();
    unique_ptr<Numero> num3 = *num1 + *num2;
    cout << "Suma: ";
    num3->to_string();
    unique_ptr<Numero> num4 = *num1 - *num2;
    cout << "Resta: ";
    num4->to_string();
    unique_ptr<Numero> num5 = *num1 * *num2;
    cout << "Producto: ";     
    num5->to_string();


    cout << "Reales:" << endl;
    unique_ptr<Numero> real1 = make_unique<Real>(23.5);
    unique_ptr<Numero> real2 = make_unique<Real>(12.3);
    real2->to_string();
    real1->to_string();
    unique_ptr<Numero> real3 = *real1 + *real2;

    cout << "Suma: ";
    real3->to_string();
    unique_ptr<Numero> real4 = *real1 - *real2;
    cout << "Resta: ";
    real4->to_string();
    unique_ptr<Numero> real5 = *real1 * *real2;
    cout << "Producto: ";
    real5->to_string();

    cout << "Complejos:" << endl;
    unique_ptr<Numero> comp1 = make_unique<Complejo>(2.0, 3.0);
    unique_ptr<Numero> comp2 = make_unique<Complejo>(1.0, 4.0);
    comp1->to_string();
    comp2->to_string();
    unique_ptr<Numero> comp3 = *comp1 + *comp2;
    cout << "Suma: ";
    comp3->to_string();
    unique_ptr<Numero> comp4 = *comp1 - *comp2;
    cout << "Resta: ";
    comp4->to_string();
    unique_ptr<Numero> comp5 = *comp1 * *comp2;
    cout << "Producto: ";
    comp5->to_string();
    




}