#include "Header.h"

//Shows user 3 options on menu, play game which allows user to play main DnD game, "options" which allows user to play mini games, and exit.

void mainMenu(sf::RenderWindow &window)
{
	int hMid = window.getSize().x / 2, vMid = window.getSize().y / 2; //Variable Declaration.
	float textureBitsX = 1400.0, textureBitsY = 1050.0, scaleF = 0.0, yOffset = 0.0, xOffset = 0.0;//1400x1050
	sf::Event event;

	//set scaleF to scale needed in order to make a minTexturesPerScreenLength long square of tiles in the center of the screen
	if (window.getSize().x /textureBitsX> window.getSize().y/textureBitsY)//landscape view(horizontal longer than vertical)
	{
		scaleF = window.getSize().y / textureBitsY;
		xOffset = ((window.getSize().x - (textureBitsX * scaleF))/2.0);
	}
	else//portrait view(horizontal narrower than vertical)
	{
		scaleF = window.getSize().x / textureBitsX;
		yOffset = ((window.getSize().y - (textureBitsY * scaleF)) / 2.0);
	}

	//scale and translate Menu Screen
	sf::Texture backgroundTexture1;
	backgroundTexture1.loadFromFile("TitleScreen.png");
	sf::Sprite backgroundSprite1(backgroundTexture1);
	backgroundSprite1.setScale(scaleF, scaleF);
	backgroundSprite1.setPosition(xOffset, yOffset);

	//create overlay sprites for user feedback
	sf::Sprite startSprite(backgroundTexture1, sf::IntRect(82, 845, 352, 70));
	sf::Sprite optionsSprite(backgroundTexture1, sf::IntRect(472, 842, 519, 70));
	sf::Sprite quitSprite(backgroundTexture1, sf::IntRect(1059, 842, 281, 72));
	//scalea overlay sprites
	startSprite.setScale(scaleF, scaleF);
	optionsSprite.setScale(scaleF, scaleF);
	quitSprite.setScale(scaleF, scaleF);
	//darken and transparency
	startSprite.setColor(sf::Color(0, 0, 0, 100));
	optionsSprite.setColor(sf::Color(0, 0, 0, 100));
	quitSprite.setColor(sf::Color(0, 0, 0, 100));
	//move to overlay the selections
	startSprite.setPosition(backgroundSprite1.getPosition().x + 82.0 * scaleF, backgroundSprite1.getPosition().y + 845.0 * scaleF);
	optionsSprite.setPosition(backgroundSprite1.getPosition().x + 472.0 * scaleF, backgroundSprite1.getPosition().y + 842.0 * scaleF);
	quitSprite.setPosition(backgroundSprite1.getPosition().x + 1059.0 * scaleF, backgroundSprite1.getPosition().y + 842.0 * scaleF);


	
	while (window.isOpen())
	{
		while (window.pollEvent(event))//poll
		{
			if (event.type == sf::Event::MouseButtonPressed)//if mouse pressed then...
			{
				//preform action if one is highlighted
				if (startSprite.getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
				{
					game(characterSelect(window), window);
					//run main game.
				}
				if (optionsSprite.getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
				{
					beachBall(window); //runs mini games.
				}
				if (quitSprite.getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
				{
					return;//closes game.
				}
			}
		}
		//reset frame
		window.clear();
		//draw background
		window.draw(backgroundSprite1);
		//if cursor is over any selections draw their highlight
		if (startSprite.getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
		{
			window.draw(startSprite);
		}
		if (optionsSprite.getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
		{
			window.draw(optionsSprite);
		}		
		if (quitSprite.getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
		{
			window.draw(quitSprite);
		}
		//display frame
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
	quadrant.x = (float)hMid;
	quadrant.y = (float)vMid;

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