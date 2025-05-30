#pragma once
#include <iostream>
#include <numbers>
#include "Figuras.hpp"
#include "Punto.hpp"

template<typename T>
class ProcesadorFigura;

template<>
class ProcesadorFigura<Circulo>{
public:
    double calcularArea(const Circulo& circulo) const{
        double r = circulo.getRadio();
        return std::numbers::pi * r * r;
    }
};

template<>
class ProcesadorFigura<Elipse>{
public:
    ProcesadorFigura() {}
    double calcularArea(const Elipse& elipse) const{
        double a = elipse.getSemiejeMayor();
        double b = elipse.getSemiejeMenor();
        return std::numbers::pi * a * b;
    }
};

template<>
class ProcesadorFigura<Rectangulo>{
public:
    ProcesadorFigura() {}
    double calcularArea(const Rectangulo& rectangulo) const{
        double ancho = rectangulo.getAncho();
        double largo = rectangulo.getLargo();
        return ancho * largo;
    }
};

/*
A continuación se muestran las fórmulas para calcular el área de cada figura:

- **Círculo:**  
  Área = π · r²  
  (donde r es el radio)

- **Rectángulo:**  
  Área = ancho · largo

- **Elipse:**  
  Área = π · a · b  
  (donde a y b son los semiejes mayor y menor, respectivamente)
*/