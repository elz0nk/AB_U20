#include "CitaMedica.h"
#include <iostream>

string CitaMedica::toString() const {
    return fecha.toString() + " - " + paciente->toString() + " con Dr. " + medico->toString() + ": " + descripcion;
}

bool CitaMedica::operator==(const CitaMedica& otra) const {
    return paciente == otra.paciente
        && medico == otra.medico
        && fecha == otra.fecha
        && descripcion == otra.descripcion
    ;
}