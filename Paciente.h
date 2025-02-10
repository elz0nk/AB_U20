#include <vector>
#include <string>
#include "Fecha.h"

#ifndef PACIENTE_H
#define PACIENTE_H

struct Paciente {
private:
    string nombre;
    string identificacion;
    Fecha fecha_nacimiento;
    string direccion;
    vector<string> historial_clinico;

public:
    Paciente(string nom, string id, Fecha fecha_nac, string dir) : nombre(nom), identificacion(id), fecha_nacimiento(fecha_nac), direccion(dir) {}
    
    void agregarHistorial(string registro);
    void mostrarHistorial() const;

    string getIdentificacionPaciente() const;
    void setNombrePaciente(string nom);
    void setDireccionPaciente(string dir);

    bool operator==(const Paciente& otro) const;
    string toString() const;
};

#endif