#pragma once
#include "Mediciones.hpp"

/**
 * @brief Clase que representa una medición de posición geográfica.
 *
 * Esta clase extiende de MedicionBase y permite almacenar información de
 * latitud, longitud y altitud, junto con el tiempo asociado a la medición.
 */
class Posicion : public MedicionBase{
public:
    /// Latitud de la posición.
    float latitud;
    /// Longitud de la posición.
    float longitud;
    /// Altitud de la posición.
    float altitud;

    /**
     * @brief Constructor de la clase Posicion.
     *
     * Inicializa una medición de posición con latitud, longitud, altitud y tiempo.
     *
     * @param lat Latitud de la posición.
     * @param lon Longitud de la posición.
     * @param alt Altitud de la posición.
     * @param t Tiempo de la medición.
     */
    Posicion(float lat, float lon, float alt, float t);
    
    /**
     * @brief Imprime la información de la posición.
     *
     * Implementa la función virtual pura de MedicionBase para mostrar los datos
     * asociados a la medición de posición.
     */
    void imprimir() const override;
    
    /**
     * @brief Serializa la posición en un flujo de salida.
     *
     * Guarda en el flujo los datos de latitud, longitud, altitud y tiempo.
     *
     * @param out Flujo de salida para la serialización.
     */
    void serializar(std::ofstream& out) const override;
    
    /**
     * @brief Deserializa la posición desde un flujo de entrada.
     *
     * Recupera los datos de latitud, longitud, altitud y tiempo desde el flujo.
     *
     * @param in Flujo de entrada para la deserialización.
     */
    void deserializar(std::ifstream& in) override;
};