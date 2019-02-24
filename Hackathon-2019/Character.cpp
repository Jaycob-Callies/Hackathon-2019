#include "Header.h"

int chooseCharacter(sf::RenderWindow &window)
{
	int vMid = window.getSize().y / 2, hMid = window.getSize().x / 2, guess = 0;
	double scaleF = window.getSize().y / 32 / 8;

	sf::Texture background;
	background.loadFromFile("Dirt.png");
	sf::Sprite backgroundSprite(background);

	sf::Texture warrior;
	warrior.loadFromFile("BlueWarrior.png");
	sf::Sprite warriorSprite(warrior);

	warriorSprite.setPosition(0, vMid);

	window.draw(warriorSprite);


	sf::Texture rogue;
	warrior.loadFromFile("BlueRogue.png");
	sf::Sprite rogueSprite(rogue);

	rogueSprite.setPosition(100, vMid);

	window.draw(rogueSprite);


	return 0;

}