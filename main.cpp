#include <iostream>
#include <limits>//Lo use porque lo vi en un video y vi que funciona para limpiar el buffer del teclado entre lineas
#include "Administrador.h"
#include "Operario.h"
#include "Peon.h"
#include "Proyecto.h"
#include "Asignacion.h"
using namespace std;
//Arreglos
Administrador admins[10];
Operario operarios[10];
Peon peones[10];
Proyecto proyectos[10];
Asignacion asignaciones[20];
//Contadores
int totalAdmins=0, totalOperarios=0, totalPeones=0, totalProyectos=0, totalAsignaciones=0;
int contadorId=1, contadorCod=1, totalCorreos=0;
string correos[30];
//Funcion de buscar
int buscarAdmin(int c) { for(int i=0;i<totalAdmins;i++) if(admins[i].getCarnet()==c) return i; return -1; }
int buscarOperario(int c) { for(int i=0;i<totalOperarios;i++) if(operarios[i].getCarnet()==c) return i; return -1; }
int buscarPeon(int c) { for(int i=0;i<totalPeones;i++) if(peones[i].getCarnet()==c) return i; return -1; }
int buscarProyecto(int c) { for(int i=0;i<totalProyectos;i++) if(proyectos[i].getCodigo()==c) return i; return -1; }

bool carnetExiste(int c) { return buscarAdmin(c)!=-1 || buscarOperario(c)!=-1 || buscarPeon(c)!=-1; }
bool correoExiste(string co) { for(int i=0;i<totalCorreos;i++) if(correos[i]==co) return true; return false; }
bool asignacionExiste(int ca, int cp) {
    for(int i=0;i<totalAsignaciones;i++)
        if(asignaciones[i].getCarnet()==ca && asignaciones[i].getCodigo()==cp) return true;
    return false;
}

