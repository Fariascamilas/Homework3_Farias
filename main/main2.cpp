#include <iostream>
#include "../include/ProcesadorFigura.hpp"
#include "../include/Figuras.hpp"
#include "../include/Punto.hpp"

int main(){
    Punto myDot(1.2,-1.2);
    Circulo myCircle(myDot,4);
    Rectangulo myRectangle(myDot,9,6);
    Elipse myEllipse(myDot,4,6);

    ProcesadorFigura<Circulo> processCircle;
    ProcesadorFigura<Rectangulo> processRectangle;
    ProcesadorFigura<Elipse> processEllipse;


    std::cout<<"El área esperada era: 50.2654"<<std::endl<<"El área obtenida fue: "<<processCircle.calcularArea(myCircle)<<std::endl;
    std::cout<<"El área esperada era: 54"<<std::endl<<"El área obtenida fue: "<<processRectangle.calcularArea(myRectangle)<<std::endl;
    std::cout<<"El área esperada era: 75.3982"<<std::endl<<"El área obtenida fue: "<<processEllipse.calcularArea(myEllipse)<<std::endl;
    
    return 0;
}
