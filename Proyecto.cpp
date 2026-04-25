#include "Proyecto.h"
//contructor
Proyecto::Proyecto(int codigo, string nombre, string fechaInicio, string fechaFin) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
}
// Muestra la informacion completa del proyecto
void Proyecto::mostrarInformacion() {
    cout << "------------------------" << endl;
    cout << "Codigo : " << codigo << endl;
    cout << "Nombre : " << nombre << endl;
    cout << "Inicio : " << fechaInicio << endl;
    cout << "Fin : " << fechaFin << endl;
    cout << "------------------------" << endl;
}
