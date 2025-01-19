#pragma once

#include <array>
#include <vector>
#include "Figure.h"
#include "Triangle.h"


class Grid 
{
public:
    std::vector<std::array<std::vector<Triangle>, 2>> triangles; //TODO move to protected
protected:
    unsigned int height;
public:
    virtual ~Grid() {};

    bool inGrid(Triangle triangle);

    bool inGrid(Figure figure);

    //Triangle getTriangle(int a, int b, int c);

    // void fillTriangle(a, b, c);
    // void clearTriangle(a, b, c);
    // bool rowIsFull(b);
    // int clearRow(b); // returns number of triangles in a row
};

class ParallelogramGrid : public Grid 
{
public:
    ParallelogramGrid(int min_a, int max_a, int min_b, int max_b);
    ParallelogramGrid(int max_a, int max_b);
};

