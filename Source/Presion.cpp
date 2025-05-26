#include <iostream>
#include <fstream>
#include "../Include/Presion.hpp"

Presion::Presion(float p, float q, float t) : MedicionBase(t), presionEstatica(p), presionDinamica(q) {}

void Presion::imprimir() const{
    std::cout<<"==== Presión ===="<<std::endl 
            <<" - P. Estática: "<<presionEstatica<<std::endl
            <<" - P. Dinámica: "<<presionDinamica<<std::endl
            <<" - Tiempo de Medición: "<<*tiempoMedicion.get()<<std::endl;
}

void Presion::serializar(std::ofstream& out) const{
    if(!out) throw std::runtime_error("Ocurrio un error al acceder al archivo para escritura\n");

    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::deserializar(std::ifstream& in){
    if (!in) throw std::runtime_error("Ocurrio un error al acceder al archivo para escritura\n");

    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&presionEstatica),sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica),sizeof(presionDinamica));
}