#pragma once
#include <iostream>
#include <fstream>
#include <memory>

/**
 * @brief Interfaz para las operaciones de serialización y deserialización de mediciones.
 */
class IMediciones {
public:
    /**
     * @brief Serializa los datos de la medición en un flujo de salida.
     * 
     * @param out Flujo de salida para la serialización.
     */
    virtual void serializar(std::ofstream& out) const = 0;
    
    /**
     * @brief Deserializa los datos de la medición desde un flujo de entrada.
     * 
     * @param in Flujo de entrada para la deserialización.
     */
    virtual void deserializar(std::ifstream& in) = 0;

    /**
     * @brief Destructor virtual.
     */
    virtual ~IMediciones() = default;
};

/**
 * @brief Clase base que implementa funciones para una medición.
 * 
 * Esta clase provee una implementación base para la serialización/deserialización y
 * define una interfaz para imprimir información de la medición, dejando la implementación
 * de dicho método a las clases derivadas.
 */
class MedicionBase : public IMediciones {
public:
    /**
     * @brief Constructor que inicializa la medición con un tiempo dado.
     * 
     * @param t Tiempo de la medición.
     */
    MedicionBase(const float& t);

    /**
     * @brief Retorna el tiempo de la medición.
     * 
     * @return float Tiempo almacenado.
     */
    float getTiempo() const;

    /**
     * @brief Imprime la información relevante de la medición.
     * 
     * Método virtual puro que debe implementarse en las clases derivadas.
     */
    virtual void imprimir() const = 0;

    /**
     * @brief Serializa la medición en un flujo de salida.
     * 
     * @param out Flujo de salida para la serialización.
     */
    virtual void serializar(std::ofstream& out) const override;

    /**
     * @brief Deserializa la medición desde un flujo de entrada.
     * 
     * @param in Flujo de entrada para la deserialización.
     */
    virtual void deserializar(std::ifstream& in) override;
protected:
    /// Tiempo de la medición almacenado como un puntero único.
    std::unique_ptr<float> tiempoMedicion;
};