#include "Header.h"

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