#include "Operario.h"
//Constructor
Operario::Operario(int carnet, string nombre, string fechaNacimiento,
                   double salario, string direccion, string telefono,
                   string correo, string especialidad)
    : Empleado(carnet, nombre, fechaNacimiento, "Operario", salario, direccion, telefono, correo) {
    this->especialidad = especialidad;
}
// Muestra la informacion del operario y la especialidad
void Operario::mostrarInformacion() {
    cout << "------------------------" << endl;
    cout << "Carnet : " << carnet << endl;
    cout << "Nombre : " << nombre << endl;
    cout << "Fecha Nac : " << fechaNacimiento << endl;
    cout << "Categoria : " << categoria << endl;
    cout << "Especialidad : " << especialidad << endl;
    cout << "Salario : " << salario << endl;
    cout << "Direccion : " << direccion << endl;
    cout << "Telefono : " << telefono << endl;
    cout << "Correo : " << correo << endl;
    cout << "------------------------" << endl;
}
