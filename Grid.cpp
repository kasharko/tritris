#include "Grid.h"


bool Grid::inGrid(Triangle triangle)
{
    //TODO TBI
    // if isUp: check the vector.at(1), otherwise (0)
    return true;
}

bool Grid::inGrid(Figure figure)
{
    //TODO TBI
    // iterate over each triangle and inGrid(triangle)
    return true;
}
/*
Triangle getTriangle(int a, int b, int c)
{   
    if ((a + b + c > 2) || (a + b + c < 1))
        throw std::invalid_argument("Invalid pivot coordinates: a + b + c must equal 1 or 2.");
    // TODO: check that it's within grid?
    const int tri_a = a - min_a;
    const int tri_b = b - min_b;
    const int tri_c = (a + b + c == 1) ? 0 : 1;
    return triangles.at(tri_b).at(tri_c).at(tri_a);
}
*/


ParallelogramGrid::ParallelogramGrid(int min_a, int max_a, int min_b, int max_b)
{   
    if (max_a <= min_a)
        throw std::invalid_argument("Invalid arguments: must be max_a > min_a.");
    if (max_b <= min_b)
        throw std::invalid_argument("Invalid arguments: must be max_b > min_b.");
    const int width_par = max_a - min_a;
    const int height_par = max_b - min_b;
    height = static_cast<unsigned int>(height_par);
    triangles.resize(height_par);
    for (size_t i = 0; i < height_par; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            std::vector<Triangle> row;
            for (size_t k = 0; k < width_par; ++k) {
                const int a = min_a + k;
                const int b = min_b + i;
                const int c = 1 + j - a - b;
                row.emplace_back(a, b, c);
                //row.emplace_back(Triangle(a, b, c));
            }
            triangles[i][j] = std::move(row);
        }
    }
}
    

ParallelogramGrid::ParallelogramGrid(int max_a, int max_b) : ParallelogramGrid(0, max_a, 0, max_b) {}

