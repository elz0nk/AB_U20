#include <vector>
#include <string>
#include "Fecha.h"
#include "Persona.h"

#ifndef PACIENTE_H
#define PACIENTE_H

struct Paciente : public Persona {
private:
    Fecha fecha_nacimiento;
    string direccion;
    vector<string> historial_clinico;

public:
    Paciente(string nom, string id, Fecha fecha_nac, string dir) : Persona(nom, id), fecha_nacimiento(fecha_nac), direccion(dir) {}
    
    void agregarHistorial(string registro);
    void mostrarHistorial() const;

    //string getIdentificacionPaciente() const;
    //void setNombrePaciente(string nom);
    void setDireccionPaciente(string dir);

    bool operator==(const Paciente& otro) const;
    string toString() const;

    static Paciente* Paciente::fromString(const string& str);
};

#endif