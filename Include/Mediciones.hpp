#pragma once
#include <iostream>
#include <fstream>
#include <memory>

class IMediciones {
public:
    virtual void serializar(std::ofstream& out) const = 0;
    virtual void deserializar(std::ifstream& in) = 0;
    virtual ~IMediciones() = default;
};

class MedicionBase : public IMediciones {
public:
    MedicionBase(const float& t);
    float getTiempo() const;
    virtual void imprimir() const = 0;
    virtual void serializar(std::ofstream& out) const override;
    virtual void deserializar(std::ifstream& in) override;
protected:
    std::unique_ptr<float> tiempoMedicion;
};