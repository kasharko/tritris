#include "Figure.h"


Figure::Figure(sf::Vector3i pivot): pivot(pivot)
{
    // TODO: check validity of coords

}

Figure::Figure(int a, int b, int c): pivot(a, b, c)
{
    // TODO: check validity of coords
}

void Figure::rotateAround(int nTimes60Grad) {
    for (auto& triangle : triangles) {
        triangle.rotateAround(this->pivot, nTimes60Grad);
    }
}


Figure1::Figure1(int a, int b, int c): Figure(a, b, c)
{
    pivot = sf::Vector3i(a, b, c);
    // (1,0,1), (1,0,0), (2,0,0)
    // TODO: why is it rotated?
    Triangle* tri = nullptr;
    tri = new Triangle(a + 1, b, c + 1);
    triangles.push_back(*tri);
    tri = new Triangle(a + 1, b, c);
    triangles.push_back(*tri);
    tri = new Triangle(a + 2, b, c);
    triangles.push_back(*tri);
}

Figure1::Figure1(sf::Vector3i pivot): Figure1(pivot.x, pivot.y, pivot.z)
{
// TODO TBI
}
