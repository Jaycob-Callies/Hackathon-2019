#include "Header.h"

//Shows user 3 options on menu, play game which allows user to play main DnD game, "options" which allows user to play mini games, and exit.

void mainMenu(sf::RenderWindow &window)
{
	int hMid = window.getSize().x / 2, vMid = window.getSize().y / 2; //Variable Declaration.
	double scaleF = window.getSize().y / 32.0 / 30;
	sf::Event event;

	sf::Texture backgroundTexture1;
	backgroundTexture1.loadFromFile("TitleScreen.png");
	backgroundTexture1.setRepeated(true);
	sf::Sprite backgroundSprite1(backgroundTexture1, sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
	backgroundSprite1.setScale(scaleF, scaleF);

	while (window.isOpen())
	{
		while (window.pollEvent(event))//poll
		{
			if (event.type == sf::Event::MouseButtonPressed)//if mouse pressed then...
			{
				if (sf::Mouse::getPosition().y > hMid + 1 * 32 * scaleF)//
				{
					if (sf::Mouse::getPosition().x < hMid - window.getSize().x / 6)
					{
						game(characterSelect(window));
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
		window.clear();
		window.draw(backgroundSprite1);
		window.display();
	}
}

void beachBall(sf::RenderWindow &window) {
	//initialize values
	int hMid = 0, vMid = 0, flag = 0;
	double evasionDifficulty = 0.0;
	string characterImage = "";
	sf::Event event;
	sf::Vector2f quadrant;

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

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::getPosition().x < hMid && sf::Mouse::getPosition().y < vMid)//top left
				{
					shape.setFillColor(sf::Color::Green);
					miniGameKeyPuzzle(window);
				}
				else if (sf::Mouse::getPosition().x >= hMid && sf::Mouse::getPosition().y < vMid)//top right
				{
					shape.setFillColor(sf::Color::Red);
					miniGameDodgeAttack(window);
				}
				else if (sf::Mouse::getPosition().x < hMid && sf::Mouse::getPosition().y >= vMid)//bottom left
				{
					shape.setFillColor(sf::Color::Blue);
					switch (rand() % 5)
					{
					case 1:
						miniGameEvasion("BlueRogue.png", window, evasionDifficulty);
						break;
					case 2:
						miniGameEvasion("BlueRogue.png", window, evasionDifficulty);
						break;
					case 3:
						miniGameEvasion("BlueRogue.png", window, evasionDifficulty);
						break;
					case 4:
						miniGameEvasion("BlueRogue.png", window, evasionDifficulty);
						break;
					default:
						miniGameEvasion("BlueRogue.png", window, evasionDifficulty);
						break;
					}
				}
				else //bottom right
				{
					shape.setFillColor(sf::Color::Yellow);
					switch (rand() % 4)
					{
					case 1:
						miniGameRangedAttack("FireBolt.png", window, 1.0);
						break;
					case 2:
						miniGameRangedAttack("LightningBolt.png", window, 1.0);
						break;
					case 3:
						miniGameRangedAttack("IceBolt.png", window, 1.0);
						break;
					default:
						miniGameRangedAttack("Arrow.png", window, 1.0);
						break;
					}
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
}