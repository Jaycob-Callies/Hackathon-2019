#include "Header.h"

int chooseCharacter(sf::RenderWindow &window)
{
	//loop for characters

	int vMid = window.getSize().y / 2, hMid = window.getSize().x / 2, guess = 0;
	double scaleF = window.getSize().y / 32 / 8;
	sf::Event event;

	sf::Texture background;
	background.loadFromFile("Dirt.png");
	sf::Sprite backgroundSprite(background);

	sf::Texture warrior;
	warrior.loadFromFile("BlueWarrior.png");
	sf::Sprite warriorSprite(warrior);

	sf::Texture rogue;
	warrior.loadFromFile("BlueRogue.png");
	sf::Sprite rogueSprite(rogue);

	sf::Texture mage;
	warrior.loadFromFile("BlueMage.png");
	sf::Sprite mageSprite(mage);

	sf::Texture bard;
	warrior.loadFromFile("BlueBard.png");
	sf::Sprite bardSprite(bard);

	warriorSprite.setPosition(5, vMid);
	rogueSprite.setPosition(10, vMid);	
	mageSprite.setPosition(15, vMid);	
	bardSprite.setPosition(20, vMid);

	//i dont know what to do
	
	while (true)
	{
		while (window.pollEvent(event))//poll
		{
			if (event.type == sf::Event::MouseButtonPressed)//
			{
				if (sf::Mouse::getPosition().y > vMid && sf::Mouse::getPosition().y < hMid + 1 * 32 * scaleF)
				{
					if (sf::Mouse::getPosition().x < hMid - 5 * 32 * scaleF && sf::Mouse::getPosition().x > hMid - 5 * 32 * scaleF)
					{
						//isthen character 1
					}
					else if (sf::Mouse::getPosition().x < hMid - 0 * 32 * scaleF && sf::Mouse::getPosition().x > hMid - 1 * 32 * scaleF)
					{
						
					}
					else if (sf::Mouse::getPosition().x < hMid + 1 * 32 * scaleF && sf::Mouse::getPosition().x > hMid - 0 * 32 * scaleF)
					{
						
					}
					else if (sf::Mouse::getPosition().x < hMid + 2 * 32 * scaleF && sf::Mouse::getPosition().x > hMid + 1 * 32 * scaleF)
					{
					
					}
					else {
						
					}
				}
			}
		}
	window.draw(backgroundSprite);
	window.draw(warriorSprite);	
	window.draw(rogueSprite);	
	window.draw(mageSprite);	
	window.draw(bardSprite);
	//just kill evrything

	//return characters
	return 0;

}