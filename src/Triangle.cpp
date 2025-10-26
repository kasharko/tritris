#include "Triangle.h"


Triangle::Triangle(int a, int b, int c, bool filled) : a(a), b(b), c(c), filled(filled)
{
    if (a + b + c != 1 && a + b + c != 2) 
        throw std::invalid_argument("Invalid triangle coordinates: a + b + c must equal 1 or 2.");
}

Triangle::~Triangle()
{
}

sf::Vector2f Triangle::getCenter() const
{
    float x = 0.5 * a - 0.5 * c;
    float y =  - std::sqrt(3) / 6 * a + std::sqrt(3) / 3 * b - std::sqrt(3) / 6 * c;
    sf::Vector2f center = {x, y};
    return center;
}

sf::Vector3i Triangle::getLeftVertex() const
{  
    sf::Vector3i shift; 
    if (this->isUp())
        shift = {-1, -1, 0};
    else
        shift = {-1, 0, 0};     
    return this->vector3() + shift;
}

sf::Vector3i Triangle::getRightVertex() const
{  
    sf::Vector3i shift; 
    if (this->isUp())
        shift = {0, -1, -1};
    else
        shift = {0, 0, -1};     
    return this->vector3() + shift;
}

sf::Vector3i Triangle::getVerticalVertex() const
{
    sf::Vector3i shift; 
    if (this->isUp())
        shift = {-1, 0, -1};
    else
        shift = {0, -1, 0};     
    return this->vector3() + shift;
}


void Triangle::rotateAroundZero(int nTimes60Grad)
{
    nTimes60Grad = nTimes60Grad % 6;
    switch (nTimes60Grad)
    {
        case 1:
            moveTo(1 - b, 1 - c, 1 - a);
        case 2:
            moveTo(c, a, b);
        case 3:
        moveTo(1 - a, 1 - b, 1 - c);
        case 4:
            moveTo(b, c, a);
        case 5:
            moveTo(1 - c, 1 - a, 1 - b);
    }
}

void Triangle::rotateAround(sf::Vector3i pivot, int nTimes60Grad){
    int sum = pivot.x + pivot.y + pivot.z;
    if (sum < 0 || sum > 2)
        throw std::invalid_argument("Invalid pivot coordinates: a + b + c must equal 0, 1 or 2.");
    if (sum != 0 && nTimes60Grad % 2 != 0)
        throw std::invalid_argument("Rotation around triangle should be even (~120 grad).");
    moveBy(-pivot);
    rotateAroundZero(nTimes60Grad);
    moveBy(pivot);
}
