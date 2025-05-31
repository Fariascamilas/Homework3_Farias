#include <iostream>
#include "JSONGenerator.hpp"

int main() {
    // Creamos instancias de VectorGenerator para cada tipo
    VectorGenerator<double> doubleGen;
    doubleGen.addData(1.3);
    doubleGen.addData(2.1);
    doubleGen.addData(3.2);

    VectorGenerator<std::string> stringGen;
    stringGen.addData("Hola");
    stringGen.addData("Mundo");

    VectorGenerator<std::pair<int,int>> pairGen;
    pairGen.addData({1,2});
    pairGen.addData({3,4});

    // Creamos la instancia de TagGenerator y agregamos las etiquetas correspondientes
    TagGenerator tagGen;
    tagGen.addTags(doubleGen);
    tagGen.addTags(stringGen);
    tagGen.addTags(pairGen);

    // Crear el archivo JSON con los datos agregados
    tagGen.createJSON();

    return 0;
}