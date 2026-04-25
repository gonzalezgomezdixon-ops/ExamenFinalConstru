#pragma once
#include "Empleado.h"
//Clase de que un empleado puede ser administrador
class Administrador : public Empleado {
	//Atributos
private:
    string departamento;
    // Constructor y metodos
public:
    Administrador() : Empleado(), departamento("") {}
    Administrador(int carnet, string nombre, string fechaNacimiento,
                  double salario, string direccion, string telefono,
                  string correo, string departamento);
    //getter
    string getDepartamento() { return departamento; }
    //Muestra la informacion del administrador
    void mostrarInformacion() ;
};
