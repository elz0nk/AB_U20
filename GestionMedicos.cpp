#include <algorithm>
#include <iostream>
#include "GestionMedicos.h"

using namespace std;

void GestionMedicos::agregarMedico(Medico* medico) {
    medicos.push_back(medico);
}

void GestionMedicos::eliminarMedico(const string& nombre) {
    medicos.erase(remove_if(medicos.begin(), medicos.end(),
        [&](Medico* medico) { return medico->getNombreMedico() == nombre; }), medicos.end());
}

void GestionMedicos::modificarMedico(string nombre, string nuevaEspecialidad) {
    for (auto& medico : medicos) {
        if (medico->getNombreMedico() == nombre) {
            medico->getEspecialidadMedico() = nuevaEspecialidad;
            break;
        }
    }
}

void GestionMedicos::mostrarMedicos() const {    
    cout << "Lista de medicos:" << endl;
    for (const Medico* medico : medicos) {
        cout << medico->toString() << endl;
    }
}

Medico* GestionMedicos::buscarMedico(string nombre) {
    for (Medico* medico : medicos) {
        if (medico->getNombreMedico() == nombre) {
            return medico;
        }
    }
    cout << "Medico no encontrado";
    return nullptr;
}

vector<Medico*> GestionMedicos::getMedicos() const {
    return medicos;
}