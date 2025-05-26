#include <fstream>
#include <iostream>
#include "../Include/Posicion.hpp"

Posicion::Posicion(float lat, float lon, float alt, float t) : MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) {}

void Posicion::imprimir() const {
    std::cout<<"==== Posición ===="<<std::endl 
            <<" - Latitud: "<<latitud<<std::endl
            <<" - Longitud: "<<longitud<<std::endl
            <<" - Altitud: "<<altitud<<std::endl
            <<" - Tiempo de Medición: "<<*tiempoMedicion.get()<<std::endl;
}

void Posicion::serializar(std::ofstream& out) const {
    if (!out) throw std::runtime_error("Ocurrio un error con el archivo para escritura\n");

    MedicionBase::serializar(out);    
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
}

void Posicion::deserializar(std::ifstream& in){
    if(!in) throw std::invalid_argument("Ocurrio un error con el archivo para lectura\n");

    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
}