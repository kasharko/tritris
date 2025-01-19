#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Triangle.h"
#include "Figure.h"
#include "Grid.h"

inline sf::RectangleShape makeLineFromVector3i(sf::Vector3i vertex1, sf::Vector3i vertex2, int scale)
{   

    float vertex1x = toCartesian(vertex1).x * scale;
    float vertex1y = toCartesian(vertex1).y * scale;
    float vertex2x = toCartesian(vertex2).x * scale;
    float vertex2y = toCartesian(vertex2).y * scale;
    sf::Vector2f startPoint(vertex1x, vertex1y);
    sf::Vector2f endPoint(vertex2x, vertex2y);
    float lineLength = std::sqrt(std::pow(endPoint.x - startPoint.x, 2) + 
                                 std::pow(endPoint.y - startPoint.y, 2));
    float angle = std::atan2(endPoint.y - startPoint.y, endPoint.x - startPoint.x) * 180 / 3.14159;
    sf::RectangleShape line = sf::RectangleShape(sf::Vector2f(lineLength, 3)); 
    line.setPosition(startPoint);                              
    line.setRotation(angle); 
    line.setFillColor(sf::Color::White);
    return line;
}


inline void draw_triangle(Triangle triangle, sf::RenderWindow* window, int scale = 50)
{       
        sf::Vector3i left_vertex = triangle.getLeftVertex();
        sf::Vector3i right_vertex = triangle.getRightVertex();
        sf::Vector3i vert_vertex = triangle.getVerticalVertex();
        window->draw(makeLineFromVector3i(left_vertex, right_vertex, scale));
        window->draw(makeLineFromVector3i(right_vertex, vert_vertex, scale));
        window->draw(makeLineFromVector3i(vert_vertex, left_vertex, scale));
        // TODO: line is shifted? triangles look different between up and down  
        
}

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse positions

	//Resources

	//Text

	//Game logic
	bool endGame;

	//Game objects
    std::vector<sf::VertexArray> triVertexes;
    Triangle *triangle = nullptr;
    sf::RectangleShape *line = nullptr;
    ParallelogramGrid *grid = nullptr;
    
    //std::vector<sf::RectangleShape> enemies;
	//sf::RectangleShape enemy;

	//Private functions
	void initVariables();
	void initWindow();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;

	//Functions
	void pollEvents();
	void update();
	void render();
};