// Muestra la informacion del empleado luego de buscarlo 
void mostrarEmpleadoPorCarnet(int c) {
    int pA=buscarAdmin(c), pO=buscarOperario(c), pP=buscarPeon(c);
    if(pA!=-1) admins[pA].mostrarInformacion();
    else if(pO!=-1) operarios[pO].mostrarInformacion();
    else if(pP!=-1) peones[pP].mostrarInformacion();
}
//menu de los empleados
void menuEmpleados() {
    int op;
    do {
        cout << "\n=== MENU EMPLEADOS ===" << endl;
        cout << "1-Ver  2-Admin  3-Operario  4-Peon  5-Salir: ";
        cin >> op;
        switch(op) {
        	//Muestra los empleados registrados
            case 1:
                if(totalAdmins==0 && totalOperarios==0 && totalPeones==0)
                    cout << "No hay empleados registrados." << endl;
                else {
                    for(int i=0;i<totalAdmins;i++) admins[i].mostrarInformacion();
                    for(int i=0;i<totalOperarios;i++) operarios[i].mostrarInformacion();
                    for(int i=0;i<totalPeones;i++) peones[i].mostrarInformacion();
                }
                break;
            case 2: case 3: case 4: {
                int c, anio; string nom, fNac, dir, tel, co, extra; double sal;
                //Valida los carnet unicos
                cout << "Carnet : "; cin >> c;
                if(carnetExiste(c)) { cout << "Carnet ya existe." << endl; break; }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nombre : "; getline(cin, nom);
                //Valida la edad ya que los que son 2007 para arriba los lee como menores de edad
                cout << "Anio Nac : "; cin >> anio;
                if(anio > 2007) { cout << "No se puede contratar menores de edad." << endl; break; }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Fecha Nac : "; getline(cin, fNac);
                cout << "Salario : "; cin >> sal;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Direccion : "; getline(cin, dir);
                cout << "Telefono : "; getline(cin, tel);
                //Valida el correo si ya existe
                cout << "Correo : "; getline(cin, co);
                if(correoExiste(co)) { cout << "Correo ya existe." << endl; break; }
                switch(op) {
                    case 2: cout << "Departamento: "; getline(cin,extra); admins[totalAdmins++] = Administrador(c,nom,fNac,sal,dir,tel,co,extra); cout << "Administrador agregado." << endl; break;
                    case 3: cout << "Especialidad: "; getline(cin,extra); operarios[totalOperarios++] = Operario(c,nom,fNac,sal,dir,tel,co,extra); cout << "Operario agregado." << endl; break;
                    case 4: cout << "Tipo trabajo: "; getline(cin,extra); peones[totalPeones++] = Peon(c,nom,fNac,sal,dir,tel,co,extra); cout << "Peon agregado." << endl; break;
                }
                //Registro de correo para futuro
                correos[totalCorreos++] = co;
                break;
            }
        }
    } while(op!=5);
}
//Menu proyectos
void menuProyectos() {
    int op;
    do {
        cout << "\n=== MENU PROYECTOS ===" << endl;
        cout << "1-Ver  2-Agregar  3-Salir: ";
        cin >> op;
        switch(op) {
        	//Muestra todos los proyectos que ya se registraron
            case 1:
                if(totalProyectos==0) cout << "No hay proyectos registrados." << endl;
                else for(int i=0;i<totalProyectos;i++) proyectos[i].mostrarInformacion();
                break;
                //Agrega nuevos proyectos
            case 2: {
                string nom, fi, ff;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nombre : "; getline(cin,nom);
                cout << "Inicio : "; getline(cin,fi);
                cout << "Fin : "; getline(cin,ff);
                proyectos[totalProyectos++] = Proyecto(contadorCod++,nom,fi,ff);
                cout << "Proyecto agregado." << endl;
                break;
            }
        }
    } while(op!=3);
}
//menu asignaciones
void menuAsignaciones() {
    int op;
    do {
        cout << "\n=== MENU ASIGNACIONES ===" << endl;
        cout << "1-Crear  2-Ver  3-Por proyecto  4-Por empleado  5-Salir: ";
        cin >> op;
        switch(op) {
        	//crea las asignaciones si el proyecto y el empleado existen
            case 1: {
                int carnet, cod; string fecha;
                cout << "Carnet empleado : "; cin >> carnet;
                cout << "Codigo proyecto : "; cin >> cod;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Fecha : "; getline(cin,fecha);
                int pA=buscarAdmin(carnet), pO=buscarOperario(carnet), pP=buscarPeon(carnet), pPr=buscarProyecto(cod);
                if(pA==-1 && pO==-1 && pP==-1) cout << "Empleado no encontrado." << endl;
                else if(pPr==-1) cout << "Proyecto no encontrado." << endl;
                else if(asignacionExiste(carnet,cod)) cout << "Asignacion ya existe." << endl;
                else {
                    // Guardam solo el carnet para evitar object slicing con las subclases
                    asignaciones[totalAsignaciones++] = Asignacion(contadorId++, carnet, proyectos[pPr], fecha);
                    cout << "\nAsignacion creada." << endl;
                    cout << "=== ASIGNACION ID: " << contadorId-1 << " ===" << endl;
                    cout << "Fecha: " << fecha << endl;
                    cout << "Empleado:" << endl;
                    mostrarEmpleadoPorCarnet(carnet);
                    cout << "Proyecto:" << endl;
                    proyectos[pPr].mostrarInformacion();
                }
                break;
            }
            //Muestra todas las asignaciones
            case 2:
                if(totalAsignaciones==0) cout << "No hay asignaciones registradas." << endl;
                else {
                    for(int i=0;i<totalAsignaciones;i++) {
                        cout << "\n=== ASIGNACION ID: " << i+1 << " ===" << endl;
                        cout << "Fecha: " << asignaciones[i].getFecha() << endl;
                        cout << "Empleado:" << endl;
                        mostrarEmpleadoPorCarnet(asignaciones[i].getCarnet());
                        cout << "Proyecto:" << endl;
                        int pPr = buscarProyecto(asignaciones[i].getCodigo());
                        if(pPr!=-1) proyectos[pPr].mostrarInformacion();
                    }
                }
                break;
                //Muestra todos los empleados asignados para un proyecto
            case 3: {
                int cod, encontrados=0; cout << "Codigo proyecto: "; cin >> cod;
                for(int i=0;i<totalAsignaciones;i++) {
                    if(asignaciones[i].getCodigo()==cod) {
                        cout << "\n=== ASIGNACION ID: " << i+1 << " ===" << endl;
                        cout << "Fecha: " << asignaciones[i].getFecha() << endl;
                        cout << "Empleado:" << endl;
                        mostrarEmpleadoPorCarnet(asignaciones[i].getCarnet());
                        encontrados++;
                    }
                }
                if(encontrados==0) cout << "No hay empleados en ese proyecto." << endl;
                break;
            }
            //Muestra todos los proyectos asignados a un empleado
            case 4: {
                int c, encontrados=0; cout << "Carnet empleado: "; cin >> c;
                for(int i=0;i<totalAsignaciones;i++) {
                    if(asignaciones[i].getCarnet()==c) {
                        cout << "\n=== ASIGNACION ID: " << i+1 << " ===" << endl;
                        cout << "Fecha: " << asignaciones[i].getFecha() << endl;
                        cout << "Proyecto:" << endl;
                        int pPr = buscarProyecto(asignaciones[i].getCodigo());
                        if(pPr!=-1) proyectos[pPr].mostrarInformacion();
                        encontrados++;
                    }
                }
                if(encontrados==0) cout << "Ese empleado no tiene proyectos asignados." << endl;
                break;
            }
        }
    } while(op!=5);
}
//menu principal
int main() {
    int op;
    do {
        cout << "\n=== CONSTRUCTORES AVANCE ===" << endl;
        cout << "1-Empleados  2-Proyectos  3-Asignaciones  4-Salir: ";
        cin >> op;
        switch(op) {
            case 1: menuEmpleados(); break;
            case 2: menuProyectos(); break;
            case 3: menuAsignaciones(); break;
        }
    } while(op!=4);//Se cierra el programa cuando le den la opcion 4
    cout << "Hasta Pronto" << endl;
    return 0;
}
