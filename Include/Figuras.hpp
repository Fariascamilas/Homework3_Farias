#pragma once
#include <iostream>
#include "Punto.hpp"

class Circulo{
private:
    Punto centro;
    double r;
public:
    Circulo(const Punto& c, double _r);
    ~Circulo() = default;
    Punto getCentro() const;
    double getRadio() const;
    void setCentro(const Punto& c);
    void setRadio(double rad);        
};

class Elipse{
private:
    Punto centro;
    double a; // Semieje mayor
    double b; // Semieje menor
public:
    Elipse(const Punto& c, double _a, double _b);
    ~Elipse() = default;
    Punto getCentro() const;
    double getSemiejeMayor() const;
    double getSemiejeMenor() const;
    void setCentro(const Punto& c);
    void setSemiejeMayor(double ra);
    void setSemiejeMenor(double rb);
};

class Rectangulo{
private:
    Punto pos; // Vértice izquierdo inferior
    double ancho;
    double largo;
public:
    Rectangulo(Punto p, double anch, double l);
    ~Rectangulo() = default;
    Punto getPos() const;
    double getAncho() const;
    double getLargo() const;
    void setPos(const Punto& p);
    void setAncho(double anch);
    void setLargo(double l);
};
