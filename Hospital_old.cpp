#include <iostream>
#include <vector>
#include "Medico.cpp"
#include "Paciente.cpp"
#include "CitaMedica.cpp"

using namespace std;

class Hospital {
private:
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<CitaMedica> citas;

public:
    void agregarPaciente(Paciente paciente) { pacientes.push_back(paciente); }
    void agregarMedico(Medico medico) { medicos.push_back(medico); }
    void agregarCita(CitaMedica cita) { citas.push_back(cita); }

    Paciente* buscarPaciente(int id) {
        for (auto& paciente : pacientes) {
            if (paciente.getId() == id) return &paciente;
        }
        return nullptr;
    }

    Medico* buscarMedico(int id) {
        for (auto& medico : medicos) {
            if (medico.getId() == id) return &medico;
        }
        return nullptr;
    }

    void listarPacientes() const {
        for (const auto& paciente : pacientes) {
            paciente.mostrarInformacion();
        }
    }

    void listarMedicos() const {
        for (const auto& medico : medicos) {
            medico.mostrarInformacion();
        }
    }

    void listarCitas() const {
        for (const auto& cita : citas) {
            cita.mostrarInformacion();
        }
    }
};
