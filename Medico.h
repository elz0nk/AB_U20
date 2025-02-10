#include <string>

#ifndef MEDICO_H
#define MEDICO_H

using namespace std;

struct Medico {
private:
    string nombre;
    string especialidad;

public:
    Medico(string nom, string esp) : nombre(nom), especialidad(esp) {}
    string getNombreMedico() const;
    string getEspecialidadMedico() const;
    bool operator==(const Medico& otro) const;
    string toString() const;
};

#endif