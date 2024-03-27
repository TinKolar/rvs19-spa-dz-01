#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window):wind(window)
{
	
}

void Cvijet::draw()
{
	sf::CircleShape shape(50);
	shape.setFillColor(sf::Color(200, 130, 0));
	shape.setPosition(get_x_center()-50, get_y_center()+25);

	sf::CircleShape dot(10);
	dot.setPosition(get_x_center()-10, get_y_center()-10);
	dot.setFillColor(sf::Color(255, 0, 0));


	sf::CircleShape core(30.f);
	core.setFillColor(sf::Color::Yellow);
	core.setPosition(get_x_center() - 30.f, get_y_center()+30);

	sf::RectangleShape stabiljka(sf::Vector2f(300, 8));
	stabiljka.setFillColor(sf::Color::Green);
	stabiljka.rotate(90);
	stabiljka.setPosition(get_x_center()+5, get_y_center()+60);
	wind->draw(stabiljka);

	// Draw petals around the center circle
	for (int i = 0; i < 12; ++i) {
		sf::RectangleShape petal(sf::Vector2f(70.f, 20.f));
		petal.setFillColor(sf::Color::Red);
		petal.setPosition(get_y_center() +100, get_y_center()+60);
		petal.rotate(i * 30.f);
		wind->draw(petal);
	}
	wind->draw(core);


	/*wind->draw(shape);
	wind->draw(dot);*/
}

float Cvijet::get_x_center()
{
	windowSize = wind->getSize();
	float centerX = windowSize.x / 2.f;
	return centerX;
}

float Cvijet::get_y_center()
{
	windowSize = wind->getSize();
	float centerY = windowSize.y / 2.f;
	return centerY;
}
