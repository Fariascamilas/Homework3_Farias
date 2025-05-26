#include "../Include/Mediciones.hpp"
#include <memory>

MedicionBase::MedicionBase(const float& t) {
    tiempoMedicion = std::make_unique<float>(t);
}

float MedicionBase::getTiempo() const{
    return *tiempoMedicion;
}

void MedicionBase::serializar(std::ofstream& out) const{
    if (!out) throw std::runtime_error("Ocurrio un error al acceder al archivo para escritura\n");

    int var;
    if (!tiempoMedicion){
        var = 0;
        out.write(reinterpret_cast<const char*>(&var), sizeof(var));
    }
    else{
        var = 1;
        out.write(reinterpret_cast<const char*>(&var), sizeof(var));
        float val = *tiempoMedicion.get();
        out.write(reinterpret_cast<const char*>(&val), sizeof(val));
    }
}

void MedicionBase::deserializar(std::ifstream& in){
    if (!in) throw std::runtime_error("Ocurrio un error al acceder al archivo para lectura\n");

    int isNotEmpty;
    in.read(reinterpret_cast<char*>(&isNotEmpty), sizeof(isNotEmpty));
    if(isNotEmpty){
        float var;
        in.read(reinterpret_cast<char*>(&var),sizeof(var));
        tiempoMedicion = std::make_unique<float>(var);
    }
}