#include "Header.h"

int main()
{
	//initialize values
	int hMid = 0, vMid = 0, flag = 0;
	sf::Event event;
	sf::Vector2f quadrant;

	//initialize randomization
	srand(time(NULL));

	//create fullscreen window size of users screen
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	window.create(sf::VideoMode(sf::VideoMode::getFullscreenModes().at(0)), "SFML Window", sf::Style::Fullscreen);
	window.setFramerateLimit(65);
	
	//set midpoints based on fullscreen resolution
	hMid = window.getSize().x / 2;
	vMid = window.getSize().y / 2;
	quadrant.x = hMid;
	quadrant.y = vMid;

	//initialize quadrants for selection screen
	sf::RectangleShape topLeft(quadrant);
	sf::RectangleShape topRight(quadrant);
	sf::RectangleShape bottomLeft(quadrant);
	sf::RectangleShape bottomRight(quadrant);
	topRight.move((float)hMid, 0.0);
	bottomRight.move((float)hMid, (float)vMid);
	bottomLeft.move(0.0, (float)vMid);
	topLeft.setFillColor(sf::Color::Green);
	topRight.setFillColor(sf::Color::Red);
	bottomLeft.setFillColor(sf::Color::Blue);
	bottomRight.setFillColor(sf::Color::Yellow);


	//place middle selector
	sf::CircleShape shape(100.f);
	shape.move((float)hMid - 100, (float)vMid - 100);
	shape.setFillColor(sf::Color::Green);

	//load images
	sf::Image arrow;
	arrow.loadFromFile("Arrow.png");

	Image wizardMonster;
	wizardMonster.loadFromFile("WizardMonster.png");

	Image SwampMonster;
	SwampMonster.loadFromFile("SwampMonser.png");

	Image Skeleton;
	Skeleton.loadFromFile("Skeleton.png");

	Image RedBard;
	RedBard.loadFromFile("RedBard.png");

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::getPosition().x < hMid && sf::Mouse::getPosition().y < vMid)//top left
				{
					shape.setFillColor(sf::Color::Green);
				}
				else if (sf::Mouse::getPosition().x >= hMid && sf::Mouse::getPosition().y < vMid)//top right
				{
					shape.setFillColor(sf::Color::Red);
					miniGameDodgeAttack(window);
				}
				else if (sf::Mouse::getPosition().x < hMid && sf::Mouse::getPosition().y >= vMid)//bottom left
				{
					shape.setFillColor(sf::Color::Blue);
				}
				else //bottom right
				{
					shape.setFillColor(sf::Color::Yellow);
					//miniGameRangedAttack(arrow , window, 1.0);
				}
			}
			if (event.type == sf::Event::Closed)
			window.close();
		}
		window.clear();

		window.draw(topLeft);
		window.draw(topRight);
		window.draw(bottomLeft);
		window.draw(bottomRight);

		window.draw(shape);
		window.display();
	}

	return 0;
}