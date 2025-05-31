#include <iostream>
#include "../include/Figuras.hpp"

Circulo::Circulo(const Punto& c, double _r) : centro(c), r(_r) {}

Punto Circulo::getCentro() const { return centro;}

double Circulo::getRadio() const { return r;}

void Circulo::setCentro(const Punto& c) { centro = c;}

void Circulo::setRadio(double rad) { r = rad;}

//---------------------------------------------------------------------------------
Elipse::Elipse(const Punto& c, double _a, double _b): centro(c), a(_a), b(_b) {};

Punto Elipse::getCentro() const{ return centro;}

double Elipse::getSemiejeMayor() const{ return a;}

double Elipse::getSemiejeMenor() const{ return b;}

void Elipse::setCentro(const Punto& c) { centro = c;}

void Elipse::setSemiejeMayor(double ra) { a = ra;}

void Elipse::setSemiejeMenor(double rb) { a = rb;}

//---------------------------------------------------------------------------------
Rectangulo::Rectangulo(Punto p, double anch, double l) : pos(p), ancho(anch), largo(l) {}

Punto Rectangulo::getPos() const { return pos;}

double Rectangulo::getAncho() const { return ancho;}

double Rectangulo::getLargo() const { return largo;}

void Rectangulo::setPos(const Punto& p) { pos = p;}

void Rectangulo::setAncho(double anch) { ancho = anch;}

void Rectangulo::setLargo(double l) { largo = l;}
