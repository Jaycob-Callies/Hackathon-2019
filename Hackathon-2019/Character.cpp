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

	sf::Texture bwarrior;
	bwarrior.loadFromFile("BlueWarrior.png");
	sf::Sprite bwarriorSprite(bwarrior);

	sf::Texture brogue;
	brogue.loadFromFile("BlueRogue.png");
	sf::Sprite brogueSprite(brogue);

	sf::Texture bmage;
	bmage.loadFromFile("BlueMage.png");
	sf::Sprite bmageSprite(bmage);

	sf::Texture bbard;
	bbard.loadFromFile("BlueBard.png");
	sf::Sprite bbardSprite(bbard);


	sf::Texture rwarrior;
	rwarrior.loadFromFile("RedWarrior.png");
	sf::Sprite rwarriorSprite(rwarrior);

	sf::Texture rrogue;
	rrogue.loadFromFile("RedRogue.png");
	sf::Sprite rrogueSprite(rrogue);

	sf::Texture rmage;
	rmage.loadFromFile("RedMage.png");
	sf::Sprite rmageSprite(rmage);

	sf::Texture rbard;
	rbard.loadFromFile("RedBard.png");
	sf::Sprite rbardSprite(rbard);

	sf::Texture gwarrior;
	gwarrior.loadFromFile("GreenWarrior.png");
	sf::Sprite gwarriorSprite(gwarrior);

	sf::Texture grogue;
	grogue.loadFromFile("GreenRogue.png");
	sf::Sprite grogueSprite(grogue);

	sf::Texture gmage;
	gmage.loadFromFile("GreenMage.png");
	sf::Sprite gmageSprite(gmage);

	sf::Texture gbard;
	gbard.loadFromFile("GreenBard.png");
	sf::Sprite gbardSprite(gbard);

	sf::Texture ywarrior;
	ywarrior.loadFromFile("YellowWarrior.png");
	sf::Sprite ywarriorSprite(ywarrior);

	sf::Texture yrogue;
	yrogue.loadFromFile("YellowRogue.png");
	sf::Sprite yrogueSprite(yrogue);

	sf::Texture ymage;
	ymage.loadFromFile("YellowMage.png");
	sf::Sprite ymageSprite(ymage);

	sf::Texture ybard;
	ybard.loadFromFile("YellowBard.png");
	sf::Sprite ybardSprite(ybard);

	rwarriorSprite.setPosition(5, vMid);
	rrogueSprite.setPosition(10, vMid);
	rmageSprite.setPosition(15, vMid);
	rbardSprite.setPosition(20, vMid);

	gwarriorSprite.setPosition(5, vMid);
	grogueSprite.setPosition(10, vMid);
	gmageSprite.setPosition(15, vMid);
	gbardSprite.setPosition(20, vMid);

	ywarriorSprite.setPosition(5, vMid);
	yrogueSprite.setPosition(10, vMid);
	ymageSprite.setPosition(15, vMid);
	ybardSprite.setPosition(20, vMid);

	bwarriorSprite.setPosition(5, vMid);
	brogueSprite.setPosition(10, vMid);
	bmageSprite.setPosition(15, vMid);
	bbardSprite.setPosition(20, vMid);

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
		window.draw(rwarriorSprite);
		window.draw(rrogueSprite);
		window.draw(rmageSprite);
		window.draw(rbardSprite);
		//just kill evrything

		//return characters
		return 0;

	}
}