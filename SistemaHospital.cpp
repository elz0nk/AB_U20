#include "SistemaHospital.h"
#include "GestionPacientes.h"
#include "GestionMedicos.h"
#include "GestionCitas.h"
#include "GestionDatos.h"

GestionPacientes gestionPacientes;
GestionMedicos gestionMedicos;
GestionCitas gestionCitas;
GestionDatos gestionDatos;

//Logica pacientes
void SistemaHospital::agregarPaciente(Paciente* p) {
    gestionPacientes.agregarPaciente(p);
}

void SistemaHospital::eliminarPaciente(const string& id) {
    gestionPacientes.eliminarPaciente(id);
}

void SistemaHospital::modificarPaciente(string id, string nuevoNombre, string nuevaDireccion) {
    gestionPacientes.modificarPaciente(id, nuevoNombre, nuevaDireccion);
}

void SistemaHospital::mostrarPacientes() const {
    gestionPacientes.mostrarPacientes();
}

Paciente* SistemaHospital::buscarPaciente(string id) const {
    return gestionPacientes.buscarPaciente(id);
}

vector<Paciente*> SistemaHospital::getPacientes() {
    return gestionPacientes.getPacientes();
}

//Logica medicos
void SistemaHospital::agregarMedico(Medico* medico) {
    gestionMedicos.agregarMedico(medico);
}

void SistemaHospital::eliminarMedico(const string& nombre) {
    gestionMedicos.eliminarMedico(nombre);
}

void SistemaHospital::modificarMedico(string nombre, string nuevaEspecialidad) {
    gestionMedicos.modificarMedico(nombre, nuevaEspecialidad);
}

void SistemaHospital::mostrarMedicos() const {
    gestionMedicos.mostrarMedicos();
}

Medico* SistemaHospital::buscarMedico(string nombre) const {
    return gestionMedicos.buscarMedico(nombre);
}

vector<Medico*> SistemaHospital::getMedicos() {
    return gestionMedicos.getMedicos();
}

//Logica citas
void SistemaHospital::agregarCita(const CitaMedica& cita) {
    gestionCitas.agregarCita(cita);
}


void SistemaHospital::eliminarCita(const CitaMedica& cita) {
    gestionCitas.eliminarCita(cita);
}

void SistemaHospital::ordenarCitasPorFecha() {
    gestionCitas.ordenarCitasPorFecha();
}

void SistemaHospital::mostrarCitas() const {
    gestionCitas.mostrarCitas();
}

vector <CitaMedica> SistemaHospital::getCitas() {
    return gestionCitas.getCitas();
}

//Logica datos
void SistemaHospital::guardarDatos() const {
    gestionDatos.guardarDatos();
}

void SistemaHospital::cargarDatos() {
    gestionDatos.cargarDatos();
}