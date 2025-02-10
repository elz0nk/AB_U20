#include "Fecha.h"

string Fecha::toString() const {
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}

bool Fecha::operator<(const Fecha& otra) const {
    if (anio != otra.anio) return anio < otra.anio;
    if (mes != otra.mes) return mes < otra.mes;
    return dia < otra.dia;
}

bool Fecha::operator==(const Fecha& otra) const {
    return anio == otra.anio
        && mes == otra.mes 
        && dia == otra.dia;
}
