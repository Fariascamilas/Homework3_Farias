#pragma once
#include <iostream>
#include <numbers>
#include "Figuras.hpp"
#include "Punto.hpp"

/**
 * @brief Plantilla base para procesar figuras geométricas.
 *
 * La plantilla se especializa para cada tipo de figura.
 */
template<typename T>
class ProcesadorFigura;

/**
 * @brief Especialización de ProcesadorFigura para círculos.
 */
template<>
class ProcesadorFigura<Circulo>{
public:
    /**
     * @brief Calcula el área de un círculo.
     *
     * Utiliza la fórmula: Área = π * r², donde r es el radio del círculo.
     *
     * @param circulo Objeto de tipo Circulo.
     * @return double Área del círculo.
     */
    double calcularArea(const Circulo& circulo) const{
        double r = circulo.getRadio();
        return std::numbers::pi * r * r;
    }
};

/**
 * @brief Especialización de ProcesadorFigura para elipses.
 */
template<>
class ProcesadorFigura<Elipse>{
public:
    /**
     * @brief Constructor por defecto.
     */
    ProcesadorFigura() {}

    /**
     * @brief Calcula el área de una elipse.
     *
     * Utiliza la fórmula: Área = π * a * b, donde a y b son los semiejes mayor y menor, respectivamente.
     *
     * @param elipse Objeto de tipo Elipse.
     * @return double Área de la elipse.
     */
    double calcularArea(const Elipse& elipse) const{
        double a = elipse.getSemiejeMayor();
        double b = elipse.getSemiejeMenor();
        return std::numbers::pi * a * b;
    }
};

/**
 * @brief Especialización de ProcesadorFigura para rectángulos.
 */
template<>
class ProcesadorFigura<Rectangulo>{
public:
    /**
     * @brief Constructor por defecto.
     */
    ProcesadorFigura() {}
    
    /**
     * @brief Calcula el área de un rectángulo.
     *
     * Utiliza la fórmula: Área = ancho * largo.
     *
     * @param rectangulo Objeto de tipo Rectangulo.
     * @return double Área del rectángulo.
     */
    double calcularArea(const Rectangulo& rectangulo) const{
        double ancho = rectangulo.getAncho();
        double largo = rectangulo.getLargo();
        return ancho * largo;
    }
};