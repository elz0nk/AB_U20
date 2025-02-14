#ifndef GESTIONPERSONAS_H
#define GESTIONPERSONAS_H

#include <vector>
#include <string>
#include <iostream>
#include "Persona.h"

class GestionPersonas {
public:
    virtual void agregarPersona(Persona* p) = 0;
    virtual void eliminarPersona(const string& id) = 0;
    virtual void modificarPersona(string id, string nuevoNombre, string nuevaDireccion) = 0;
    virtual void mostrarPersonas() const = 0;
    virtual Persona* buscarPersona(string id) const = 0;
    virtual vector<Persona*> getPersonas() = 0;

    virtual ~GestionPersonas() = default;
};

#endif
