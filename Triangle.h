#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

// TODO: move to common geometry
inline sf::Vector2f toCartesian(sf::Vector3i vector3){
    int a = vector3.x;
    int b = vector3.y;
    int c = vector3.z;
    float x = 0.5 * a - 0.5 * c;
    float y =  - std::sqrt(3) / 6 * a + std::sqrt(3) / 3 * b - std::sqrt(3) / 6 * c;
    sf::Vector2f center = {x, y};
    return center;
}

// TODO: remove SFML everywhere and use it only on a frontend?
/**
 * @brief Represents 2D equilateral triangle with cubic coordinates (a, b, c).
 */
class Triangle
{
private:
    int a, b, c;
    bool filled;

public:

    /**
     * @brief Constructs a triangle from 3 cubic coordinates. 
     *
     * @param a coordinate 'a' (increases from top-left to bottom-right).
     * @param b coordinate 'b' (increases from top-right to bottom-left).
     * @param c coordinate 'c' (increases vertically from bottom to top).
     * @param filled used to control whether it's empty in a grid.
     * @throws std::invalid_argument if a+b+c aren't equal to 1 or 2.
     */
    Triangle(int a, int b, int c, bool filled = false);

	virtual ~Triangle();

    bool isFilled() const {return filled;}

   /**
    * @brief True if the triangle points up.
    */
    bool isUp() const {return a+b+c == 2;}

   /**
    * @brief Builds sf::Vector3i out of the coordinates.
    */
    sf::Vector3i vector3() const {return sf::Vector3i(a,b,c);}

   /**
    * @brief Returns cartesian coordinates of the triangle center.
    */
    sf::Vector2f getCenter() const;

    sf::Vector3i getLeftVertex() const;

    sf::Vector3i getRightVertex() const;

   /**
    * @brief Top vertex if isUp(), otherwise bottom vertex.
    */
    sf::Vector3i getVerticalVertex() const;

   /**
    * @brief Changes coordinates to the new values.
    */
    void moveTo(int a, int b, int c){this->a = a; this->b = b; this->c = c;};

    void moveTo(sf::Vector3i v){this->a = v.x; this->b = v.y; this->c = v.z;};

   /**
    * @brief Shifts coordinates by the argument values.
    */
    void moveBy(int a, int b, int c){moveTo(this->a + a, this->b + b, this->c + c);};

    void moveBy(sf::Vector3i v){moveTo(vector3() + v);};

   /**
    * @brief Rotates triangle around (0, 0, 0) vertex by n*60 grad.
    * @ param nTimes60Grad number of times the triangle will be rotated by 60 grad.
    */
    void rotateAroundZero(int nTimes60Grad);

   /**
    * @brief Rotates around a vertex or triangle.
    * @ param pivot vertex or triangle to rotate around.
    * @ param nTimes60Grad number of times the triangle will be rotated by 60 grad.
    * @throws std::invalid_argument if a+b+c aren't equal to 0, 1 or 2.
    * @throws std::invalid_argument if pivot is a triangle and nTimes60Grad is odd.
    */
    void rotateAround(sf::Vector3i pivot, int nTimes60Grad);
}; 
