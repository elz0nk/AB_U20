#include <string>

#ifndef FECHA_H
#define FECHA_H

using namespace std;

class Fecha {
public:
    int dia;
    int mes;
    int anio;

    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

    bool operator<(const Fecha& otra) const {
        if (anio != otra.anio) return anio < otra.anio;
        if (mes != otra.mes) return mes < otra.mes;
        return dia < otra.dia;
    }

    string toString() const {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
    }
};

#endif