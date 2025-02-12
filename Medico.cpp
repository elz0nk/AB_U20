#include "Medico.h"

string Medico::getEspecialidadMedico() const {
    return this->especialidad;
}

bool Medico::operator==(const Medico& otro) const {
    return this->getNombre() == otro.getNombre();
}

string Medico::toString() const {
    return this->getNombre() + ", ID: " + this->getIdentificacion() + ", Especialidad: " + this->getEspecialidadMedico();
}

Medico* Medico::fromString(const string& str) {
    size_t pos1 = str.find(", ID: ");
    if (pos1 == string::npos) return nullptr;
    size_t pos2 = str.find(", Especialidad: ");
    if (pos2 == string::npos) return nullptr;

    string nombre = str.substr(0, pos1);
    string id = str.substr(pos1 + 6, pos2 - (pos1 + 6));
    string especialidad = str.substr(pos2 + 16);

    return new Medico(nombre, id, especialidad);
}
