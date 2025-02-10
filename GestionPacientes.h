#ifndef GESTIONPACIENTES_H
#define GESTIONPACIENTES_H

#include <vector>
#include "Paciente.h"

using namespace std;

class GestionPacientes {
private:
    vector<Paciente*> pacientes;

public:
    void agregarPaciente(Paciente* paciente);
    void eliminarPaciente(const string& id);
    void modificarPaciente(string id, string nuevoNombre, string nuevaDireccion);
    void mostrarPacientes() const;
    Paciente* buscarPaciente(string id);
    vector<Paciente*> getPacientes() const;
};

#endif