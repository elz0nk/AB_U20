#include <iostream>
#include <vector>
#include <string>
#include "Fecha.h"

#ifndef PACIENTE_H
#define PACIENTE_H

using namespace std;

class Paciente {
public:
    string nombre;
    string identificacion;
    Fecha fecha_ingreso;
    string direccion;
    vector<string> historial_clinico;

    Paciente(string nom, string id, Fecha fecha, string dir) : nombre(nom), identificacion(id), fecha_ingreso(fecha), direccion(dir) {}

    void agregarHistorial(string registro) {
        historial_clinico.push_back(registro);
    }

    void mostrarHistorial() const {
        cout << "Historial clínico de " << nombre << ":" << endl;
        for (const string& registro : historial_clinico) {
            cout << "- " << registro << endl;
        }
    }

    string toString() const {
        return nombre + ", ID: " + identificacion + ", Fecha de nacimiento: " + fecha_ingreso.toString() + ", Dirección: " + direccion;
    }
};

#endif