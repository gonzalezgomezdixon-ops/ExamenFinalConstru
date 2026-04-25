#include "Asignacion.h"
//Constructor
Asignacion::Asignacion(int id, int carnet, Proyecto proyecto, string fecha)
    : proyecto(proyecto) {
    this->id = id;
    this->carnet = carnet;
    this->fecha  = fecha;
}
