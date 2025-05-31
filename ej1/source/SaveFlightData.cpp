#include <iostream>
#include <fstream>
#include "../include/SaveFlightData.hpp"

SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q) : posicion(0.0f,0.0f,0.0f,0.0f), presion(0.0f,0.0f,0.0f) {
    std::ofstream o("SaveFlightData.bin", std::ios::binary);
    p.serializar(o);
    q.serializar(o);
    o.close();

    std::ifstream i("SaveFlightData.bin", std::ios::binary);
    posicion.deserializar(i);
    presion.deserializar(i);
    i.close();
}

void SaveFlightData::serializar(std::ofstream& out) const {
    if(!out) throw std::runtime_error("Ocurrio un error con el archivo para escritura\n");

    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(std::ifstream& in){
    if(!in) throw std::runtime_error("Ocurrio un error con el archivo para lectura\n");

    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() const{
    std::cout<<"-----Save Flight Data-----"<<std::endl;
    presion.imprimir();
    posicion.imprimir();
    std::cout<<"--------------------------"<<std::endl;
}