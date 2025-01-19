#pragma once

#include <vector>
#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

#include "Triangle.h"

class Figure
{
protected:
    std::vector<Triangle> triangles;
    sf::Vector3i pivot;

public:
    Figure(sf::Vector3i pivot);
    Figure(int a = 0, int b = 0, int c = 0);
    virtual ~Figure() {};

    std::vector<Triangle> & getTriangles() {return triangles;}
    const std::vector<Triangle> & getTriangles() const {return triangles;}

    void rotateAround(int nTimes60Grad);
};

class Figure1 : public Figure
{
    /*   -----
     *  /\   /\
     * /  \ /  \
     * ----X----
     */
public:
    Figure1(int a, int b, int c);
    Figure1(sf::Vector3i pivot);
};
