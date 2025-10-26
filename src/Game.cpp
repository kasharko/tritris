#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;
	
	//Game logic
	this->endGame = false;
}

void Game::initWindow()
{
    this->videoMode = sf::VideoMode({800u, 600u});

	
	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
    
    grid = new ParallelogramGrid(2, 11, 2, 11);

    Figure fig = Figure1(3, 6, -9);
    for (Triangle& triangle : fig.getTriangles()) {
        sf::VertexArray triVertex(sf::PrimitiveType::Triangles, 3); // TODO: to make a separate class for TriangleVertexArray?
        //sf::VertexArray triVertex;
        //triVertex.setPrimitiveType(sf::Triangles);
        //triVertex.resize(3);
        int scale = 50;
        std::cout << toCartesian(scale * triangle.getVerticalVertex()).x << ", " 
                  << toCartesian(scale * triangle.getVerticalVertex()).y << std::endl;
        std::cout << toCartesian(scale * triangle.getLeftVertex()).x << ", "
                  << toCartesian(scale * triangle.getLeftVertex()).y << std::endl;
        std::cout << toCartesian(scale * triangle.getRightVertex()).x << ", "
                  << toCartesian(scale * triangle.getRightVertex()).y << std::endl;
        
        triVertex[0].position = toCartesian(scale * triangle.getVerticalVertex()); 
        triVertex[0].color = sf::Color::Red;
        triVertex[1].position = toCartesian(scale * triangle.getLeftVertex()); 
        triVertex[1].color = sf::Color::Red;
        triVertex[2].position = toCartesian(scale * triangle.getRightVertex()); 
        triVertex[2].color = sf::Color::Red;
        triVertexes.push_back(triVertex);
    }
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}

//Functions
void Game::pollEvents()
{
    // Event polling
    while (auto event = this->window->pollEvent())
    {
        // Window closed
        if (event->is<sf::Event::Closed>())
        {
            this->window->close();
        }
    }
}


void Game::update()
{
	this->pollEvents();

}

void Game::render()
{
	/**
		@return void

		- clear old frame
		- render objects
		- display frame in window

		Renders the game objects.
	*/

	this->window->clear();
    for (sf::VertexArray& triVertex : triVertexes) {
        this->window->draw(triVertex);
    }
    //window->draw(*line);
    for (auto& arr : grid->triangles) {
        for (auto& vec : arr) {
            for (const auto& triangle : vec) {
                draw_triangle(triangle, window);
                
            }
        }
    } 
    //Draw game objects
	this->window->display();
}
