#include <algorithm>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "GestionDatos.h"
#include "SistemaHospital.h"
#include "Medico.h"

SistemaHospital sistemaHospital;

void GestionDatos::guardarDatos() const {
    ofstream archivo("datos_hospital.txt");

    archivo << "Pacientes:\n";
    for (Paciente* paciente : sistemaHospital.getPacientes()) {
        archivo << paciente->toString() << "\n";
    }

    archivo << "Medicos:\n";
    for (Medico* medico : sistemaHospital.getMedicos()) {
        archivo << medico->toString() << "\n";
    }

    archivo << "Citas:\n";
    for (const CitaMedica& cita : sistemaHospital.getCitas()) {
        archivo << cita.toString() << "\n";
    }

    archivo.close();
}

void GestionDatos::cargarDatos() {
    ifstream archivo("datos_hospital.txt");
    string linea;
    while (getline(archivo, linea)) {
    }
    archivo.close();
}