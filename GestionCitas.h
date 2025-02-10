#ifndef GESTIONCITAS_H
#define GESTIONCITAS_H

#include <vector>
#include "CitaMedica.h"

using namespace std;

class GestionCitas {
private:
    vector<CitaMedica> citas;

public:
    void agregarCita(const CitaMedica& cita);
    void eliminarCita(const CitaMedica& cita);
    void modificarCita(Paciente* paciente, Medico* medico, Fecha fecha);
    void ordenarCitasPorFecha();
    void mostrarCitas() const;
    vector<CitaMedica> getCitas() const;
};

#endif