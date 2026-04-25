#include "Empleado.h"
//Constructor
Empleado::Empleado(int carnet, string nombre, string fechaNacimiento, string categoria, double salario, string direccion, string telefono, string correo) {
    this->carnet = carnet;
    this->nombre = nombre;
    this->fechaNacimiento = fechaNacimiento;
    this->categoria = categoria;
    // Revisa si el salario esta fuera del rango 250000-500000 paraque sino se asigne 250000 automaticamente
    this->salario = (salario < 250000 || salario > 500000) ? 250000 : salario;
    // Si no se pone direccion, se usa "San Jose" por defecto
    this->direccion = (direccion == "") ? "San Jose" : direccion;
    this->telefono = telefono;
    this->correo = correo;
}
//Muestra la informacion del empleado
void Empleado::mostrarInformacion() {
    cout << "------------------------" << endl;
    cout << "Carnet : " << carnet << endl;
    cout << "Nombre : " << nombre << endl;
    cout << "Fecha Nac : " << fechaNacimiento << endl;
    cout << "Categoria : " << categoria << endl;
    cout << "Salario : " << salario << endl;
    cout << "Direccion : " << direccion << endl;
    cout << "Telefono : " << telefono << endl;
    cout << "Correo : " << correo << endl;
    cout << "------------------------" << endl;
}
