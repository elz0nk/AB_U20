#include <algorithm>
#include <iostream>
#include "GestionPacientes.h"

using namespace std;

void GestionPacientes::agregarPaciente(Paciente* paciente) {
    pacientes.push_back(paciente);
}

void GestionPacientes::eliminarPaciente(const string& id) {
    pacientes.erase(remove_if(pacientes.begin(), pacientes.end(),
        [&id](Paciente* paciente) { 
            return paciente->getIdentificacionPaciente() == id; }),
             pacientes.end());
}

void GestionPacientes::modificarPaciente(string id, string nuevoNombre, string nuevaDireccion) {
    for (Paciente* paciente : pacientes) {
        if (paciente->getIdentificacionPaciente() == id) {
            paciente->setNombrePaciente(nuevoNombre);
            paciente->setDireccionPaciente(nuevaDireccion);
            break;
        }
    }
}

void GestionPacientes::mostrarPacientes() const {
    cout << "Lista de pacientes:" << endl;
    for (const Paciente* paciente : pacientes) {
        cout << paciente->toString() << endl;
    }
}

Paciente* GestionPacientes::buscarPaciente(string id) {
    for (Paciente* paciente : pacientes) {
        if (paciente->getIdentificacionPaciente() == id) {
            return paciente;
        }
    }
    cout << "Paciente no encontrado";
    return nullptr;
}
    
vector<Paciente*> GestionPacientes::getPacientes() const {
    return pacientes;
}