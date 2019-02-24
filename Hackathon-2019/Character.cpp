#include "Header.h"


std::vector<Character> characterSelect(sf::RenderWindow &window)
{
	std::vector<Character> temp;
	int vMid = 0, hMid = 0; //Variable Declaration.
	double scaleF = window.getSize().y / 32.0 / 8;
	std::string newCharacterFile;
	sf::Event event;
	sf::Mouse mouse;

	sf::Texture characterTexture1;
	characterTexture1.loadFromFile("BlueBard.png");
	sf::Sprite characterSprite1;
	characterSprite1.setTexture(characterTexture1);
	characterSprite1.setScale(scaleF, scaleF);

	sf::Texture characterTexture2;
	characterTexture2.loadFromFile("BlueMage.png");
	sf::Sprite characterSprite2;
	characterSprite2.setTexture(characterTexture2);
	characterSprite2.setScale(scaleF, scaleF);

	sf::Texture characterTexture3;
	characterTexture3.loadFromFile("BlueRogue.png");
	sf::Sprite characterSprite3;
	characterSprite3.setTexture(characterTexture3);
	characterSprite3.setScale(scaleF, scaleF);

	sf::Texture characterTexture4;
	characterTexture4.loadFromFile("BlueWarrior.png");
	sf::Sprite characterSprite4;
	characterSprite4.setTexture(characterTexture4);
	characterSprite4.setScale(scaleF, scaleF);

	sf::Texture characterTexture5;
	characterTexture5.loadFromFile("GreenBard.png");
	sf::Sprite characterSprite5;
	characterSprite5.setTexture(characterTexture5);
	characterSprite5.setScale(scaleF, scaleF);

	sf::Texture characterTexture6;
	characterTexture6.loadFromFile("GreenMage.png");
	sf::Sprite characterSprite6;
	characterSprite6.setTexture(characterTexture6);
	characterSprite6.setScale(scaleF, scaleF);

	sf::Texture characterTexture7;
	characterTexture7.loadFromFile("GreenRogue.png");
	sf::Sprite characterSprite7;
	characterSprite7.setTexture(characterTexture7);
	characterSprite7.setScale(scaleF, scaleF);

	sf::Texture characterTexture8;
	characterTexture8.loadFromFile("GreenWarrior.png");
	sf::Sprite characterSprite8;
	characterSprite8.setTexture(characterTexture8);
	characterSprite8.setScale(scaleF, scaleF);

	sf::Texture characterTexture9;
	characterTexture9.loadFromFile("RedBard.png");
	sf::Sprite characterSprite9;
	characterSprite9.setTexture(characterTexture9);
	characterSprite9.setScale(scaleF, scaleF);

	sf::Texture characterTexture10;
	characterTexture10.loadFromFile("RedMage.png");
	sf::Sprite characterSprite10;
	characterSprite10.setTexture(characterTexture10);
	characterSprite10.setScale(scaleF, scaleF);

	sf::Texture characterTexture11;
	characterTexture11.loadFromFile("RedRogue.png");
	sf::Sprite characterSprite11;
	characterSprite11.setTexture(characterTexture11);
	characterSprite11.setScale(scaleF, scaleF);

	sf::Texture characterTexture12;
	characterTexture12.loadFromFile("RedWarrior.png");
	sf::Sprite characterSprite12;
	characterSprite12.setTexture(characterTexture12);
	characterSprite12.setScale(scaleF, scaleF);

	sf::Texture characterTexture13;
	characterTexture13.loadFromFile("YellowBard.png");
	sf::Sprite characterSprite13;
	characterSprite13.setTexture(characterTexture13);
	characterSprite13.setScale(scaleF, scaleF);

	sf::Texture characterTexture14;
	characterTexture14.loadFromFile("YellowMage.png");
	sf::Sprite characterSprite14;
	characterSprite14.setTexture(characterTexture14);
	characterSprite14.setScale(scaleF, scaleF);

	sf::Texture characterTexture15;
	characterTexture15.loadFromFile("YellowRogue.png");
	sf::Sprite characterSprite15;
	characterSprite15.setTexture(characterTexture15);
	characterSprite15.setScale(scaleF, scaleF);

	sf::Texture characterTexture16;
	characterTexture16.loadFromFile("YellowWarrior.png");
	sf::Sprite characterSprite16;
	characterSprite16.setTexture(characterTexture16);
	characterSprite16.setScale(scaleF, scaleF);

	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if((sf::Mouse::getPosition().x< window.getSize().x / 4.0 * (j+1) && sf::Mouse::getPosition().x > window.getSize().x / 4.0 * (j))
							&& (sf::Mouse::getPosition().y< window.getSize().y / 4.0 * (i + 1) && sf::Mouse::getPosition().y > window.getSize().y / 4.0 * (i)))
						{
							switch (i)
							{
							case 1:
								newCharacterFile = "Red";
								break;
							case 2:
								newCharacterFile = "Blue";
								break;
							case 3:
								newCharacterFile = "Green";
								break;
							default:
								newCharacterFile = "Yellow";
								break;
							}
							
							switch (j)
							{
							case 1:
								newCharacterFile = newCharacterFile + "Rogue.png";
								break;
							case 2:
								newCharacterFile = newCharacterFile + "Mage.png";
								break;
							case 3:
								newCharacterFile = newCharacterFile + "Bard.png";
								break;
							default:
								newCharacterFile = newCharacterFile + "Warrior.png";
								break;
							}
							temp.push_back(*new(Character));
							temp.at(temp.size() - 1).setFile(newCharacterFile);
						}
					}
				}
			}
		}
	}
}