#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"

#ifndef SISTEMA_HOSPITAL_H
#define SISTEMA_HOSPITAL_H

using namespace std;

class SistemaHospital {
private:
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<CitaMedica> citas;

public:
    void agregarPaciente(Paciente paciente) {
        pacientes.push_back(paciente);
    }

    void eliminarPaciente(string id) {
        pacientes.erase(remove_if(pacientes.begin(), pacientes.end(),
            [&](const Paciente& p) { return p.identificacion == id; }), pacientes.end());
    }

    void modificarPaciente(string id, string nuevoNombre, string nuevaDireccion) {
        for (auto& paciente : pacientes) {
            if (paciente.identificacion == id) {
                paciente.nombre = nuevoNombre;
                paciente.direccion = nuevaDireccion;
                break;
            }
        }
    }

    void agregarMedico(Medico medico) {
        medicos.push_back(medico);
    }

    void eliminarMedico(string nombre) {
        medicos.erase(remove_if(medicos.begin(), medicos.end(),
            [&](const Medico& m) { return m.nombre == nombre; }), medicos.end());
    }

    void modificarMedico(string nombre, string nuevaEspecialidad) {
        for (auto& medico : medicos) {
            if (medico.nombre == nombre) {
                medico.especialidad = nuevaEspecialidad;
                break;
            }
        }
    }

    void agregarCita(CitaMedica cita) {
        citas.push_back(cita);
    }

    void eliminarCita(Paciente* paciente, Medico* medico, Fecha fecha) {
        citas.erase(remove_if(citas.begin(), citas.end(),
            [&](const CitaMedica& c) { 
                return c.paciente == paciente && c.medico == medico 
                && c.fecha.anio == fecha.anio && c.fecha.mes == fecha.mes && c.fecha.dia == fecha.dia; 
                }),
                 citas.end());
    }

    void ordenarCitasPorFecha() {
        sort(citas.begin(), citas.end(), [](const CitaMedica& a, const CitaMedica& b) {
            return a.fecha < b.fecha;
        });
    }

    void mostrarPacientes() const {
        cout << "Lista de pacientes:" << endl;
        for (const Paciente& paciente : pacientes) {
            cout << paciente.toString() << endl;
        }
    }

    void mostrarMedicos() const {
        cout << "Lista de medicos:" << endl;
        for (const Medico& medico : medicos) {
            cout << medico.toString() << endl;
        }
    }

    void mostrarCitas() const {
        cout << "Lista de citas medicas:" << endl;
        for (const CitaMedica& cita : citas) {
            cout << cita.toString() << endl;
        }
    }

    void guardarDatos() const {
        ofstream archivo("datos_hospital.txt");
        archivo << "Pacientes:\n";
        for (const Paciente& paciente : pacientes) {
            archivo << paciente.nombre << "," << paciente.identificacion << "," << paciente.direccion << ","
                    << paciente.fecha_ingreso.dia << "/" << paciente.fecha_ingreso.mes << "/" << paciente.fecha_ingreso.anio << "\n";
        }
        archivo << "Medicos:\n";
        for (const Medico& medico : medicos) {
            archivo << medico.nombre << "," << medico.especialidad << "\n";
        }
        archivo << "Citas:\n";
        for (const CitaMedica& cita : citas) {
            archivo << cita.fecha.dia << "/" << cita.fecha.mes << "/" << cita.fecha.anio << "," 
                    << cita.paciente->nombre << "," << cita.medico->nombre << "," << cita.descripcion << "\n";
        }
        archivo.close();
    }

    void cargarDatos() {
        ifstream archivo("datos_hospital.txt");
        string linea;
        while (getline(archivo, linea)) {
            // Parse the line and load data into appropriate structures
        }
        archivo.close();
    }
};

#endif