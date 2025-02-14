#ifndef GESTIONMEDICOS_H
#define GESTIONMEDICOS_H

#include "GestionPersonas.h"
#include "Medico.h"

class GestionMedicos : public GestionPersonas {

private:
    vector<Medico*> medicos;

public:
    void GestionPersonas::agregarPersona(Persona* medico) override {
        medicos.push_back(dynamic_cast<Medico*>(medico));
    }

    void GestionPersonas::eliminarPersona(const string& nombre) override {
        medicos.erase(remove_if(medicos.begin(), medicos.end(),
            [&](Medico* medico) { return medico->getNombre() == nombre; }), medicos.end());
    }

    void GestionPersonas::modificarPersona(string id, string nombre, string nuevaEspecialidad) override {
        for (auto medico : medicos) {
            if (medico->getNombre() == nombre) {
                medico->getEspecialidadMedico() = nuevaEspecialidad;
                break;
            }
        }
    }

    void GestionPersonas::mostrarPersonas() const override {
        for (auto m : medicos) {
            cout << m->toString() << endl;
        }
    }

    Persona* GestionPersonas::buscarPersona(string nombre) const override {
        for (auto medico : medicos) {
            if (medico->getNombre() == nombre) {
                return medico;
            }
        }
        return nullptr;
    }

    vector<Persona*> GestionPersonas::getPersonas() override {
        return vector<Persona*>(medicos.begin(), medicos.end());
    }
};

#endif