#include "Medico.h"

string Medico::getEspecialidadMedico() const {
    return this->especialidad;
}

bool Medico::operator==(const Medico& otro) const {
    return this->getNombre() == otro.getNombre();
}

string Medico::toString() const {
    return this->getNombre() + ", Especialidad: " + this->getEspecialidadMedico();
}
