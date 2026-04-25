#include "Administrador.h"
//Constructor
Administrador::Administrador(int carnet, string nombre, string fechaNacimiento,
                             double salario, string direccion, string telefono,
                             string correo, string departamento)
    : Empleado(carnet, nombre, fechaNacimiento, "Administrador", salario, direccion, telefono, correo) {
    this->departamento = departamento;
}
//Muestra la informacion del administrador con el departamento
void Administrador::mostrarInformacion() {
    cout << "------------------------"      << endl;
    cout << "Carnet : " << carnet          << endl;
    cout << "Nombre : " << nombre          << endl;
    cout << "Fecha Nac : " << fechaNacimiento << endl;
    cout << "Categoria : " << categoria       << endl;
    cout << "Departamento : " << departamento    << endl;
    cout << "Salario : " << salario         << endl;
    cout << "Direccion : " << direccion       << endl;
    cout << "Telefono : " << telefono        << endl;
    cout << "Correo : " << correo          << endl;
    cout << "------------------------"      << endl;
}
