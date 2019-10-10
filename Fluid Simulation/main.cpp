#include <SFML\Graphics.hpp>
#include "Fluid.h"
#include <iostream>

using namespace std;
using namespace sf;

int main() {
	const int width = 300;
	const int height = 300;
	const int N = 30;
	const float dt = 0.1;

	RenderWindow window(sf::VideoMode(width, height), "Fluid Simulation");
	Fluid fluid(N, 0, 0.0000001, dt);

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
			fluid.addDensity(mousePos.x/10, mousePos.y/10, 100);
			float amtX = mousePos.x - mousePrevPos.x;
			float amtY = mousePos.y - mousePrevPos.y;
			fluid.addVelocity(mousePos.x/10, mousePos.y/10, amtX, amtY);
		}
		fluid.render(window);
		//window.clear(Color::Black);
		//window.clear(Color::Red);

		window.display();
	}

	
}