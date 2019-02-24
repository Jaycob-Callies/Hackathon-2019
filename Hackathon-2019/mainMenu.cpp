#include "Header.h"

//Shows user 3 options on menu, play game which allows user to play main DnD game, "options" which allows user to play mini games, and exit.

sf::Event event;

//while (true)
//{
//	while (window.pollEvent(event1))//poll
//	{
//		if (event1.type == sf::Event::MouseButtonPressed)//if mouse pressed 
//		{
//			
//		}
//	}
//}

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