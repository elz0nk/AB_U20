#include <string>

#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

class Persona {
    string nombre;
    string identificacion;

public:
    Persona(const string& nom, const string& id) : nombre(nom), identificacion(id) {}

    virtual ~Persona() = default;

    string getNombre() const { return nombre; }
    void setNombre(const string& nom) { nombre = nom; }

    string getIdentificacion() const { return identificacion; }
    void setIdentificacion(const string& id) { identificacion = id; }

    virtual string toString() const = 0;
};

#endif
