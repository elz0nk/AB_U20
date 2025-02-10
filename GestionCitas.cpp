#include <algorithm>
#include <iostream>
#include "GestionCitas.h"

using namespace std;

void GestionCitas::agregarCita(const CitaMedica& cita) {
    citas.push_back(cita);
}

void GestionCitas::eliminarCita(const CitaMedica& cita) {
    citas.erase(remove_if(citas.begin(), citas.end(),
        [&](const CitaMedica& citaMedica) { 
            return cita == citaMedica; }),
             citas.end());
}

void GestionCitas::modificarCita(Paciente* paciente, Medico* medico, Fecha fecha) {
    for (auto& cita : citas) {
        if (cita.paciente == paciente) {
            cita.medico = medico;
            cita.fecha = fecha;
            break;
        }
    }
}

void GestionCitas::ordenarCitasPorFecha() {
    std::sort(citas.begin(), citas.end(), [](const CitaMedica& a, const CitaMedica& b) {
        return a.fecha < b.fecha;
    });
}

void GestionCitas::mostrarCitas()  const {
    cout << "Lista de citas medicas:" << endl;
    for (const CitaMedica& cita : citas) {
        cout << cita.toString() << endl;
    }
}

vector<CitaMedica> GestionCitas::getCitas() const {
    return citas;
}