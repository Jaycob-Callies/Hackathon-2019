#include "Header.h"

void testPlayer(sf::RenderWindow &window) {
	sf::Event event;
	Room start(sf::Vector2i(0,0));
	start.explore();
	start.getpLeft()->explore();
	start.getpRight()->explore();
	start.getpTop()->explore();
	start.getpBottom()->explore();

	Character testCharacter;
	testCharacter.setLocation(&start);
	
	testCharacter.display(window);
	window.display();

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				return;
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

	}
}