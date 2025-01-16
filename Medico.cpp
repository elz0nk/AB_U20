#include <iostream>
#include <string>
using namespace std;

class Medico {
private:
    string nombre;
    int id;
    string especialidad;

public:
    Medico(string nombre, int id, string especialidad)
        : nombre(nombre), id(id), especialidad(especialidad) {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getEspecialidad() const { return especialidad; }
    
    void mostrarInformacion() const {
        cout << "Medico: " << nombre << ", ID: " << id << ", Especialidad: " << especialidad << endl;
    }
};
