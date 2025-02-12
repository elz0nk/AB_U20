#include <iostream>
#include <sstream>
#include "Paciente.h"


string Paciente::toString() const
{
    return this->getNombre() + ", ID: " + this->getIdentificacion() + ", Fecha de nacimiento: " + this->fecha_nacimiento.toString() + ", Direccion: " + this->direccion;
}

bool Paciente::operator==(const Paciente &otro) const
{
    return this->identificacion == otro.identificacion;
}

void Paciente::agregarHistorial(string registro)
{
    Paciente::historial_clinico.push_back(registro);
}

void Paciente::mostrarHistorial() const
{
    cout << "Historial clínico de " << this->nombre << ":" << endl;
    for (const string &registro : historial_clinico)
    {
        cout << "- " << registro << endl;
    }
}

void Paciente::setDireccionPaciente(const string dir)
{
    this->direccion = dir;
}

Paciente *Paciente::fromString(const string &str)
{
    string nombre, id, direccion;

    size_t pos1 = str.find(", ID: ");
    size_t pos2 = str.find(", Fecha de nacimiento: ");
    size_t pos3 = str.find(", Direccion: ");

    if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos)
        return nullptr;

    nombre = str.substr(0, pos1);
    id = str.substr(pos1 + 6, pos2 - (pos1 + 6));
    string fechaStr = str.substr(pos2 + 23, pos3 - (pos2 + 23));
    int dia, mes, anio;
    char separador;
    stringstream ss(fechaStr);
    ss >> dia >> separador >> mes >> separador >> anio;
    Fecha fecha(dia, mes, anio);
    direccion = str.substr(pos3 + 12);
    return new Paciente(nombre, id, fecha, direccion);
}