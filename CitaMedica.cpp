 #include <iostream>
#include <string>
using namespace std;

class CitaMedica {
private:
    int id_paciente;
    int id_medico;
    string fecha;
    string motivo;

public:
    CitaMedica(int id_paciente, int id_medico, string fecha, string motivo)
        : id_paciente(id_paciente), id_medico(id_medico), fecha(fecha), motivo(motivo) {}

    int getIdPaciente() const { return id_paciente; }
    int getIdMedico() const { return id_medico; }
    string getFecha() const { return fecha; }
    string getMotivo() const { return motivo; }


    void mostrarInformacion() const {
        cout << "Cita Medica - Paciente ID: " << id_paciente << ", Medico ID: " << id_medico << ", Fecha: " << fecha << ", Motivo: " << motivo << endl;
    }
};
