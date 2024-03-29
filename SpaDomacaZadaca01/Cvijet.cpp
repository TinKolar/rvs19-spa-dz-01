#include "Cvijet.h"
#include<iostream>

Cvijet::Cvijet(sf::RenderWindow* window):wind(window)
{
	
}

void Cvijet::draw()
{
	//ispis vremena
	sf::Time time = clock.getElapsedTime();
	std::cout << time.asMilliseconds() << std::endl;

	//double speed = 300.f;
	//double distance = speed * time.asMilliseconds();

	double size_mod = 1.5;


	sf::CircleShape dot(10);
	dot.setPosition(get_x_center()+5, get_y_center()+200);
	dot.setFillColor(sf::Color(255, 0, 0));

	sf::CircleShape core(35.f* size_mod);
	core.setFillColor(sf::Color::Yellow);
	core.setPosition(get_x_center() - 35.f* size_mod, get_y_center()+10);

	//Stabiljka
	sf::RectangleShape stabiljka(sf::Vector2f(300* size_mod, 8* size_mod));
	stabiljka.setFillColor(sf::Color::Green);
	stabiljka.rotate(90);
	stabiljka.setPosition(get_x_center()+5, get_y_center()+60);
	wind->draw(stabiljka);


	// Draw petals around the center circle
	for (int i = 0; i < 12; ++i) {

		sf::RectangleShape petal(sf::Vector2f(70.f* size_mod, 19.f* size_mod));
		petal.setFillColor(sf::Color::Red);
		petal.setPosition(get_y_center() +100, get_y_center()+60);

		//animation for petal
		float speed = 15.f;
		float distance = speed * time.asSeconds();
		float ostatak = std::fmod(distance, 30);
		petal.rotate(i * 30+ ostatak);

		wind->draw(petal);
	}
	wind->draw(core);

	//oci cvijeta
	sf::VertexArray eye(sf::Lines, 2);
	eye[0].color = sf::Color::Black;
	eye[1].color = sf::Color::Black;
	float x_ofset = -20;
	float y_ofset = 40;

	for (int i = 0; i < 10; i++) {

		eye[0].position = sf::Vector2f(get_x_center()+ x_ofset  + sqrt(i) * 4, get_y_center() + y_ofset + i);
		eye[1].position = sf::Vector2f(get_x_center()+ x_ofset - sqrt(i) * 4, get_y_center() + y_ofset + i);
		wind->draw(eye);

		eye[0].position = sf::Vector2f(get_x_center()+ x_ofset + sqrt(i) * 4, get_y_center() + y_ofset + 16-i);
		eye[1].position = sf::Vector2f(get_x_center()+ x_ofset - sqrt(i) * 4, get_y_center() + y_ofset + 16-i);
		wind->draw(eye);
	}

	 x_ofset = 20;
	 y_ofset = 40;

	for (int i = 0; i < 10; i++) {


		eye[0].position = sf::Vector2f(get_x_center() + x_ofset + sqrt(i) * 4, get_y_center() + y_ofset + i);
		eye[1].position = sf::Vector2f(get_x_center() + x_ofset - sqrt(i) * 4, get_y_center() + y_ofset + i);
		wind->draw(eye);

		eye[0].position = sf::Vector2f(get_x_center() + x_ofset + sqrt(i) * 4, get_y_center() + y_ofset + 16 - i);
		eye[1].position = sf::Vector2f(get_x_center() + x_ofset - sqrt(i) * 4, get_y_center() + y_ofset + 16 - i);
		wind->draw(eye);
	}


	//usne cvijeta

	sf::VertexArray lips(sf::Lines, 2);
	lips[0].color = sf::Color::Black;
	lips[1].color = sf::Color::Black;

	for (int i = 0; i < 50; i++) {

		lips[0].position = sf::Vector2f(get_x_center()-20+i, get_y_center() + 75);
		lips[1].position = sf::Vector2f(get_x_center()-20+i, get_y_center() + 81);
		wind->draw(lips);

	}

	//draw list
	sf::VertexArray List(sf::Lines, 2);
	int smoother = 80;
	int size_list = 90;
	sf::Color dark_green(0, 80, 0);;

	for (int i = 0; i < size_list; i++) {
		List[0].color = dark_green;
		List[1].color = sf::Color::Green;
		if (i < smoother) {
			List[0].position = sf::Vector2f(get_x_center() + 3 + i, get_y_center() + 200 + sqrt(i) * 3.5);
			List[1].position = sf::Vector2f(get_x_center() + 3 + i, get_y_center() + 200 - sqrt(i) * 3.5);
			wind->draw(List);

			List[0].position = sf::Vector2f(get_x_center() + (size_list * 2 + 2) - i, get_y_center() + 200 + sqrt(i) * 3.5);
			List[1].position = sf::Vector2f(get_x_center() + (size_list * 2 + 2) - i, get_y_center() + 200 - sqrt(i) * 3.5);
			wind->draw(List);
		}
		else {
			List[0].position = sf::Vector2f(get_x_center() + 3 + i, get_y_center() + 200 + sqrt(smoother) * 3.5);
			List[1].position = sf::Vector2f(get_x_center() + 3 + i, get_y_center() + 200 - sqrt(smoother) * 3.5);
			wind->draw(List);

			List[0].position = sf::Vector2f(get_x_center() + (size_list * 2 + 2) - i, get_y_center() + 200 + sqrt(smoother) * 3.5);
			List[1].position = sf::Vector2f(get_x_center() + (size_list * 2 + 2) - i, get_y_center() + 200 - sqrt(smoother) * 3.5);
			wind->draw(List);
		}
	}
	if (time.asSeconds() < 3) {
		double speed = 30.f;
		double distance = speed * time.asSeconds();
		dot.move(distance, 0);
	}
	//sf::Time elapsed01 = clock.getElapsedTime();
	//std::cout << elapsed01.asMilliseconds() << std::endl;

	wind->draw(dot);
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
