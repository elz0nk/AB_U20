#include <algorithm>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "GestionDatos.h"
#include "SistemaHospital.h"
#include "Medico.h"

SistemaHospital sistemaHospital;

void GestionDatos::guardarDatos() const
{
    ofstream archivo("datos_hospital.txt");

    archivo << "Pacientes:\n";
    for (Paciente *paciente : sistemaHospital.getPacientes())
    {
        archivo << paciente->toString() << "\n";
    }

    archivo << "Medicos:\n";
    for (Medico *medico : sistemaHospital.getMedicos())
    {
        archivo << medico->toString() << "\n";
    }

    archivo << "Citas:\n";
    for (const CitaMedica &cita : sistemaHospital.getCitas())
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
                sistemaHospital.agregarPaciente(paciente);
            }
            else if (seccion == "Medicos")
            {
                Medico *medico = Medico::fromString(linea);
                sistemaHospital.agregarMedico(medico);
            }
            else if (seccion == "Citas")
            {
                CitaMedica cita = CitaMedica::fromString(linea);
                sistemaHospital.agregarCita(cita);
            }
        }
    }

    archivo.close();
}
