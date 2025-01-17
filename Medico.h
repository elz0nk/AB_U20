#include <string>

#ifndef MEDICO_H
#define MEDICO_H

using namespace std;

struct Medico {
public:
    string nombre;
    string especialidad;

    Medico(string nom, string esp) : nombre(nom), especialidad(esp) {}

    string toString() const {
        return nombre + ", Especialidad: " + especialidad;
    }
};

#endif