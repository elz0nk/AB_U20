#include <string>

#ifndef FECHA_H
#define FECHA_H

using namespace std;

struct Fecha {
public:
    int dia;
    int mes;
    int anio;

    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

    bool operator<(const Fecha& otra) const;

    bool operator==(const Fecha& otra) const;

    string toString() const;
};

#endif