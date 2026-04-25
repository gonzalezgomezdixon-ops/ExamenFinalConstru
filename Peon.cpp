#include "Peon.h"
//constructor
Peon::Peon(int carnet, string nombre, string fechaNacimiento,
           double salario, string direccion, string telefono,
           string correo, string tipoTrabajo)
    : Empleado(carnet, nombre, fechaNacimiento, "Peon", salario, direccion, telefono, correo) {
    this->tipoTrabajo = tipoTrabajo;
}
//Muestra la informacion del peon y el tipo de trabajo
void Peon::mostrarInformacion() {
    cout << "------------------------" << endl;
    cout << "Carnet : " << carnet << endl;
    cout << "Nombre : " << nombre << endl;
    cout << "Fecha Nac : " << fechaNacimiento << endl;
    cout << "Categoria : " << categoria << endl;
    cout << "Tipo Trabajo : " << tipoTrabajo << endl;
    cout << "Salario : " << salario << endl;
    cout << "Direccion : " << direccion << endl;
    cout << "Telefono : " << telefono << endl;
    cout << "Correo : " << correo << endl;
    cout << "------------------------" << endl;
}
