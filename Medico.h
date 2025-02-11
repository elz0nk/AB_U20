#include <string>
#include "Persona.h"

#ifndef MEDICO_H
#define MEDICO_H

using namespace std;

struct Medico : public Persona {
private:
    string especialidad;

public:
    Medico(string nom, string id, string esp) : Persona(nom, id), especialidad(esp) {}
    string getEspecialidadMedico() const;
    bool operator==(const Medico& otro) const;
    string toString() const;
};

#endif