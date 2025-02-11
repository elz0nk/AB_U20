#include <iostream>
#include "Paciente.h"

string Paciente::toString() const {
    return this->getNombre() + ", ID: " + this->getIdentificacion() + ", Fecha de nacimiento: " + this->fecha_nacimiento.toString() + ", Direccion: " + this->direccion;    
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

void Paciente::setDireccionPaciente(const string dir) {
    this->direccion = dir;
}


