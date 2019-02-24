#include "Header.h"


void characterSelect(sf::RenderWindow &window)
{
	int vMid = 0, hMid = 0; //Variable Declaration.
	double scaleF = window.getSize().y / 32.0 / 8;
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
		while (window.pollEvent(event))//poll
		{
			if (event.type == sf::Event::MouseButtonPressed)//if mouse pressed send arrow trajectory up
			{
				if (sf::Mouse::getPosition().y > hMid + 1 * 32 * scaleF)//vertical correct
				{
					if (sf::Mouse::getPosition().x < hMid - window.getSize().x / 6)
					{
						//run main game.
					}
					else if (sf::Mouse::getPosition().x < hMid + window.getSize().x / 6)
					{
						beachBall(window); //runs mini games.
					}
					else
					{
						exit(EXIT_SUCCESS); //closes game.
					}
				}
			}
		}
	}
}