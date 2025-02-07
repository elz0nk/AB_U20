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
    int opcion;
    while (true)
    {
        cout << "Sistema de gestión hospitalaria" << endl;
        cout << "===============================" << endl;
        cout << endl;
        cout << "Elija qué desea hacer:" << endl;
        cout << "=====================" << endl;
        cout << "1.  Agregar paciente" << endl;
        cout << "2.  Eliminar paciente" << endl;
        cout << "3.  Modificar paciente" << endl;
        cout << "4.  Agregar médico" << endl;
        cout << "5.  Eliminar médico" << endl;
        cout << "6.  Modificar médico" << endl;
        cout << "7.  Agregar cita médica" << endl;
        cout << "8.  Eliminar cita médica" << endl;
        cout << "9.  Mostrar pacientes" << endl;
        cout << "10. Mostrar médicos" << endl;
        cout << "11. Mostrar citas médicas" << endl;
        cout << "12. Guardar datos" << endl;
        cout << "13. Salir" << endl;
        cin >> opcion;

        if (opcion == 13)
        {
            break;
        }

        string nombre, id, dir, esp;
        int dia, mes, anio;

        switch (opcion)
        {
        case 1:{
            cout << "Ingrese el nombre del paciente: ";
            cin >> nombre;

            cout << "Ingrese la identificación del paciente: ";
            cin >> id;

            cout << "Ingrese la fecha de nacimiento del paciente (dd mm aaaa): ";
            cin >> dia >> mes >> anio;

            cout << "Ingrese la dirección del paciente: ";
            cin >> dir;

            hospital.agregarPaciente(Paciente(nombre, id, Fecha(dia, mes, anio), dir));
            break;
        }
        case 2:{
            cout << "Ingrese la identificación del paciente a eliminar: ";
            cin >> id;
            hospital.eliminarPaciente(id);
            break;
        }
        case 3:{
            cout << "Ingrese la identificación del paciente a modificar: ";
            cin >> id;

            cout << "Ingrese el nuevo nombre del paciente: ";
            cin >> nombre;

            cout << "Ingrese la nueva dirección del paciente: ";
            cin >> dir;

            hospital.modificarPaciente(id, nombre, dir);
            break;
        }
        case 4:{
            cout << "Ingrese el nombre del médico: ";
            cin >> nombre;

            cout << "Ingrese la especialidad del médico: ";
            cin >> esp;

            hospital.agregarMedico(Medico(nombre, esp));
            break;
        }
        case 5:{
            cout << "Ingrese el nombre del médico a eliminar: ";
            cin >> nombre;
            hospital.eliminarMedico(nombre);
            break;
        }
        case 6:{
            cout << "Ingrese el nombre del médico a modificar: ";
            cin >> nombre;

            cout << "Ingrese la nueva especialidad del médico: ";
            cin >> esp;

            hospital.modificarMedico(nombre, esp);
            break;
        }
        case 7:{
            cout << "Ingrese la identificación del paciente: ";
            cin >> id;

            cout << "Ingrese el nombre del médico: ";
            cin >> nombre;

            cout << "Ingrese la fecha de la cita (dd mm aaaa): ";
            cin >> dia >> mes >> anio;

            cout << "Ingrese la descripción de la cita: ";
            cin >> dir;

            Paciente* paciente = hospital.buscarPaciente(id);
            Medico* medico = hospital.buscarMedico(nombre);

            if (paciente != nullptr && medico != nullptr)
            {
                hospital.agregarCita(CitaMedica(paciente, medico, Fecha(dia, mes, anio), dir));
            }
            else
            {
                cout << "Paciente o médico no encontrado." << endl;
            }
            break;
        }
        case 8:{
            cout << "Ingrese la identificación del paciente: ";
            cin >> id;

            cout << "Ingrese el nombre del médico: ";
            cin >> nombre;

            cout << "Ingrese la fecha de la cita a eliminar (dd mm aaaa): ";
            cin >> dia >> mes >> anio;

            Paciente* paciente = hospital.buscarPaciente(id);
            Medico* medico = hospital.buscarMedico(nombre);

            if (paciente != nullptr && medico != nullptr)
            {
                hospital.eliminarCita(paciente, medico, Fecha(dia, mes, anio));
            }
            else
            {
                cout << "Paciente o médico no encontrado." << endl;
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
            break;
        };

        // Ejemplo de uso
        Paciente p1("Alice", "001", Fecha(12, 5, 1992), "Calle 123, Ciudad");
        Paciente p2("Bob", "002", Fecha(24, 11, 1985), "Avenida 456, Pueblo");
        Medico m1("Dr. Smith", "Cardiología");
        Medico m2("Dr. Jones", "Neurología");

        hospital.agregarPaciente(p1);
        hospital.agregarPaciente(p2);
        hospital.agregarMedico(m1);
        hospital.agregarMedico(m2);

        CitaMedica c1(&p1, &m1, Fecha(15, 6, 2023), "Chequeo general");
        CitaMedica c2(&p2, &m2, Fecha(20, 6, 2023), "Consulta neurológica");

        hospital.agregarCita(c1);
        hospital.agregarCita(c2);

        hospital.ordenarCitasPorFecha();
        hospital.mostrarPacientes();
        hospital.mostrarMedicos();
        hospital.mostrarCitas();

        hospital.guardarDatos();

        return 0;
    }

    int main();
    {
        SistemaHospital hospital;

        // Ejemplo de uso
        Paciente p1("Alice", "001", Fecha(12, 5, 1992), "Calle 123, Ciudad");
        Paciente p2("Bob", "002", Fecha(24, 11, 1985), "Avenida 456, Pueblo");
        Medico m1("Dr. Smith", "Cardiología");
        Medico m2("Dr. Jones", "Neurología");

        hospital.agregarPaciente(p1);
        hospital.agregarPaciente(p2);
        hospital.agregarMedico(m1);
        hospital.agregarMedico(m2);

        CitaMedica c1(&p1, &m1, Fecha(15, 6, 2023), "Chequeo general");
        CitaMedica c2(&p2, &m2, Fecha(20, 6, 2023), "Consulta neurológica");

        hospital.agregarCita(c1);
        hospital.agregarCita(c2);

        hospital.ordenarCitasPorFecha();
        hospital.mostrarPacientes();
        hospital.mostrarMedicos();
        hospital.mostrarCitas();

        hospital.guardarDatos();

        return 0;
    }
