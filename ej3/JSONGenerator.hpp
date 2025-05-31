#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <fstream>
#include <concepts>
#include <sstream>
#include <iomanip>

/**
 * @brief Concepto que restringe los tipos válidos para la generación de vectores JSON.
 * 
 * Los tipos válidos son: std::string, std::pair<int,int> y double.
 */
template <typename T>
concept ValidParam = std::is_same_v<T,std::string> || std::is_same_v<T,std::pair<int,int>> || std::is_same_v<T,double>;

#define D "vec_doubles"
#define P "palabras"
#define L "listas"

/**
 * @brief Plantilla para generar representaciones JSON de vectores de datos.
 * 
 * La clase VectorGenerator almacena datos de tipo T y proporciona métodos para agregar datos,
 * obtener datos procesados en formato JSON y representar dichos datos como una cadena.
 * 
 * @tparam T Tipo de dato. Debe cumplir con el concepto ValidParam.
 */
template<ValidParam T>
class VectorGenerator{
private:
    /// Vector que almacena los datos.
    std::vector<T> data;
public:
    /**
     * @brief Constructor por defecto.
     */
    VectorGenerator(){}
    
    /**
     * @brief Agrega un dato al vector.
     * 
     * @param param Dato de tipo T a agregar.
     */
    void addData(T param){
        data.push_back(param);
    }
    
    /**
     * @brief Obtiene los datos almacenados en el vector.
     * 
     * @return std::vector<std::string> Representación en cadena de los datos.
     */
    std::vector<std::string> getData() const{
        return data;
    }
    
    /**
     * @brief Procesa los datos del vector y los representa en formato JSON.
     * 
     * Dependiendo del tipo T, el método formatea los datos:
     * - Para std::string: cada elemento se encierra entre comillas.
     * - Para std::pair<int,int>: cada par se representa como un array [x, y].
     * - Para double: cada número se formatea con una precisión fija de 1 decimal.
     * 
     * @return std::string Cadena en formato JSON con los datos procesados.
     */
    std::string processData() const{
        std::string str = "[";

        if constexpr(std::is_same_v<T,std::string>){
            for(size_t i = 0; i < data.size(); ++i){
                str += "\"" + data[i] + "\"";
                if(i != data.size()-1)
                    str += ", ";
            }
        }
        else if constexpr(std::is_same_v<T,std::pair<int,int>>){
            for(size_t i = 0; i < data.size(); ++i){
                str += "[";
                str += std::to_string(data[i].first) + ", " + std::to_string(data[i].second);
                str += "]";
                if(i != data.size()-1)
                    str += ", ";
            }
        }
        else if constexpr(std::is_same_v<T,double>){
           for(size_t i = 0; i < data.size(); ++i){
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(1) << data[i];
                str += oss.str();
                if(i != data.size()-1)
                str += ", ";
           }
        }
        str += "]";
        return str;
    }
};

/**
 * @brief Clase para generar etiquetas y crear un JSON a partir de múltiples vectores.
 * 
 * La clase TagGenerator facilita la construcción de un objeto JSON combinando diferentes vectores
 * de datos, cada uno etiquetado de acuerdo al tipo contenido.
 */
class TagGenerator{
public:
    /// Vector que almacena pares de etiquetas y datos en formato JSON.
    std::vector<std::pair<std::string,std::string>> JSON;
    
    /**
     * @brief Agrega una etiqueta y su correspondiente representación JSON de datos.
     * 
     * El método utiliza una especialización basada en el tipo T para determinar la etiqueta:
     * - Para std::string se usa la etiqueta definida en P.
     * - Para double se usa la etiqueta definida en D.
     * - Para std::pair<int,int> se usa la etiqueta definida en L.
     * 
     * @tparam T Tipo de dato que cumple con ValidParam.
     * @param d VectorGenerator que contiene los datos a agregar.
     */
    template <typename T>
    void addTags(const VectorGenerator<T>& d){
        std::string tag;
        if constexpr(std::is_same_v<T,std::string>){
            tag = P;
        }
        else if constexpr(std::is_same_v<T,double>){
            tag = D;
        }
        else if constexpr(std::is_same_v<T,std::pair<int,int>>){
            tag = L;
        }
        JSON.push_back({tag, d.processData()});
    }
    
    /**
     * @brief Crea y escribe el JSON completo en un archivo.
     * 
     * El método construye una cadena en formato JSON a partir del vector de etiquetas y datos,
     * aplicando un formato especial para las etiquetas correspondientes a listas.
     * Finalmente, escribe el JSON en un archivo llamado "myJSON.json".
     * 
     * @throws std::runtime_error Si ocurre un error al abrir el archivo de salida.
     */
    void createJSON(){
        std::string json = "{\n";
        // Formato especial para 'listas' (agregamos salto de línea y sangría)
        for(size_t i = 0; i < JSON.size(); ++i){
            if(JSON[i].first == L){
                json += "   \"" + JSON[i].first + "\" : [\n      " + JSON[i].second;
                // Ajustamos el formato de listas para mostrar cada par en una línea
                // Reemplazamos ", " por ",\n      " para los elementos de la matriz
                size_t pos = 0;
                while((pos = json.find("], ", pos)) != std::string::npos){
                    json.replace(pos, 3, "],\n      ");
                    pos += 9;
                }
                json += "\n   ]";
            }
            else{
                json += "   \"" + JSON[i].first + "\" : " + JSON[i].second;
            }
            if(i != JSON.size()-1)
                json += ",\n";
            else
                json += "\n";
        }
        json += "}";
        
        std::ofstream outf("myJSON.json");
        if(!outf){
            throw std::runtime_error("Error con el archivo de salida (JSON)");
        }
        outf << json;
        outf.close();
    }
}; 