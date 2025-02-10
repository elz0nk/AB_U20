#ifndef GESTIONMEDICOS_H
#define GESTIONMEDICOS_H

#include <vector>
#include "Medico.h"

using namespace std;

class GestionMedicos {
private:
    vector<Medico*> medicos;

public:
    void agregarMedico( Medico* medico);
    void eliminarMedico(const string& nombre);
    void modificarMedico(string nombre, string nuevaEspecialidad);
    void mostrarMedicos() const;
    Medico* buscarMedico(string nombre);
    vector<Medico*> getMedicos() const;
};

#endif