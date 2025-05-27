#pragma once
#include <iostream>

class Punto{
private:
    double x;
    double y;
public:
    Punto(double _x, double _y);
    ~Punto() = default;
    double getX() const;
    double getY() const;
    void setX(double val);
    void setY(double val);
};