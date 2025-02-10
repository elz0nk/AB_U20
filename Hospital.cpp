#include <iostream>
#include <vector>
#include <algorithm>
#include "SistemaHospital.h"
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"

using namespace std;

int main()
{
    SistemaHospital hospital;
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

        string nombre, id, dir, esp;
        int dia, mes, anio;

        switch (opcion)
        {
        case 1:{
            cout << "Ingrese el nombre del paciente: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Ingrese la identificacion del paciente: ";
            cin >> id;

            cout << "Ingrese la fecha de nacimiento del paciente (dd mm aaaa): ";
            cin >> dia >> mes >> anio;

            cout << "Ingrese la direccion del paciente: ";
            cin.ignore();
            getline(cin, dir);

            hospital.agregarPaciente(new Paciente(nombre, id, Fecha(dia, mes, anio), dir));
            break;
        }
        case 2:{
            cout << "Ingrese la identificacion del paciente a eliminar: ";
            cin >> id;
            hospital.eliminarPaciente(id);
            break;
        }
        case 3:{
            cout << "Ingrese la identificacion del paciente a modificar: ";
            cin >> id;

            cout << "Ingrese el nuevo nombre del paciente: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Ingrese la nueva direccion del paciente: ";
            cin.ignore();
            getline(cin, dir);

            hospital.modificarPaciente(id, nombre, dir);
            break;
        }
        case 4:{
            cout << "Ingrese el nombre del medico: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Ingrese la especialidad del medico: ";
            getline(cin, esp);

            hospital.agregarMedico(new Medico(nombre, esp));
            break;
        }
        case 5:{
            cout << "Ingrese el nombre del medico a eliminar: ";
            cin >> nombre;
            hospital.eliminarMedico(nombre);
            break;
        }
        case 6:{
            cout << "Ingrese el nombre del medico a modificar: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Ingrese la nueva especialidad del medico: ";
            cin.ignore();
            getline(cin, esp);

            hospital.modificarMedico(nombre, esp);
            break;
        }
        case 7:{
            cout << "Ingrese la identificacion del paciente: ";
            cin >> id;

            cout << "Ingrese el nombre del medico: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Ingrese la fecha de la cita (dd mm aaaa): ";
            cin >> dia >> mes >> anio;

            cout << "Ingrese la descripción de la cita: ";
            cin.ignore();
            getline(cin, dir);

            Paciente* paciente = hospital.buscarPaciente(id);
            Medico* medico = hospital.buscarMedico(nombre);

            if (paciente != nullptr && medico != nullptr)
            {
                hospital.agregarCita(CitaMedica(paciente, medico, Fecha(dia, mes, anio), dir));
            }
            else
            {
                cout << "Paciente o medico no encontrado." << endl;
            }
            break;
        }
        case 8:{
            cout << "Ingrese la identificación del paciente: ";
            cin >> id;

            cout << "Ingrese el nombre del medico: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Ingrese la fecha de la cita a eliminar (dd mm aaaa): ";
            cin >> dia >> mes >> anio;

            Paciente* paciente = hospital.buscarPaciente(id);
            Medico* medico = hospital.buscarMedico(nombre);

            if (paciente != nullptr && medico != nullptr)
            {
                const CitaMedica& citaParaEliminar = CitaMedica(paciente, medico, Fecha(dia, mes, anio), string(""));
                hospital.eliminarCita(citaParaEliminar);
            }
            else
            {
                cout << "Paciente o medico no encontrado." << endl;
            }
            break;
        }
        case 9:{
            hospital.mostrarPacientes();
            break;
        }
        case 10:{
            hospital.mostrarMedicos();
            break;
        }
        case 11:{
            hospital.mostrarCitas();
            break;
        }
        case 12:{
            hospital.guardarDatos();
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

        // Ejemplo de uso
        // Paciente p1("Alice", "001", Fecha(12, 5, 1992), "Calle 123, Ciudad");
        // Paciente p2("Bob", "002", Fecha(24, 11, 1985), "Avenida 456, Pueblo");
        // Medico m1("Dr. Smith", "Cardiología");
        // Medico m2("Dr. Jones", "Neurología");

        // hospital.agregarPaciente(&p1);
        // hospital.agregarPaciente(&p2);
        // hospital.agregarMedico(&m1);
        // hospital.agregarMedico(&m2);
        
        // CitaMedica c1(&p1, &m1, Fecha(15, 6, 2023), "Chequeo general");
        // CitaMedica c2(&p2, &m2, Fecha(20, 6, 2023), "Consulta neurológica");
        
        // hospital.agregarCita(c1);
        // hospital.agregarCita(c2);
        
        // hospital.ordenarCitasPorFecha();
        // hospital.mostrarPacientes();
        // hospital.mostrarMedicos();
        // hospital.mostrarCitas();
        
        // hospital.guardarDatos();
    }
}