#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"

#ifndef SISTEMA_HOSPITAL_H
#define SISTEMA_HOSPITAL_H

class SistemaHospital {
public:
    void agregarPaciente(Paciente* p);
    void eliminarPaciente(const string& id);
    void modificarPaciente(string id, string nuevoNombre, string nuevaDireccion);
    void mostrarPacientes() const;
    Paciente* buscarPaciente(string id) const;
    vector<Paciente*> getPacientes();

    void agregarMedico(Medico* medico);
    void eliminarMedico(const string& nombre);
    void modificarMedico(string nombre, string nuevaEspecialidad);
    void mostrarMedicos() const;
    Medico* buscarMedico(string nombre) const;
    vector<Medico*> getMedicos();

    void agregarCita(const CitaMedica& cita);
    void eliminarCita(const CitaMedica& cita);
    void ordenarCitasPorFecha();
    void mostrarCitas() const;
    vector<CitaMedica> getCitas();

    void guardarDatos() const;
    void cargarDatos();
};

#endif