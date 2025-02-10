#include <iostream>
#include "Paciente.h"

string Paciente::toString() const {
    return this->nombre + ", ID: " + this->getIdentificacionPaciente() + ", Fecha de nacimiento: " + this->fecha_nacimiento.toString() + ", Dirección: " + this->direccion;    
}

bool Paciente::operator==(const Paciente& otro) const {
    return this->identificacion == otro.identificacion;
}

void Paciente::agregarHistorial(string registro) {
    Paciente::historial_clinico.push_back(registro);
}

void Paciente::mostrarHistorial() const {
    cout << "Historial clínico de " << this->nombre << ":" << endl;
    for (const string& registro : historial_clinico) {
        cout << "- " << registro << endl;
    }
}

string Paciente::getIdentificacionPaciente() const {
    return this->identificacion;
}

void Paciente::setNombrePaciente(const string nom) {
    this->nombre = nom;
}

void Paciente::setDireccionPaciente(const string dir) {
    this->direccion = dir;
}


