#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class Fecha {
public:
    int dia;
    int mes;
    int anio;

    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

    bool operator<(const Fecha& otra) const {
        if (anio != otra.anio) return anio < otra.anio;
        if (mes != otra.mes) return mes < otra.mes;
        return dia < otra.dia;
    }

    string toString() const {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
    }
};

class Paciente {
public:
    string nombre;
    string identificacion;
    Fecha fecha_ingreso;
    vector<string> historial_clinico;

    Paciente(string nom, string id, Fecha fecha) : nombre(nom), identificacion(id), fecha_ingreso(fecha) {}

    void agregarHistorial(string registro) {
        historial_clinico.push_back(registro);
    }

    void mostrarHistorial() const {
        cout << "Historial clínico de " << nombre << ":" << endl;
        for (const string& registro : historial_clinico) {
            cout << "- " << registro << endl;
        }
    }

    string toString() const {
        return nombre + ", ID: " + identificacion + ", Fecha de ingreso: " + fecha_ingreso.toString();
    }
};

class Medico {
public:
    string nombre;
    string especialidad;

    Medico(string nom, string esp) : nombre(nom), especialidad(esp) {}

    string toString() const {
        return nombre + ", Especialidad: " + especialidad;
    }
};

class CitaMedica {
public:
    Paciente* paciente;
    Medico* medico;
    Fecha fecha;
    string descripcion;

    CitaMedica(Paciente* p, Medico* m, Fecha f, string desc) : paciente(p), medico(m), fecha(f), descripcion(desc) {}

    string toString() const {
        return fecha.toString() + " - " + paciente->nombre + " con Dr. " + medico->nombre + ": " + descripcion;
    }
};

class SistemaHospital {
private:
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<CitaMedica> citas;

public:
    void agregarPaciente(Paciente paciente) {
        pacientes.push_back(paciente);
    }

    void eliminarPaciente(string id) {
        pacientes.erase(remove_if(pacientes.begin(), pacientes.end(),
            [&](const Paciente& p) { return p.identificacion == id; }), pacientes.end());
    }

    void modificarPaciente(string id, string nuevoNombre) {
        for (auto& paciente : pacientes) {
            if (paciente.identificacion == id) {
                paciente.nombre = nuevoNombre;
                break;
            }
        }
    }

    void agregarMedico(Medico medico) {
        medicos.push_back(medico);
    }

    void eliminarMedico(string nombre) {
        medicos.erase(remove_if(medicos.begin(), medicos.end(),
            [&](const Medico& m) { return m.nombre == nombre; }), medicos.end());
    }

    void modificarMedico(string nombre, string nuevaEspecialidad) {
        for (auto& medico : medicos) {
            if (medico.nombre == nombre) {
                medico.especialidad = nuevaEspecialidad;
                break;
            }
        }
    }

    void agregarCita(CitaMedica cita) {
        citas.push_back(cita);
    }

    void eliminarCita(Paciente* paciente, Medico* medico, Fecha fecha) {
        citas.erase(remove_if(citas.begin(), citas.end(),
            [&](const CitaMedica& c) { return c.paciente == paciente && c.medico == medico && c.fecha == fecha; }), citas.end());
    }

    void ordenarCitasPorFecha() {
        sort(citas.begin(), citas.end(), [](const CitaMedica& a, const CitaMedica& b) {
            return a.fecha < b.fecha;
        });
    }

    void mostrarPacientes() const {
        cout << "Lista de pacientes:" << endl;
        for (const Paciente& paciente : pacientes) {
            cout << paciente.toString() << endl;
        }
    }

    void mostrarMedicos() const {
        cout << "Lista de medicos:" << endl;
        for (const Medico& medico : medicos) {
            cout << medico.toString() << endl;
        }
    }

    void mostrarCitas() const {
        cout << "Lista de citas medicas:" << endl;
        for (const CitaMedica& cita : citas) {
            cout << cita.toString() << endl;
        }
    }

    void guardarDatos() const {
        ofstream archivo("datos_hospital.txt");
        archivo << "Pacientes:\n";
        for (const Paciente& paciente : pacientes) {
            archivo << paciente.nombre << "," << paciente.identificacion << "," 
                    << paciente.fecha_ingreso.dia << "/" << paciente.fecha_ingreso.mes << "/" << paciente.fecha_ingreso.anio << "\n";
        }
        archivo << "Medicos:\n";
        for (const Medico& medico : medicos) {
            archivo << medico.nombre << "," << medico.especialidad << "\n";
        }
        archivo << "Citas:\n";
        for (const CitaMedica& cita : citas) {
            archivo << cita.fecha.dia << "/" << cita.fecha.mes << "/" << cita.fecha.anio << "," 
                    << cita.paciente->nombre << "," << cita.medico->nombre << "," << cita.descripcion << "\n";
        }
        archivo.close();
    }

    void cargarDatos() {
        ifstream archivo("datos_hospital.txt");
        string linea;
        while (getline(archivo, linea)) {
            // Parse the line and load data into appropriate structures
        }
        archivo.close();
    }
};

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
