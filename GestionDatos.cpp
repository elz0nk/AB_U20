#include <algorithm>
#include <iostream>
#include <fstream>
#include "GestionDatos.h"
#include "Medico.h"
#include "Paciente.h"

void GestionDatos::guardarDatos() const
{
    ofstream archivo("datos_hospital.txt");

    archivo << "Pacientes:\n";
    for (Persona *paciente : gestionPacientes->getPersonas())
    {
        archivo << ((Paciente*) paciente)->toString() << "\n";
    }

    archivo << "Medicos:\n";
    for (Persona *medico : gestionMedicos->getPersonas())
    {
        archivo << ((Medico*) medico)->toString() << "\n";
    }

    archivo << "Citas:\n";
    for (const CitaMedica &cita : gestionCitas->getCitas())
    {
        archivo << cita.toString() << "\n";
    }

    archivo.close();
}

void GestionDatos::cargarDatos()
{
    ifstream archivo("datos_hospital.txt");
    if (!archivo)
    {
        cerr << "Error: No se pudo abrir el archivo de datos." << endl;
        return;
    }

    string linea;
    string seccion = "";

    while (getline(archivo, linea))
    {
        if (linea == "Pacientes:")
        {
            seccion = "Pacientes";
        }
        else if (linea == "Medicos:")
        {
            seccion = "Medicos";
        }
        else if (linea == "Citas:")
        {
            seccion = "Citas";
        }
        else if (!linea.empty())
        { 
            if (seccion == "Pacientes")
            {
                Paciente *paciente = Paciente::fromString(linea);
                gestionPacientes->agregarPersona(paciente);
            }
            else if (seccion == "Medicos")
            {
                Medico *medico = Medico::fromString(linea);
                gestionMedicos->agregarPersona(medico);
            }
            else if (seccion == "Citas")
            {
                CitaMedica cita = CitaMedica::fromString(linea);
                gestionCitas->agregarCita(cita);
            }
        }
    }

    archivo.close();
}
