#include <string>
#include "Paciente.h"
#include "Medico.h"
#include "Fecha.h"

#ifndef CITA_MEDICA_H
#define CITA_MEDICA_H

class CitaMedica {
public:
    Paciente* paciente;
    Medico* medico;
    Fecha fecha;
    string descripcion;

    CitaMedica(Paciente* p, Medico* m, Fecha f, string desc) : paciente(p), medico(m), fecha(f), descripcion(desc) {}

    string toString() const {
        return fecha.toString() + " - " + paciente->nombre + " con Dr. " + medico->nombre + ": " + descripcion;
    }
};

#endif