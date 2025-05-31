#include <iostream>
#include "../include/Punto.hpp"

Punto::Punto(double _x, double _y) : x(_x), y(_y) {}

double Punto::getX() const{ return x;}

double Punto::getY() const{ return y;}

void Punto::setX(double val) { x = val;}

void Punto::setY(double val) { y = val;}