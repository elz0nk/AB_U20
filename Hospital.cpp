#include <iostream>
#include <vector>
#include <algorithm>
#include "SistemaHospital.h"
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"

using namespace std;

int main() {
    SistemaHospital hospital;

    // Ejemplo de uso
    Paciente p1("Alice", "001", Fecha(12, 5, 1992));
    Paciente p2("Bob", "002", Fecha(24, 11, 1985));
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
