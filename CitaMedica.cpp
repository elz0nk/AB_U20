#include <iostream>
#include <sstream>
#include "CitaMedica.h"
#include "Paciente.h"
#include "Medico.h"

CitaMedica CitaMedica::fromString(const string& str) {
    size_t pos1 = str.find(" - ");
    size_t pos2 = str.find(" con Dr. ");
    size_t pos3 = str.find(", descripcion: ");

    string fechaStr = str.substr(0, pos1);
    int dia, mes, anio;
    char separador;
    stringstream ss(fechaStr);    
    ss >> dia >> separador >> mes >> separador >> anio;
    Fecha fecha(dia, mes, anio);
    string pacienteStr = str.substr(pos1 + 3, pos2 - (pos1 + 3));
    string medicoStr = str.substr(pos2 + 9, pos3 - (pos2 + 9));
    string descripcion = str.substr(pos3 + 15);

    Paciente* paciente = Paciente::fromString(pacienteStr);
    Medico* medico = Medico::fromString(medicoStr);

    return CitaMedica(paciente, medico, fecha, descripcion);
}


string CitaMedica::toString() const {
    return fecha.toString() + " - " + paciente->toString() + " con Dr. " + medico->toString() + ", descripcion: " + descripcion;
}

bool CitaMedica::operator==(const CitaMedica& otra) const {
    return paciente == otra.paciente
        && medico == otra.medico
        && fecha == otra.fecha
    ;
}