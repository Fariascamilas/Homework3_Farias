#pragma once
#include <iostream>

/**
 * @brief Clase que representa un punto en el plano 2D.
 */
class Punto{
private:
    /// Coordinada X del punto.
    double x;
    /// Coordinada Y del punto.
    double y;
public:
    /**
     * @brief Constructor de la clase Punto.
     *
     * Inicializa un punto con las coordenadas dadas.
     *
     * @param _x Valor de la coordenada X.
     * @param _y Valor de la coordenada Y.
     */
    Punto(double _x, double _y);
    
    /**
     * @brief Destructor por defecto.
     */
    ~Punto() = default;
    
    /**
     * @brief Obtiene la coordenada X del punto.
     *
     * @return double Valor de la coordenada X.
     */
    double getX() const;
    
    /**
     * @brief Obtiene la coordenada Y del punto.
     *
     * @return double Valor de la coordenada Y.
     */
    double getY() const;
    
    /**
     * @brief Establece un nuevo valor para la coordenada X.
     *
     * @param val Nuevo valor para X.
     */
    void setX(double val);
    
    /**
     * @brief Establece un nuevo valor para la coordenada Y.
     *
     * @param val Nuevo valor para Y.
     */
    void setY(double val);
};