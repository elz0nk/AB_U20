#include <string>
#include "Paciente.h"
#include "Medico.h"
#include "Fecha.h"

#ifndef CITA_MEDICA_H
#define CITA_MEDICA_H

struct CitaMedica {
public:
    Paciente* paciente;
    Medico* medico;
    Fecha fecha;
    string descripcion;

    CitaMedica(Paciente* p, Medico* m, Fecha f, string desc) : paciente(p), medico(m), fecha(f), descripcion(desc) {}

    bool operator==(const CitaMedica& otra) const;

    string toString() const;
};

#endif