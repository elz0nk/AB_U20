#include <iostream>
#include <vector>
#include <algorithm>
#include "GestionCitas.h"
#include "GestionDatos.h"
#include "GestionPersonas.h"
#include "GestionPacientes.h"
#include "GestionMedicos.h"
#include "CitaMedica.h"
#include "Medico.h"
#include "Paciente.h"

using namespace std;

int main()
{
    GestionPersonas* gestionPacientes = new GestionPacientes();
    GestionPersonas* gestionMedicos = new GestionMedicos();
    GestionCitas gestionCitas;
    GestionDatos gestionDatos(gestionPacientes, gestionMedicos, &gestionCitas);

    gestionDatos.cargarDatos();
    int opcion=0;
    while (opcion<13)
    {
        cout << "Sistema de gestion hospitalaria" << endl;
        cout << "===============================" << endl;
        cout << endl;
        cout << "Elija que desea hacer:" << endl;
        cout << "=====================" << endl;
        cout << "1.  Agregar paciente" << endl;
        cout << "2.  Eliminar paciente" << endl;
        cout << "3.  Modificar paciente" << endl;
        cout << "4.  Agregar medico" << endl;
        cout << "5.  Eliminar medico" << endl;
        cout << "6.  Modificar medico" << endl;
        cout << "7.  Agregar cita medica" << endl;
        cout << "8.  Eliminar cita medica" << endl;
        cout << "9.  Mostrar pacientes" << endl;
        cout << "10. Mostrar medicos" << endl;
        cout << "11. Mostrar citas medicas" << endl;
        cout << "12. Guardar datos" << endl;
        cout << "13. Salir" << endl;
        cin >> opcion;
        if (!cin.good()) 
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida, introduzca un valor valido" << endl;
            continue;
        }

        string nombreMedico, nombrePaciente, idMedico, idPaciente, direccionPaciente, especialidadMedico, descripcionCita;
        int diaNacimientoPaciente, mesNacimientoPaciente, anioNacimientoPaciente, diaCita, mesCita, anioCita;

        switch (opcion)
        {
        case 1:{
            cout << "Ingrese el nombre del paciente: ";
            cin.ignore();
            getline(cin, nombrePaciente);

            cout << "Ingrese la identificacion del paciente: ";
            cin >> idPaciente;

            cout << "Ingrese la fecha de nacimiento del paciente (dd mm aaaa): ";
            cin >> diaNacimientoPaciente >> mesNacimientoPaciente >> anioNacimientoPaciente;

            cout << "Ingrese la direccion del paciente: ";
            cin.ignore();
            getline(cin, direccionPaciente);

            gestionPacientes->agregarPersona(
                new Paciente(nombrePaciente, idPaciente,
                                     Fecha(diaNacimientoPaciente, mesNacimientoPaciente, anioNacimientoPaciente),
                                                       direccionPaciente));
            break;
        }
        case 2:{
            cout << "Ingrese la identificacion del paciente a eliminar: ";
            cin >> idPaciente;
            gestionPacientes->eliminarPersona(idPaciente);
            break;
        }
        case 3:{
            cout << "Ingrese la identificacion del paciente a modificar: ";
            cin >> idPaciente;

            cout << "Ingrese el nuevo nombre del paciente: ";
            cin.ignore();
            getline(cin, nombrePaciente);

            cout << "Ingrese la nueva direccion del paciente: ";
            cin.ignore();
            getline(cin, direccionPaciente);

            gestionPacientes->modificarPersona(idPaciente, nombrePaciente, direccionPaciente);
            break;
        }
        case 4:{
            cout << "Ingrese el nombre del medico: ";
            cin.ignore();
            getline(cin, nombreMedico);

            cout << "Ingrese la identificacion del medico: ";
            cin >> idMedico;

            cout << "Ingrese la especialidad del medico: ";
            cin.ignore();
            getline(cin, especialidadMedico);

            gestionMedicos->agregarPersona(new Medico(nombreMedico, idMedico, especialidadMedico));
            break;
        }
        case 5:{
            cout << "Ingrese el nombre del medico a eliminar: ";
            cin >> nombreMedico;
            gestionMedicos->eliminarPersona(nombreMedico);
            break;
        }
        case 6:{
            cout << "Ingrese el nombre del medico a modificar: ";
            cin.ignore();
            getline(cin, nombreMedico);

            cout << "Ingrese la nueva especialidad del medico: ";
            cin.ignore();
            getline(cin, especialidadMedico);

            gestionMedicos->modificarPersona("", nombreMedico, especialidadMedico);
            break;
        }
        case 7:{
            cout << "Ingrese la identificacion del paciente: ";
            cin >> idPaciente;

            cout << "Ingrese el nombre del medico: ";
            cin.ignore();
            getline(cin, nombreMedico);

            cout << "Ingrese la fecha de la cita (dd mm aaaa): ";
            cin >> diaCita >> mesCita >> anioCita;

            cout << "Ingrese la descripción de la cita: ";
            cin.ignore();
            getline(cin, descripcionCita);

            Persona* paciente = gestionPacientes->buscarPersona(idPaciente);
            Persona* medico = gestionMedicos->buscarPersona(nombreMedico);

            if (paciente != nullptr && medico != nullptr)
            {
                gestionCitas.agregarCita(CitaMedica(paciente, medico, Fecha(diaCita, mesCita, anioCita), descripcionCita));
            }
            else
            {
                cout << "Paciente o medico no encontrado." << endl;
            }
            break;
        }
        case 8:{
            cout << "Ingrese la identificación del paciente: ";
            cin >> idPaciente;

            cout << "Ingrese el nombre del medico: ";
            cin.ignore();
            getline(cin, nombreMedico);

            cout << "Ingrese la fecha de la cita a eliminar (dd mm aaaa): ";
            cin >> diaCita >> mesCita >> anioCita;

            Persona* paciente = gestionPacientes->buscarPersona(idPaciente);
            Persona* medico = gestionMedicos->buscarPersona(nombreMedico);

            if (paciente != nullptr && medico != nullptr)
            {
                const CitaMedica& citaParaEliminar = CitaMedica(paciente, medico, Fecha(diaCita, mesCita, anioCita), string(""));
                gestionCitas.eliminarCita(citaParaEliminar);
            }
            else
            {
                cout << "Paciente o medico no encontrado." << endl;
            }
            break;
        }
        case 9:{
            gestionPacientes->mostrarPersonas();
            break;
        }
        case 10:{
            gestionMedicos->mostrarPersonas();
            break;
        }
        case 11:{
            gestionCitas.mostrarCitas();
            break;
        }
        case 12:{
            gestionDatos.guardarDatos();
            break;
        }
        case 13:{
            break;
        }
        default:
            opcion = 0;
            cout << "Opcion invalida, introduzca un valor valido" << endl;
            break;
        };
    }
}