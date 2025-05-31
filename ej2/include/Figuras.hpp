#pragma once
#include <iostream>
#include "Punto.hpp"

/**
 * @brief Clase que representa un círculo.
 */
class Circulo{
private:
    /// Centro del círculo.
    Punto centro;
    /// Radio del círculo.
    double r;
public:
    /**
     * @brief Constructor de la clase Circulo.
     *
     * Inicializa un círculo con un centro y un radio dado.
     *
     * @param c Centro del círculo.
     * @param _r Radio del círculo.
     */
    Circulo(const Punto& c, double _r);

    /**
     * @brief Destructor por defecto.
     */
    ~Circulo() = default;

    /**
     * @brief Obtiene el centro del círculo.
     *
     * @return Punto Centro del círculo.
     */
    Punto getCentro() const;

    /**
     * @brief Obtiene el radio del círculo.
     *
     * @return double Radio del círculo.
     */
    double getRadio() const;

    /**
     * @brief Define un nuevo centro para el círculo.
     *
     * @param c Nuevo centro del círculo.
     */
    void setCentro(const Punto& c);

    /**
     * @brief Define un nuevo radio para el círculo.
     *
     * @param rad Nuevo radio del círculo.
     */
    void setRadio(double rad);        
};

/**
 * @brief Clase que representa una elipse.
 */
class Elipse{
private:
    /// Centro de la elipse.
    Punto centro;
    /// Semieje mayor de la elipse.
    double a;
    /// Semieje menor de la elipse.
    double b;
public:
    /**
     * @brief Constructor de la clase Elipse.
     *
     * Inicializa una elipse con un centro, semieje mayor y semieje menor.
     *
     * @param c Centro de la elipse.
     * @param _a Valor del semieje mayor.
     * @param _b Valor del semieje menor.
     */
    Elipse(const Punto& c, double _a, double _b);

    /**
     * @brief Destructor por defecto.
     */
    ~Elipse() = default;

    /**
     * @brief Obtiene el centro de la elipse.
     *
     * @return Punto Centro de la elipse.
     */
    Punto getCentro() const;
    
    /**
     * @brief Obtiene el valor del semieje mayor.
     *
     * @return double Valor del semieje mayor.
     */
    double getSemiejeMayor() const;
    
    /**
     * @brief Obtiene el valor del semieje menor.
     *
     * @return double Valor del semieje menor.
     */
    double getSemiejeMenor() const;
    
    /**
     * @brief Define un nuevo centro para la elipse.
     *
     * @param c Nuevo centro de la elipse.
     */
    void setCentro(const Punto& c);
    
    /**
     * @brief Define un nuevo valor para el semieje mayor.
     *
     * @param ra Nuevo valor del semieje mayor.
     */
    void setSemiejeMayor(double ra);
    
    /**
     * @brief Define un nuevo valor para el semieje menor.
     *
     * @param rb Nuevo valor del semieje menor.
     */
    void setSemiejeMenor(double rb);
};

/**
 * @brief Clase que representa un rectángulo.
 */
class Rectangulo{
private:
    /// Posición del vértice inferior izquierdo.
    Punto pos;
    /// Ancho del rectángulo.
    double ancho;
    /// Largo del rectángulo.
    double largo;
public:
    /**
     * @brief Constructor de la clase Rectangulo.
     *
     * Inicializa un rectángulo con la posición del vértice inferior izquierdo, ancho y largo.
     *
     * @param p Posición del vértice inferior izquierdo.
     * @param anch Ancho del rectángulo.
     * @param l Largo del rectángulo.
     */
    Rectangulo(Punto p, double anch, double l);
    
    /**
     * @brief Destructor por defecto.
     */
    ~Rectangulo() = default;
    
    /**
     * @brief Obtiene la posición del vértice inferior izquierdo.
     *
     * @return Punto Posición del vértice inferior izquierdo.
     */
    Punto getPos() const;
    
    /**
     * @brief Obtiene el ancho del rectángulo.
     *
     * @return double Ancho del rectángulo.
     */
    double getAncho() const;
    
    /**
     * @brief Obtiene el largo del rectángulo.
     *
     * @return double Largo del rectángulo.
     */
    double getLargo() const;
    
    /**
     * @brief Define una nueva posición para el vértice inferior izquierdo.
     *
     * @param p Nueva posición.
     */
    void setPos(const Punto& p);
    
    /**
     * @brief Define un nuevo ancho para el rectángulo.
     *
     * @param anch Nuevo ancho.
     */
    void setAncho(double anch);
    
    /**
     * @brief Define un nuevo largo para el rectángulo.
     *
     * @param l Nuevo largo.
     */
    void setLargo(double l);
};
