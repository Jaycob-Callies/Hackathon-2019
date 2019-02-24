#include "Header.h"


int vMid = 0, hMid = 0; //Variable Declaration.
double scaleF = window.getSize().y / 32.0 / 8;

//Shows user 3 options on menu, play game which allows user to play main DnD game, "options" which allows user to play mini games, and exit.

sf::Event event;

sf::Texture backgroundTexture;
backgroundTexture.loadFromFile("TitleScreen.png", sf::IntRect(32, 0, 32, 32));
backgroundTexture.setRepeated(true);
sf::Sprite backgroundSprite(backgroundTexture, sf::IntRect(0, 0, distance * 32, 8 * 32)); //is the sprite necessary?
backgroundSprite.setScale(scaleF, scaleF);

while (true) //Runs infinite loop. (basically while window is open).
{
	while (window.pollEvent(event))//poll
	{
		if (event.type == sf::Event::MouseButtonPressed)//if mouse pressed send arrow trajectory up
		{
			if (sf::Mouse::getPosition().y > vMid && sf::Mouse::getPosition().y < hMid + 1 * 32 * scaleF)//vertical correct
			{
				if (sf::Mouse::getPosition().x < hMid - 1 * 32 * scaleF && sf::Mouse::getPosition().x > hMid - 2 * 32 * scaleF && tines.at(guess).getTexture() == &triangle)
				{
					correct_guess++;
					tines.at(guess).setColor(sf::Color::White);
				}
				else if (sf::Mouse::getPosition().x < hMid - 0 * 32 * scaleF && sf::Mouse::getPosition().x > hMid - 1 * 32 * scaleF && tines.at(guess).getTexture() == &square)
				{
					correct_guess++;
					tines.at(guess).setColor(sf::Color::White);
				}
				else if (sf::Mouse::getPosition().x < hMid + 1 * 32 * scaleF && sf::Mouse::getPosition().x > hMid - 0 * 32 * scaleF && tines.at(guess).getTexture() == &star)
				{
					correct_guess++;
					tines.at(guess).setColor(sf::Color::White);
				}
				else if (sf::Mouse::getPosition().x < hMid + 2 * 32 * scaleF && sf::Mouse::getPosition().x > hMid + 1 * 32 * scaleF && tines.at(guess).getTexture() == &circle)
				{
					correct_guess++;
					tines.at(guess).setColor(sf::Color::White);
				}
				else {
					tines.at(guess).setColor(sf::Color::Red);
				}
				guess++;
			}
		}
	}
}