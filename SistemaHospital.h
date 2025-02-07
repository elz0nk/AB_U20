// SistemaHospital.h
#ifndef SISTEMAHOSPITAL_H
#define SISTEMAHOSPITAL_H

#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"

class SistemaHospital {
private:
    std::vector<Medico> medicos;
    std::vector<CitaMedica> citas;

public:
    void agregarPaciente(const Paciente& p);
    void eliminarPaciente(const std::string& id);
    void mostrarPacientes() const;

    void agregarMedico(const Medico& m);
    void eliminarMedico(const std::string& nombre);
    void mostrarMedicos() const;

    void agregarCita(const CitaMedica& c);
    void mostrarCitas() const;
    void ordenarCitasPorFecha();
};

#endif