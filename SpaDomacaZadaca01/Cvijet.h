#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cvijet
{
private:
	RenderWindow* wind;
	sf::Vector2u windowSize;

public:
	Cvijet(RenderWindow* window);
	void draw();
	float get_x_center();
	float get_y_center();
};

