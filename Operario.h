#pragma once
#include "Empleado.h"
//Clase de un empleado que es Operario
class Operario : public Empleado {
	//Atributos
private:
    string especialidad;
    //Constructor y metodos
public:
    Operario() : Empleado(), especialidad("") {}
    Operario(int carnet, string nombre, string fechaNacimiento,
             double salario, string direccion, string telefono,
             string correo, string especialidad);
    //getter
    string getEspecialidad() { return especialidad; }
    //Muestra la informacion del operario
    void mostrarInformacion() ;
};
