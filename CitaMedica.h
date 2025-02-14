#include <string>
#include "Persona.h"
#include "Fecha.h"

#ifndef CITA_MEDICA_H
#define CITA_MEDICA_H

struct CitaMedica {
public:
    Persona* paciente;
    Persona* medico;
    Fecha fecha;
    string descripcion;

    CitaMedica(Persona* p, Persona* m, Fecha f, string desc) : paciente(p), medico(m), fecha(f), descripcion(desc) {}

    bool operator==(const CitaMedica& otra) const;

    string toString() const;
    
    static CitaMedica CitaMedica::fromString(const string& str);
};

#endif