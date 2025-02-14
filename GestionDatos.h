#ifndef GESTIONDATOS_H
#define GESTIONDATOS_H

#include "GestionCitas.h"
#include "GestionPersonas.h"

class GestionDatos {
    private:
        GestionPersonas* gestionPacientes;
        GestionPersonas* gestionMedicos;
        GestionCitas* gestionCitas;

    public:
        GestionDatos(GestionPersonas* pacientes, GestionPersonas* medicos, GestionCitas* citas)
                : gestionPacientes(pacientes), gestionMedicos(medicos), gestionCitas(citas) {}
                
        void guardarDatos() const;
        void cargarDatos();
};

#endif