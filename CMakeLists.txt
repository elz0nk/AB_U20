cmake_minimum_required(VERSION 3.10)

# Set the project name
project(HospitalManagement)

# Add the executable
add_executable(hospital
    Hospital.cpp
    GestionCitas.cpp
    GestionDatos.cpp
    Fecha.cpp
    Medico.cpp
    Paciente.cpp
    CitaMedica.cpp
)

# Include directories
target_include_directories(hospital PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})