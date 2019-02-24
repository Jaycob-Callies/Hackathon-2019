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
	int doorsDodged = 4, hMid = window.getSize().x / 2, vMid = window.getSize().y / 2, walls = 4, distance = 0;
	int clicked = 0;
	double speed = difficulty * .1, scaleF = window.getSize().y / 32.0 / 8;
	sf::Event event;
	std::vector<int> obsticleLocations;
	std::vector<double> obsticleHeights;
	std::vector<sf::Sprite> obsticles;
	
	//4 random distances and heights
	for (int i = 0; i < 4; i++)
	{
		obsticleLocations.push_back(6+ (rand() % 8));
		obsticleHeights.push_back(rand() % window.getSize().y);
	}
	
	//sum total distances
	distance = obsticleLocations.at(0) + obsticleLocations.at(1) + obsticleLocations.at(2) + obsticleLocations.at(3) + 2*(window.getSize().x - window.getSize().y)/32/scaleF;

	//load Textures
	sf::Texture projectileTexture;
	projectileTexture.loadFromFile("Arrow.png");
	sf::Sprite projectileSprite;
	projectileSprite.setTexture(projectileTexture);
	projectileSprite.setScale(scaleF, scaleF);

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("StoneTile.png");
	backgroundTexture.setRepeated(true);
	sf::Sprite backgroundSprite(backgroundTexture, sf::IntRect(0,0,distance*32,8*32));
	backgroundSprite.setScale(scaleF, scaleF);

	sf::Texture wallTexture;
	wallTexture.loadFromFile("StoneWallCorners.png", sf::IntRect(64, 32, 32, 32));
	wallTexture.setRepeated(true);
	sf::Sprite wallSprite(wallTexture, sf::IntRect(0, 0, 32, 8 * 32));
	wallSprite.setScale(scaleF, scaleF);
	wallSprite.setPosition(-hMid, -vMid);

	for (int i = 0; i < 4; i++)
	{
		obsticles.push_back(sf::Sprite(wallSprite));
		obsticles.at(2*i).setPosition(obsticleLocations.at(i)*32 * scaleF, obsticleHeights.at(i) + 48*scaleF);
		obsticles.push_back(sf::Sprite(wallSprite));
		obsticles.at(2*i+1).setPosition(obsticleLocations.at(i) * 32 * scaleF, obsticleHeights.at(i) - window.getSize().y);
		if (i > 0)
		{
			obsticles.at(2*i).move(obsticles.at(2*i - 2).getPosition().x, 0);
			obsticles.at(2*i+1).move(obsticles.at(2*i - 1).getPosition().x, 0);
		}
	}

	while (walls != 0)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				clicked = 60;
		}
		if (clicked > 0)
		{
			projectileSprite.move(0, 2 -0.15 * pow((.13333333 * clicked - 4), 3));
		}
		else
		{
			projectileSprite.move(0, 10);
		}
		window.clear();
		backgroundSprite.move(-1 * scaleF, 0);
		window.draw(backgroundSprite);
		window.draw(projectileSprite);
		for (int i = 0; i < obsticles.size(); i++)
		{
			obsticles.at(i).move(-1.0 * scaleF, 0.0);
			window.draw(obsticles.at(i));
		}
		window.display();
		clicked--;
	}
	return doorsDodged;
}