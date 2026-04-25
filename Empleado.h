#pragma once // Es para que las clases no se lean varias veces y den errores sin ningun sentido
#include <string>
#include <iostream>
using namespace std;
//Clase base
class Empleado {
protected: //Lo use para que herede informacion de subclases
    int carnet;
    string nombre;
    string fechaNacimiento;      //Atributos
    string categoria;
    double salario;
    string direccion;
    string telefono;
    string correo;
// Constructor y metodos 
public:
    Empleado() : carnet(0), nombre(""), fechaNacimiento(""), categoria(""),
                 salario(250000), direccion("San Jose"), telefono(""), correo("") {}
    Empleado(int carnet, string nombre, string fechaNacimiento, string categoria,
             double salario, string direccion, string telefono, string correo);
    // Getters
    int getCarnet() { return carnet; }
    string getNombre() { return nombre; }
    string getCategoria() { return categoria; }
    double getSalario() { return salario; }
    string getCorreo() { return correo; }
    //Muestra la informacion
    virtual void mostrarInformacion();
};
