#pragma once
#include <iostream>
#include<fstream>
#include <memory>
#include "Posicion.hpp"
#include "Presion.hpp"

/**
 * @brief Clase que maneja el guardado y carga de datos de vuelo.
 *
 * Esta clase encapsula las mediciones de posición y presión, y
 * proporciona métodos para la serialización, deserialización e impresión
 * de los datos de vuelo.
 */
class SaveFlightData {
public:
    /// Medición de posición.
    Posicion posicion;
    /// Medición de presión.
    Presion presion;
    
    /**
     * @brief Constructor de la clase SaveFlightData.
     *
     * Inicializa la clase con las mediciones de posición y presión proporcionadas.
     *
     * @param p Objeto de tipo Posicion que contiene la medición de posición.
     * @param q Objeto de tipo Presion que contiene la medición de presión.
     */
    SaveFlightData(const Posicion& p, const Presion& q);
    
    /**
     * @brief Serializa los datos de vuelo en un flujo de salida.
     *
     * Guarda la medición de posición y la medición de presión en el flujo de salida.
     *
     * @param out Flujo de salida para la serialización.
     */
    void serializar(std::ofstream& out) const;
    
    /**
     * @brief Deserializa los datos de vuelo desde un flujo de entrada.
     *
     * Recupera la medición de posición y la medición de presión desde el flujo de entrada.
     *
     * @param in Flujo de entrada para la deserialización.
     */
    void deserializar(std::ifstream& in);
    
    /**
     * @brief Imprime los datos de vuelo.
     *
     * Muestra en pantalla la información de la medición de posición y presión.
     */
    void imprimir() const;
};