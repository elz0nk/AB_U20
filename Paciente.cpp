#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Paciente {
private:
    string nombre;
    int id;
    string fecha_nacimiento;
    string historial_clinico;

public:
    Paciente(string nombre, int id, string fecha_nacimiento)
        : nombre(nombre), id(id), fecha_nacimiento(fecha_nacimiento) {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getFechaNacimiento() const { return fecha_nacimiento; }
    string getHistorialClinico() const { return historial_clinico; }

    void agregarHistorial(string historial) { historial_clinico += "\n" + historial; }
    void mostrarInformacion() const {
        cout << "Paciente: " << nombre << ", ID: " << id << ", Fecha de Nacimiento: " << fecha_nacimiento << endl;
        cout << "Historial Clinico: " << historial_clinico << endl;
    }
};
