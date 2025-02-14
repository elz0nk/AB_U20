#ifndef GESTIONPACIENTES_H
#define GESTIONPACIENTES_H

#include "GestionPersonas.h"
#include "Paciente.h"

class GestionPacientes : public GestionPersonas {

private:
    vector<Paciente*> pacientes;

public:
    void GestionPersonas::agregarPersona(Persona* p) override {
        pacientes.push_back(dynamic_cast<Paciente*>(p));
    }

    void GestionPersonas::eliminarPersona(const string& id) override {
        pacientes.erase(remove_if(pacientes.begin(), pacientes.end(),
            [&id](Paciente* p) { return p->getIdentificacion() == id; }), pacientes.end());
    }

    void GestionPersonas::modificarPersona(string id, string nuevoNombre, string nuevaDireccion) override {
        for (auto p : pacientes) {
            if (p->getIdentificacion() == id) {
                p->setNombre(nuevoNombre);
                p->setIdentificacion(nuevaDireccion);
                break;
            }
        }
    }

    void GestionPersonas::mostrarPersonas() const override {
        for (auto p : pacientes) {
            cout << p->toString() << endl;
        }
    }

    Persona* GestionPersonas::buscarPersona(string id) const override {
        for (auto p : pacientes) {
            if (p->getIdentificacion() == id) {
                return p;
            }
        }
        return nullptr;
    }

    vector<Persona*> GestionPersonas::getPersonas() override {
        return vector<Persona*>(pacientes.begin(), pacientes.end());
    }
};

#endif