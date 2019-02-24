#include "Header.h"

int difficulty = 0;
int windowWidth = 400;
int windowHeight = 300;

//int MiniGameEvasion(sf::Image character, int difficulty, sf::RenderWindow &window)
//{
//	//speed = scrolling speed, IsKeyDown(sf::key::____)- Can use to program jumping. (should be the only necessary action).
//	double speed = 0.0;
//	int velocity = 0, gravity = 0, jumping = 0, amountOfCorrectResponses = 0;
//	sf::Event event;
//
//	while (window.pollEvent(event))
//	{
//		if (event.type == sf::Event::KeyPressed)
//		{
//			if (sf::Keyboard::Space)
//			{
//				velocity = 0;
//				gravity = 0;
//				jumping == true;
//			}
//		}
//		//sf::CircleShape Triangle(100);
//		//sf::Triangle.setPointCount(3);
//		//
//		//if (character intersects(const; Rect<T> &triangle))
//		//{
//		//	characterLife -= 1;
//		//}
//	}
//
//	return amountOfCorrectResponses;
//}
//int miniGameRangedAttack(sf::Image projectileImage, sf::RenderWindow &window, double difficulty)
//{
//	int doorsDodged = 4, hMid = window.getSize().x / 2, vMid = window.getSize().y / 2, walls = 4, distance = 0;
//	int clicked = 0;
//	double speed = difficulty * .1, scaleF = window.getSize().y / 32.0 / 8;
//	sf::Event event;
//	std::vector<int> obsticleLocations;
//	std::vector<double> obsticleHeights;
//	std::vector<sf::Sprite> obsticles;
//	
//	//4 random distances and heights
//	for (int i = 0; i < 4; i++)
//	{
//		obsticleLocations.push_back(6+ (rand() % 8));
//		obsticleHeights.push_back(rand() % window.getSize().y);
//	}
//	
//	//sum total distances
//	distance = obsticleLocations.at(0) + obsticleLocations.at(1) + obsticleLocations.at(2) + obsticleLocations.at(3) + 2*(window.getSize().x - window.getSize().y)/32/scaleF;
//
//	//load Textures
//	sf::Texture projectileTexture;
//	projectileTexture.loadFromFile("Arrow.png");
//	sf::Sprite projectileSprite;
//	projectileSprite.setTexture(projectileTexture);
//	projectileSprite.setScale(scaleF, scaleF);
//
//	sf::Texture backgroundTexture;
//	backgroundTexture.loadFromFile("StoneTile.png");
//	backgroundTexture.setRepeated(true);
//	sf::Sprite backgroundSprite(backgroundTexture, sf::IntRect(0,0,distance*32,8*32));
//	backgroundSprite.setScale(scaleF, scaleF);
//
//	sf::Texture wallTexture;
//	wallTexture.loadFromFile("StoneWallCorners.png", sf::IntRect(64, 32, 32, 32));
//	wallTexture.setRepeated(true);
//	sf::Sprite wallSprite(wallTexture, sf::IntRect(0, 0, 32, 8 * 32));
//	wallSprite.setScale(scaleF, scaleF);
//	wallSprite.setPosition(-hMid, -vMid);
//
//	for (int i = 0; i < 4; i++)
//	{
//		obsticles.push_back(sf::Sprite(wallSprite));
//		obsticles.at(2*i).setPosition(obsticleLocations.at(i)*32 * scaleF, obsticleHeights.at(i) + 48*scaleF);
//		obsticles.push_back(sf::Sprite(wallSprite));
//		obsticles.at(2*i+1).setPosition(obsticleLocations.at(i) * 32 * scaleF, obsticleHeights.at(i) - window.getSize().y);
//		if (i > 0)
//		{
//			obsticles.at(2*i).move(obsticles.at(2*i - 2).getPosition().x, 0);
//			obsticles.at(2*i+1).move(obsticles.at(2*i - 1).getPosition().x, 0);
//		}
//	}
//
//	while (walls != 0)
//	{
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::MouseButtonPressed)
//				clicked = 60;
//		}
//		if (clicked > 0)
//		{
//			projectileSprite.move(0, 2 -0.15 * pow((.13333333 * clicked - 4), 3));
//		}
//		else
//		{
//			projectileSprite.move(0, 10);
//		}
//		window.clear();
//		backgroundSprite.move(-1 * scaleF, 0);
//		window.draw(backgroundSprite);
//		window.draw(projectileSprite);
//		for (int i = 0; i < obsticles.size(); i++)
//		{
//			obsticles.at(i).move(-1.0 * scaleF, 0.0);
//			window.draw(obsticles.at(i));
//		}
//		window.display();
//		clicked--;
//	}
//	return doorsDodged;
//}

