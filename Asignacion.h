#pragma once
#include "Empleado.h"
#include "Proyecto.h"
//Clase que asigna un empleado a un proyecto
class Asignacion {
	//Atributos
private:
    int id;
    int carnet;   // solo guardamos el carnet, no el objeto completo
    Proyecto proyecto;
    string fecha;
public:
	//Constructor y metodos
    Asignacion() : id(0), carnet(0), proyecto(), fecha("") {}
    Asignacion(int id, int carnet, Proyecto proyecto, string fecha);
    //getters
    int getCarnet() { return carnet; }
    int getCodigo() { return proyecto.getCodigo(); }
    string getFecha() { return fecha; }
};
