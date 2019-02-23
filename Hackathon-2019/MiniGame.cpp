#include "Header.h"

int difficulty = 0;
int windowWidth = 400;
int windowHeight = 300;

int MiniGameEvasion(sf::Image character, int difficulty, sf::RenderWindow &window)
{
	//speed = scrolling speed, IsKeyDown(sf::key::____)- Can use to program jumping. (should be the only necessary action).
	double speed = 0.0;
	int velocity = 0, gravity = 0, jumping = 0, amountOfCorrectResponses = 0;
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::Space)
			{
				velocity = 0;
				gravity = 0;
				jumping == true;
			}
		}
		//sf::CircleShape Triangle(100);
		//sf::Triangle.setPointCount(3);
		//
		//if (character intersects(const; Rect<T> &triangle))
		//{
		//	characterLife -= 1;
		//}
	}

	return amountOfCorrectResponses;
}
int miniGameRangedAttack(sf::Image projectileImage, sf::RenderWindow &window, double difficulty)
{
	int doorsDodged = 0, hMid = window.getSize().x / 2, vMid = window.getSize().y / 2;
	

	double speed = difficulty * .1, scaleF = window.getSize().x / 32.0 / 8;
	sf::Texture projectileTexture;
	projectileTexture.loadFromFile("BarbarianMonster - Copy.png");
	sf::Sprite projectileSprite;
	projectileSprite.setTexture(projectileTexture);
	projectileSprite.setScale(scaleF, scaleF);
	window.clear();
	window.draw(projectileSprite);

	return doorsDodged;
}