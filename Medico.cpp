#include "Medico.h"

string Medico::getNombreMedico() const {
    return this->nombre;
}

string Medico::getEspecialidadMedico() const {
    return this->especialidad;
}

bool Medico::operator==(const Medico& otro) const {
    return this->nombre == otro.nombre;
}

string Medico::toString() const {
    return this->getNombreMedico() + ", Especialidad: " + this->getEspecialidadMedico();
}
