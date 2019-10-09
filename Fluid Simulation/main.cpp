#include <SFML\Graphics.hpp>
#include "Fluid.h"
#include <iostream>

using namespace std;
using namespace sf;

int main() {
	const int width = 400;
	const int height = 400;
	const int N = 2;
	const float dt = 0.000003;

	RenderWindow window(sf::VideoMode(width, height), "Fluid Simulation");
	Fluid fluid(N, 0, 0, dt);

	Vector2f mousePos, mousePrevPos, mouseSpeed;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		mousePrevPos = mousePos;
		mousePos = Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
		mouseSpeed = (mousePos - mousePrevPos) / (float)dt;

		bool LMB = Mouse::isButtonPressed(Mouse::Left);

		fluid.step();

		if (LMB) {
			fluid.addDensity(mousePos.x, mousePos.y, 100);
			float amtX = mousePos.x - mousePrevPos.x;
			float amtY = mousePos.y - mousePrevPos.y;
			fluid.addVelocity(mousePos.x, mousePos.y, amtX, amtY);
			fluid.render(mousePos, window);
		}
		//window.clear(Color::Black);
		//window.clear(Color::Red);

		window.display();
	}

	
}