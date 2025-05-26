#pragma once
#include "Mediciones.hpp"

class Presion : public MedicionBase{
public:
    float presionEstatica; // p
    float presionDinamica; // q
    Presion(float p, float q, float t);
    void imprimir() const override;
    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
};