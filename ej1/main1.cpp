#include "include/Presion.hpp"
#include "include/Posicion.hpp"
#include "include/SaveFlightData.hpp"
#include <fstream>
int main(){
    // Pruebas Presion
    std::cout<<"Prueba 1: Serialización y deserialización de objetos tipo Presión"<<std::endl;
    Presion presion(0.0f, 0.0f, 0.0f);
    Presion aCopiar(101.3f, 5.8f, 6.1f);

    // Antes
    std::cout<<"Antes de la trasferencia: "<<std::endl;
    aCopiar.imprimir();
    presion.imprimir();

    std::ofstream out("prueba.bin", std::ios::binary);
    aCopiar.serializar(out);
    out.close();

    std::ifstream in("prueba.bin", std::ios::binary);
    presion.deserializar(in);
    in.close();

    std::cout<<"--------------------------"<<std::endl;

    // Después
    std::cout<<"Después de la trasferencia: "<<std::endl;
    aCopiar.imprimir();
    presion.imprimir();
    std::cout<<std::endl;

    //-----------------------------------------------------------------------------
    // Pruebas Posicion
    std::cout<<"Prueba 2: Serialización y deserialización de objetos tipo Posición"<<std::endl;
    Posicion posicion(0.0f, 0.0f, 0.0f, 0.0);
    Posicion aCopiar2(-34.6f, -58.4f, 950.0f, 5.3);

    // Antes
    std::cout<<"Antes de la trasferencia: "<<std::endl;
    aCopiar2.imprimir();
    posicion.imprimir();

    std::ofstream out2("prueba.bin", std::ios::binary);
    aCopiar2.serializar(out2);
    out2.close();

    std::ifstream in2("prueba.bin", std::ios::binary);
    posicion.deserializar(in2);
    in2.close();

    std::cout<<"--------------------------"<<std::endl;
    
    // Después
    std::cout<<"Después de la trasferencia: "<<std::endl;
    aCopiar2.imprimir();
    posicion.imprimir();
    std::cout<<std::endl;

    //-----------------------------------------------------------------------------
    // Pruebas SaveFlightData
    std::cout<<"Prueba 3: Serialización y deserialización de objetos tipo SaveFlightData"<<std::endl;
    Posicion posVacia(0.0f,0.0f,0.0f,0.0f);
    Presion presVacia(0.0f,0.0f,0.0f);

    SaveFlightData myFlight(posicion,presion);
    SaveFlightData empty(posVacia,presVacia);

    // Antes
    std::cout<<"Antes de la trasferencia: "<<std::endl;
    myFlight.imprimir();
    empty.imprimir();

    std::ofstream out3("prueba.bin", std::ios::binary);
    myFlight.serializar(out3);
    out3.close();

    std::ifstream in3("prueba.bin", std::ios::binary);
    empty.deserializar(in3);
    in3.close();
    
    // Después
    std::cout<<"Después de la trasferencia: "<<std::endl;
    myFlight.imprimir();
    empty.imprimir();

    return 0;
}