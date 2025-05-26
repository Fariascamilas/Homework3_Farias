#pragma once
#include "Mediciones.hpp"

class Posicion : public MedicionBase{
public:
    float latitud;
    float longitud;
    float altitud;
    Posicion(float lat, float lon, float alt, float t);
    void imprimir() const override;
    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
};