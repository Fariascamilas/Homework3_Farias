#pragma once
#include "Mediciones.hpp"

/**
 * @brief Clase que representa una medición de presión.
 *
 * Esta clase extiende de MedicionBase y permite almacenar los valores de presión 
 * estática y dinámica, junto con el tiempo asociado a la medición.
 */
class Presion : public MedicionBase{
public:
    /// p
    float presionEstatica;
    /// q
    float presionDinamica; 

    /**
     * @brief Constructor de la clase Presion.
     *
     * Inicializa una medición de presión con valores de presión estática, presión dinámica y tiempo.
     *
     * @param p Valor de la presión estática.
     * @param q Valor de la presión dinámica.
     * @param t Tiempo de la medición.
     */
    Presion(float p, float q, float t);

    /**
     * @brief Imprime la información de la presión.
     *
     * Implementa la función virtual pura de MedicionBase para mostrar los datos
     * asociados a la medición de presión.
     */
    void imprimir() const override;

    /**
     * @brief Serializa la medición de presión en un flujo de salida.
     *
     * Guarda en el flujo los datos de presión estática, presión dinámica y el tiempo.
     *
     * @param out Flujo de salida para la serialización.
     */
    void serializar(std::ofstream& out) const override;
    
    /**
     * @brief Deserializa la medición de presión desde un flujo de entrada.
     *
     * Recupera los datos de presión estática, presión dinámica y el tiempo desde el flujo.
     *
     * @param in Flujo de entrada para la deserialización.
     */
    void deserializar(std::ifstream& in) override;
};