int miniGameDodgeAttack(RenderWindow &window) {
		
	srand(time(NULL));
	int randYValue = 0;
	double randValue = 0.0;
	int limit = 0; //limit is how many times you can hit the sheild or how many times one monster goes past a boundary

	int hMid = window.getSize().x / 2, vMid = window.getSize().y / 2;

	int score = 0;
	int direction = 0, direction2 = 0, direction3 = 0;

	double scaleF = window.getSize().y / 32.0 / 8;

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("StoneTile.png");
	backgroundTexture.setRepeated(true);
	sf::Sprite backgroundSprite(backgroundTexture, sf::IntRect(0, 0, 16* 32, 8 * 32));
	backgroundSprite.setScale(scaleF, scaleF);

	std::vector<double> characterx;
	std::vector<double> charactery;
	

	for (int i = 0; i < 4; i++)
	{
		characterx.push_back(rand() % (window.getSize().x));
		charactery.push_back(rand() % (window.getSize().y));
	}

	sf::Texture attacker1;
	attacker1.loadFromFile("WizardMonster.png");
	sf::Sprite attackerSprite;
	attackerSprite.setTexture(attacker1);
	attackerSprite.setScale(scaleF*5, scaleF*5);
	attackerSprite.setPosition(Vector2f(characterx.at(0), charactery.at(0)));
		
	sf::Texture attacker2;
	attacker2.loadFromFile("Skeleton.png");
	sf::Sprite attackerSprite2;
	attackerSprite2.setTexture(attacker2);
	attackerSprite2.setScale(scaleF * 5, scaleF * 5);
	attackerSprite2.setPosition(Vector2f(characterx.at(1), charactery.at(1)));

	sf::Texture attacker3;
	attacker3.loadFromFile("SwampMonster.png");
	sf::Sprite attackerSprite3;
	attackerSprite3.setTexture(attacker3);
	attackerSprite3.setScale(scaleF * 2, scaleF * 2);
	attackerSprite3.setPosition(Vector2f(0, 10.f));
	attackerSprite3.setPosition(Vector2f(characterx.at(2), charactery.at(2)));

	sf::Texture treasure;
	treasure.loadFromFile("HealthPotion.png");
	sf::Sprite treasureSprite;
	treasureSprite.setTexture(treasure);
	treasureSprite.setScale(scaleF * 4, scaleF * 4);
	treasureSprite.setPosition(Vector2f(characterx.at(3), charactery.at(3)));
	
	CircleShape attacker;
	bool isHit = false;
	attacker.setRadius(10.f);
	attacker.setFillColor(Color::Black);
	attacker.setPosition(Vector2f(0, window.getSize().y - attacker.getRadius() * 3));


	while (limit < 9) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
					window.close();
		}

			//hitPlace update
		if (attackerSprite.getPosition().x <= 0 ) {
			direction = 1;
			limit++;
		}
		else if (attackerSprite.getPosition().x >= window.getSize().x) {
				direction = 0;
		}
		if (direction == 0) {
			attackerSprite.move(-5.f, 0);
		}
		else {
			attackerSprite.move(5.f, 0);
		}


		if (treasureSprite.getPosition().x <= 0 || treasureSprite.getPosition().y <= 0) {
			direction = 1;
		}
		else if (treasureSprite.getPosition().x >= window.getSize().x || treasureSprite.getPosition().y >= window.getSize().y) {
			direction = 0;			}
		if (direction == 0) {
			treasureSprite.move(-10.f, 4.f);
		}
		else {
			treasureSprite.move(15.f, 3.f);
		}
		if (attackerSprite2.getPosition().y <= 0) {
			direction2 = 1;
		}
		else if (attackerSprite2.getPosition().y >= window.getSize().y) {
			direction2 = 0;
		}
		if (direction2 == 0) {
			attackerSprite2.move(-10.f, -10.f);
		}
		else {
			attackerSprite2.move(10.f, 10.f);
		}
		if (attackerSprite3.getPosition().y <= 0 || attackerSprite3.getPosition().x <= 0) {
			direction3 = 1;
		}
		else if ((attackerSprite3.getPosition().x >= window.getSize().x) ||
			(attackerSprite3.getPosition().y >= window.getSize().y)) {
			direction3 = 0;
			}
		if (direction3 == 0) {
			attackerSprite3.move(-5.f, -2.f);
		}
		else {
			attackerSprite3.move(10.f, 10.f);
		}


		//update attack

		if (!isHit) {
			attacker.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
		}
		else {
			attacker.move(0, -7.f);
		}

		//collison 
			
		if (attacker.getGlobalBounds().intersects(attackerSprite.getGlobalBounds())) {
			//reset 
			isHit = false;
			
			randYValue = rand() % 100 + 1;
			randValue = randYValue;
			attackerSprite.setPosition(Vector2f(attackerSprite.getPosition().x, randValue));
			score--;
		}
		if (attacker.getGlobalBounds().intersects(attackerSprite2.getGlobalBounds())) {
			//reset 
			isHit = false;
				
			randYValue = rand() % 100 + 1;
			randValue = randYValue;
			attackerSprite2.setPosition(Vector2f(attackerSprite2.getPosition().x, randValue));
			score--;
		}
		if (attacker.getGlobalBounds().intersects(attackerSprite3.getGlobalBounds())) {
				//reset 
			isHit = false;
				
			randYValue = rand() % 100 + 1;
			randValue = randYValue;
			attackerSprite3.setPosition(Vector2f(attackerSprite3.getPosition().x, randValue));
			score--;
		}
		if (treasureSprite.getGlobalBounds().intersects(attacker.getGlobalBounds())) {
				//reset 
			isHit = false;
				
			randYValue = rand() % (int)scaleF * 32 * 8 + 1;
			randValue = randYValue;
			treasureSprite.setPosition(Vector2f(randYValue, randValue));
			randValue = rand() % 6;
			treasureSprite.move(3.f, randValue);
			score = score + 2;
			limit++;
		}

		window.clear(Color::White);
		window.draw(backgroundSprite);
		window.draw(attackerSprite);
		window.draw(attackerSprite2);
		window.draw(attackerSprite3);
			
		window.draw(attackerSprite3);
		window.draw(treasureSprite);
		window.draw(attacker);
		window.display();
	}

	return 0;
	}
