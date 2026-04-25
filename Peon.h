#pragma once
#include "Empleado.h"
//Clase de un empleado que es peon
class Peon : public Empleado {
//Atributos
private:
    string tipoTrabajo;
//constructor y metodos
public:
    Peon() : Empleado(), tipoTrabajo("") {}
    Peon(int carnet, string nombre, string fechaNacimiento,
         double salario, string direccion, string telefono,
         string correo, string tipoTrabajo);
         //getter
    string getTipoTrabajo() { return tipoTrabajo; }
    //Muestra la informacion del peon
    void mostrarInformacion() ;
};
