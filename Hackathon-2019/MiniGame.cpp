#include "Header.h"



struct Position
{
	int x;
	int y;
};

int game(std::vector<Character> players) {
	return 0;
}

//Raise floor a touch higher. (Done)
//Alter "obsticles" to be random non-moving sprites. (Done)
//Alter jumping ability to only jump when feet touching ground or platform instead of multiple double jumps. (Done) 
//Alter hitbox to fit average character build. (Hitbox is about accurate, Done)
//Alter obstacle y-direction. (Done)
//Alter hang time in the air. (Done)
//Make program functional. (Done)

int miniGameEvasion(std::string characterImage, sf::RenderWindow &window, double evasionDifficulty)
{
	window.setFramerateLimit(60);

	int obstaclesDodged = 4, hMid = window.getSize().x / 2, vMid = window.getSize().y / 2, walls = 4, distance = 0;
	int time = 0, prevVel = 0, onFloor = 0;
	double speed = evasionDifficulty * .1, scaleF = window.getSize().y / 32.0 / 8;
	sf::Event event;
	std::vector<int> obstacleLocations;
	std::vector<sf::Sprite> obstacles;

	for (int i = 0; i < 4; i++)
	{
		obstacleLocations.push_back(6 + (rand() % 8));
	}

	distance = obstacleLocations.at(0) + obstacleLocations.at(1) + obstacleLocations.at(2) + obstacleLocations.at(3) + 2 * (window.getSize().x - window.getSize().y) / 32 / scaleF;

	sf::Texture characterTexture;
	characterTexture.loadFromFile(characterImage);
	sf::Sprite characterSprite;
	characterSprite.setTexture(characterTexture);
	characterSprite.setScale(scaleF, scaleF);

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("StoneWallCorners.png", sf::IntRect(32, 0, 32, 32));
	backgroundTexture.setRepeated(true);
	sf::Sprite backgroundSprite(backgroundTexture, sf::IntRect(0, 0, distance * 32, 8 * 32));
	backgroundSprite.setScale(scaleF, scaleF);

	sf::Texture obstacleTexture;
	obstacleTexture.loadFromFile("PitFullOfSpikes.png");
	sf::Sprite obstacleSprite;
	obstacleSprite.setTexture(obstacleTexture);
	obstacleSprite.setScale(scaleF, scaleF);

	sf::Texture obstacle1Texture;
	obstacle1Texture.loadFromFile("TripWire.png");
	sf::Sprite obstacle1Sprite;
	obstacle1Sprite.setTexture(obstacle1Texture);
	obstacle1Sprite.setScale(scaleF, scaleF);

	sf::Texture obstacle2Texture;
	obstacle2Texture.loadFromFile("LightningBolt.png");
	sf::Sprite obstacle2Sprite;
	obstacle2Sprite.setTexture(obstacle2Texture);
	obstacle2Sprite.setScale(scaleF, scaleF);

	sf::Texture obstacle3Texture;
	obstacle3Texture.loadFromFile("IceBolt.png");
	sf::Sprite obstacle3Sprite;
	obstacle3Sprite.setTexture(obstacle3Texture);
	obstacle3Sprite.setScale(scaleF, scaleF);

	sf::Texture obstacle4Texture;
	obstacle4Texture.loadFromFile("Skeleton.png");
	sf::Sprite obstacle4Sprite;
	obstacle4Sprite.setTexture(obstacle4Texture);
	obstacle4Sprite.setScale(scaleF, scaleF);

	//sf::Texture wallTexture;
	//wallTexture.loadFromFile("StoneWallCorners.png", sf::IntRect(64, 32, 32, 32));
	//wallTexture.setRepeated(true);
	//sf::Sprite wallSprite(wallTexture, sf::IntRect(0, 0, 32, 8 * 32));
	//wallSprite.setScale(scaleF, scaleF);
	//wallSprite.setPosition(-hMid, -vMid);
	
	sf::RectangleShape hitBox(sf::Vector2f(25 * scaleF, 2 * scaleF));

	//set locations of obsticles based on reandom values
	for (int i = 0; i < 4; i++)
	{
		switch (rand() % 5)
		{
		case 1:
			obstacles.push_back(sf::Sprite(obstacleSprite));//Sprite of first random
			break;
		case 2:
			obstacles.push_back(sf::Sprite(obstacle1Sprite));//Sprite of first random
			break;
		case 3:
			obstacles.push_back(sf::Sprite(obstacle2Sprite));//Sprite of first random
			break;
		case 4:
			obstacles.push_back(sf::Sprite(obstacle3Sprite));//Sprite of first random
			break;
		default:
			obstacles.push_back(sf::Sprite(obstacle4Sprite));//Sprite of first random
			break;
		}

		//Adjust obstacle height.

		obstacles.at(i).setPosition(obstacleLocations.at(i) * 32.0 * scaleF,window.getSize().y-scaleF * 25); 

		if (i > 0)//offset the concurrent onsticles so they dont stack
		{
			obstacles.at(i).move(obstacles.at(i - 1).getPosition().x, 0);
		}
	}
	characterSprite.setPosition(0, window.getSize().y);
	//main functionality
	while (true)//infinite loop
	{
		//event handling
		while (window.pollEvent(event))//poll
		{
			if (event.type == sf::Event::MouseButtonPressed)//if mouse pressed send arrow trajectory up
			{
				if (onFloor == 1)
				{
					onFloor = 0;
					time = 0;
					prevVel = -20; //bad solution for hang time issue, but possible.
				}
			}
		}

		//exponentially decrease trajectory simulating gravity

		characterSprite.move(0, -1*(225 - pow(time-15, 2))/20);//(prevVel + pow(2, 1.1)) * 1.5);
		prevVel = (prevVel + pow(1.1, 2) * 0.75);

		//bound character to stay on screen.

		if (characterSprite.getPosition().y > window.getSize().y + -30 * scaleF)
		{
			characterSprite.setPosition(0, window.getSize().y - 30 * scaleF);
			onFloor = 1;
		}

		//set hitbox for player.

		hitBox.setPosition(characterSprite.getPosition().x + 5 * scaleF, characterSprite.getPosition().y + 15 * scaleF);

		//check if hitbox intersects an obstacle

		for (int i = 0; i < obstacles.size(); i++)
		{
			if (hitBox.getGlobalBounds().intersects(obstacles.at(i).getGlobalBounds()) && obstacles.at(i).getColor() != sf::Color::Blue)
			{
				obstaclesDodged--;
				obstacles.at(i).setColor(sf::Color::Blue);
			}
		}

		//draw all sprites

		window.clear();
		backgroundSprite.move(-3 * scaleF, 0);
		window.draw(backgroundSprite);
		window.draw(characterSprite);

		for (int i = 0; i < obstacles.size(); i++)
		{
			obstacles.at(i).move(-3.0 * scaleF, 0.0);
			window.draw(obstacles.at(i));
		}

		//if the last sprite moves off screen exit
		if (obstacles.at(obstacles.size()-1).getPosition().x < 0)
		{
			return obstaclesDodged;
		}

		//if not display next frame
		window.display();
		time++;
	}
	return obstaclesDodged;
}

//make background a bit longer
int miniGameRangedAttack(std::string projectileImage, sf::RenderWindow &window, double difficulty)
{
	int doorsDodged = 4, hMid = window.getSize().x / 2, vMid = window.getSize().y / 2, walls = 4, distance = 0;
	int time = 0, prevVel = 0;
	double speed = difficulty * .1, scaleF = window.getSize().y / 32.0 / 8;
	sf::Event event;
	std::vector<int> obsticleLocations;
	std::vector<double> obsticleHeights;
	std::vector<sf::Sprite> obsticles;

	//4 random distances and heights
	for (int i = 0; i < 4; i++)
	{
		obsticleLocations.push_back(6 + (rand() % 8));
		obsticleHeights.push_back(rand() % window.getSize().y);
	}

	//sum total distances
	distance = obsticleLocations.at(0) + obsticleLocations.at(1) + obsticleLocations.at(2) + obsticleLocations.at(3) + 2 * (window.getSize().x - window.getSize().y) / 32 / scaleF;

	//load Textures
	sf::Texture projectileTexture;
	projectileTexture.loadFromFile(projectileImage);
	sf::Sprite projectileSprite;
	projectileSprite.setTexture(projectileTexture);
	projectileSprite.setScale(scaleF, scaleF);

	sf::RectangleShape whiteScreen(sf::Vector2f(window.getSize().x, window.getSize().y));
	whiteScreen.setFillColor(sf::Color::White);

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("WoodFloor.png");
	backgroundTexture.setRepeated(true);
	sf::Sprite backgroundSprite(backgroundTexture, sf::IntRect(0, 0, distance * 32, 8 * 32));
	backgroundSprite.setScale(scaleF, scaleF);
	backgroundSprite.setColor(sf::Color::Color(255, 220, 190, 220));

	sf::Texture wallTexture;
	wallTexture.loadFromFile("StoneWallCorners.png", sf::IntRect(64, 32, 32, 32));
	wallTexture.setRepeated(true);
	sf::Sprite wallSprite(wallTexture, sf::IntRect(0, 0, 32, 8 * 32));
	wallSprite.setScale(scaleF, scaleF);
	wallSprite.setPosition(-hMid, -vMid);


	//hitbox
	sf::RectangleShape hitBox(sf::Vector2f(25 * scaleF, 2 * scaleF));

	//set locations of obsticles based on reandom values
	for (int i = 0; i < 4; i++)
	{
		obsticles.push_back(sf::Sprite(wallSprite));
		obsticles.at(2 * i).setPosition(obsticleLocations.at(i) * 32 * scaleF, obsticleHeights.at(i) + 48 * scaleF);
		obsticles.push_back(sf::Sprite(wallSprite));
		obsticles.at(2 * i + 1).setPosition(obsticleLocations.at(i) * 32 * scaleF, obsticleHeights.at(i) - window.getSize().y);

		if (i > 0)//offset the concurrent onsticles so they dont stack
		{
			obsticles.at(2 * i).move(obsticles.at(2 * i - 2).getPosition().x, 0);
			obsticles.at(2 * i + 1).move(obsticles.at(2 * i - 1).getPosition().x, 0);
		}
	}

	//main functionality
	while (true)//infinite loop
	{
		//event handling
		while (window.pollEvent(event))//poll
		{
			if (event.type == sf::Event::MouseButtonPressed)//if mouse pressed send arrow trajectory up
			{
				time = 0;
				prevVel = -20;
			}
		}

		//exponentially decrease trajectory simulating gravity
		projectileSprite.move(0, prevVel + pow(2, 1.1));
		prevVel = prevVel + pow(1.1, 2);

		//bound arrow to stay on screen
		if (projectileSprite.getPosition().y < -8 * 2 * scaleF)
		{
			projectileSprite.setPosition(0, -8 * 2 * scaleF);
		}
		else if (projectileSprite.getPosition().y > window.getSize().y + -8 * scaleF)
		{
			projectileSprite.setPosition(0, window.getSize().y - 8 * 2 * scaleF);
		}

		//set hitbox on stem of arrow
		hitBox.setPosition(projectileSprite.getPosition().x + 5 * scaleF, projectileSprite.getPosition().y + 15 * scaleF);

		//check if hitbox intersects an obsticle
		for (int i = 0; i < obsticles.size(); i++)
		{
			if (hitBox.getGlobalBounds().intersects(obsticles.at(i).getGlobalBounds()) && obsticles.at(i).getColor() != sf::Color::Red)
			{
				doorsDodged--;
				obsticles.at(i).setColor(sf::Color::Red);
			}
		}

		//draw all sprites
		window.clear();
		window.draw(whiteScreen);
		backgroundSprite.move(-1 * scaleF, 0);
		window.draw(backgroundSprite);
		window.draw(projectileSprite);
		for (int i = 0; i < obsticles.size(); i++)
		{
			obsticles.at(i).move(-1.0 * scaleF, 0.0);
			window.draw(obsticles.at(i));
		}

		//if the last sprite moves off screen exit
		if (obsticles.at(7).getPosition().x < 0)
		{
			return doorsDodged;
		}

		//if not display next frame
		window.display();
		time++;
	}
	return doorsDodged;
}

//fix skeleton bugs
//fix speed being same for each caharacter
//add difficulty
//add better score output
int miniGameDodgeAttack(sf::RenderWindow &window) {
	//initialize
	int limit = 0, direction = 0, direction2 = 0, direction3 = 0, direction4 = 0, randYValue = 0, randValue = 0, score = 0;
	double scaleF = window.getSize().y / 32.0 / 8;
	std::vector<int>  time;
	std::vector<double> characterx, charactery;
	sf::Event event;
	for (int i = 0; i < 4; i++)
	{
		time.push_back(30+rand()%60);
		characterx.push_back(rand() % window.getSize().x/time.at(i));
		charactery.push_back(rand() % window.getSize().y / time.at(i));
		switch (rand() % 4)
		{
		case 1:
			characterx.at(i) = -1*characterx.at(i);
			charactery.at(i) = charactery.at(i);
			break;
			
		case 2: 
			characterx.at(i) = characterx.at(i);
			charactery.at(i) = -1 * charactery.at(i);
			break;
		case 3: 
			characterx.at(i) = -1 * characterx.at(i);
			charactery.at(i) = -1 * charactery.at(i);
			break;
		default:
			characterx.at(i) = characterx.at(i);
			charactery.at(i) = charactery.at(i);
			break;
		}
	}

	//texturez
	sf::Texture StoneTile;
	StoneTile.loadFromFile("StoneTile.png");
	StoneTile.setRepeated(true);
	sf::Sprite StoneBackground(StoneTile, sf::IntRect(0,0,window.getSize().x/scaleF, window.getSize().y / scaleF));
	StoneBackground.setScale(scaleF, scaleF);

	sf::Texture attacker1;
	attacker1.loadFromFile("WizardMonster.png");
	sf::Sprite attackerSprite;
	attackerSprite.setTexture(attacker1);
	attackerSprite.setScale(scaleF * 2.5, scaleF * 2.5);
	attackerSprite.setPosition(Vector2f(rand()%window.getSize().x, rand() % window.getSize().y));

	sf::Texture attacker2;
	attacker2.loadFromFile("Skeleton.png");
	sf::Sprite attackerSprite2;
	attackerSprite2.setTexture(attacker2);
	attackerSprite2.setScale(scaleF * 2, scaleF * 2);
	attackerSprite2.setPosition(Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));

	sf::Texture attacker3;
	attacker3.loadFromFile("SwampMonster.png");
	sf::Sprite attackerSprite3;
	attackerSprite3.setTexture(attacker3);
	attackerSprite3.setScale(scaleF * 1, scaleF * 1);
	attackerSprite3.setPosition(Vector2f(0, 10.f));
	attackerSprite3.setPosition(Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));

	sf::Texture treasure;
	treasure.loadFromFile("HealthPotion.png");
	sf::Sprite treasureSprite;
	treasureSprite.setTexture(treasure);
	treasureSprite.setScale(scaleF * .75, scaleF * .75);
	treasureSprite.setPosition(Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));

	CircleShape attacker;
	bool isHit = false;
	attacker.setRadius(10.f);
	attacker.setFillColor(Color::Black);
	attacker.setPosition(Vector2f(0, 0));

	//hitbox of potion
	//sf::hitBox.setPosition(treasureSprite.getPosition().x + 5 * scaleF, treasureSprite.getPosition().y + 15 * scaleF);
	
	//loop
	while (limit < 300)
	{
		for (int i = 0; i < 4; i++)
		{
			if (time.at(i) <= 0)
			{
				time.at(i)=(30 + rand() % 60);
				characterx.push_back(rand() % window.getSize().y);
				charactery.push_back(rand() % window.getSize().y);
				switch (rand() % 4)
				{
				case 1:
					characterx.at(i) = -1 * characterx.at(i);
					charactery.at(i) = charactery.at(i);
					break;

				case 2:
					characterx.at(i) = characterx.at(i);
					charactery.at(i) = -1 * charactery.at(i);
					break;
				case 3:
					characterx.at(i) = -1 * characterx.at(i);
					charactery.at(i) = -1 * charactery.at(i);
					break;
				default:
					characterx.at(i) = characterx.at(i);
					charactery.at(i) = charactery.at(i);
					break;
				}
			}
		}
		//check windowClose
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (attackerSprite.getPosition().x <= 0 || attackerSprite.getPosition().x > window.getSize().x) {
			characterx.at(0) = -1 * characterx.at(0);
			limit++;
		}
		if (attackerSprite.getPosition().y >= window.getSize().y || attackerSprite.getPosition().y < 0) {
			charactery.at(0) = -1 * charactery.at(0);
			limit++;
		}
		if (attackerSprite2.getPosition().x <= 0 || attackerSprite2.getPosition().x > window.getSize().x) {
			characterx.at(1) = -1 * characterx.at(1);
			limit++;
		}
		if (attackerSprite2.getPosition().y >= window.getSize().y || attackerSprite2.getPosition().y < 0) {
			charactery.at(1) = -1 * charactery.at(1);
			limit++;
		}
		if (attackerSprite3.getPosition().x <= 0 || attackerSprite3.getPosition().x > window.getSize().x) {
			characterx.at(2) = -1 * characterx.at(2);
			limit++;
		}
		if (attackerSprite3.getPosition().y >= window.getSize().y || attackerSprite3.getPosition().y < 0) {
			charactery.at(2) = -1 * charactery.at(2);
			limit++;
		}
		if (treasureSprite.getPosition().x <= 0 || treasureSprite.getPosition().x > window.getSize().x) {
			characterx.at(3) = -1 * characterx.at(3);
			limit++;
		}
		if (treasureSprite.getPosition().y >= window.getSize().y || treasureSprite.getPosition().y < 0) {
			charactery.at(3) = -1 * charactery.at(3);
			limit++;
		}
		
		//enemy move
		attackerSprite.move(sf::Vector2f(characterx.at(0), charactery.at(0)));
		attackerSprite2.move(sf::Vector2f(characterx.at(1), charactery.at(1)));
		attackerSprite3.move(sf::Vector2f(characterx.at(2), charactery.at(2)));
		treasureSprite.move(sf::Vector2f(characterx.at(3), charactery.at(3)));

		//update attack
		if (!isHit) {
			attacker.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
		}

		if (attacker.getGlobalBounds().intersects(attackerSprite.getGlobalBounds())) {
			//reset 
			isHit = false;
			randYValue = rand() % window.getSize().y;
			randValue = randYValue;
			attackerSprite.setPosition(Vector2f(attackerSprite.getPosition().x, randValue));
			++limit;
			score--;
		}

		if (attacker.getGlobalBounds().intersects(attackerSprite2.getGlobalBounds())) {
			//reset 
			isHit = false;
			randYValue = rand() % window.getSize().y;
			randValue = randYValue;
			attackerSprite2.setPosition(Vector2f(attackerSprite2.getPosition().x, randValue));
			++limit;
			score--; //score for if you want to implement 
		}
		if (attacker.getGlobalBounds().intersects(attackerSprite3.getGlobalBounds())) {
			//reset 
			isHit = false;
			randYValue = rand() % window.getSize().y;
			randValue = randYValue;
			attackerSprite3.setPosition(Vector2f(attackerSprite3.getPosition().x, randValue));
			++limit;
			score--;
		}
		if (treasureSprite.getGlobalBounds().intersects(attacker.getGlobalBounds())) {
			//reset 
			isHit = false;

			randYValue = rand() % window.getSize().y;
			randValue = randYValue;
			randYValue = rand() % window.getSize().y;
			treasureSprite.setPosition(Vector2f(randYValue, randValue));
			randValue = rand() % 6;
			
			score = score + 2;
			limit++;
		}


		window.clear();
		window.draw(StoneBackground);
		window.draw(attackerSprite);
		window.draw(attackerSprite2);
		window.draw(attackerSprite3);
		window.draw(treasureSprite);
		window.draw(attacker);
		window.display();
		for (int i = 0; i < 4; i++)
		{
			time.at(i)--;
		}
	}
	return 0;
}


int miniGameKeyPuzzle(sf::RenderWindow &window)
{
	int correct_guess = 4, vMid = window.getSize().y/2, hMid = window.getSize().x / 2, guess = 0;
	double scaleF = window.getSize().y / 32 / 8;
	sf::Event event;
	std::vector<sf::Sprite> tines;

	sf::Texture key;
	sf::Texture triangle;
	sf::Texture square;
	sf::Texture star;
	sf::Texture circle;
	sf::Texture back;
	sf::Texture backTile;

	key.loadFromFile("KeyOutline.png");
	triangle.loadFromFile("ChestMiniGameTriangle.png");
	square.loadFromFile("ChestMiniGameSquare.png");
	star.loadFromFile("ChestMiniGameStar.png");
	circle.loadFromFile("ChestMiniGameCircle.png");
	backTile.loadFromFile("StoneTile.png");
	backTile.setRepeated(true);

	switch (rand() % 3)
	{
	case 1:
		back.loadFromFile("Door1.png");
		break;
	case 2:
		back.loadFromFile("Door2.png");
		break;
	default:
		back.loadFromFile("Door3.png");
		break;
	}

	sf::Sprite keySprite(key);
	sf::Sprite backSprite(back);

	sf::Sprite triangleSprite(triangle);
	sf::Sprite squareSprite(square);
	sf::Sprite circleSprite(circle);
	sf::Sprite starSprite(star);

	sf::Sprite backBack(backTile, sf::IntRect(0,0,64,64));
	for (int i = 0; i < 4; i++)
	{
		switch (rand() % 4)
		{
		case 1:
			tines.push_back(sf::Sprite(triangle));
			break;
		case 2:
			tines.push_back(sf::Sprite(square));
			break;
		case 3:
			tines.push_back(sf::Sprite(star));
			break;
		default:
			tines.push_back(sf::Sprite(circle));
			break;
		}
		switch (i)
		{
		case 0:
			tines.at(0).setPosition(hMid - scaleF * 32 * 1.125, vMid - scaleF * 32 * 2.5);
			break;
		case 1:
			tines.at(1).setPosition(hMid + scaleF * 32 * 0.125, vMid - scaleF * 32 * 2.5);
			break;
		case 2:
			tines.at(2).setPosition(hMid + scaleF * 32 * 1.375, vMid - scaleF * 32 * 2.5);
			break;
		default:
			tines.at(3).setPosition(hMid + scaleF * 32 * 2.625, vMid - scaleF * 32 * 2.5);
			break;
		}
		tines.at(i).setColor(sf::Color::Black);
		tines.at(i).setScale(scaleF, scaleF);
	}


	backSprite.setScale(scaleF * 8, scaleF * 8);
	keySprite.setScale(scaleF * 8, scaleF * 8);
	backBack.setScale(scaleF * 8, scaleF * 8);
	triangleSprite.setScale(scaleF , scaleF );
	squareSprite.setScale(scaleF , scaleF );
	circleSprite.setScale(scaleF , scaleF );
	starSprite.setScale(scaleF , scaleF );

	backSprite.move(hMid - scaleF*32*4, 0);	
	keySprite.move(hMid - scaleF*32*4, 0);

	triangleSprite.setPosition(hMid - 2 * 32 * scaleF, vMid);
	squareSprite.setPosition(hMid - 1 * 32 * scaleF, vMid);
	starSprite.setPosition(hMid - 0 * 32 * scaleF, vMid);
	circleSprite.setPosition(hMid + 1 * 32 * scaleF, vMid);
	
	while (true)
	{
		while (window.pollEvent(event))//poll
		{
			if (event.type == sf::Event::MouseButtonPressed)//if mouse pressed send arrow trajectory up
			{
				if (sf::Mouse::getPosition().y > vMid && sf::Mouse::getPosition().y < hMid + 1 * 32 * scaleF)//vertical correct
				{
					if (sf::Mouse::getPosition().x < hMid - 1 * 32 * scaleF && sf::Mouse::getPosition().x > hMid - 2 * 32 * scaleF && tines.at(guess).getTexture() == &triangle)
					{
						correct_guess++;
						tines.at(guess).setColor(sf::Color::White);
					}
					else if (sf::Mouse::getPosition().x < hMid - 0 * 32 * scaleF && sf::Mouse::getPosition().x > hMid - 1 * 32 * scaleF && tines.at(guess).getTexture() == &square)
					{
						correct_guess++;
						tines.at(guess).setColor(sf::Color::White);
					}
					else if (sf::Mouse::getPosition().x < hMid + 1 * 32 * scaleF && sf::Mouse::getPosition().x > hMid - 0 * 32 * scaleF && tines.at(guess).getTexture() == &star)
					{
						correct_guess++;
						tines.at(guess).setColor(sf::Color::White);
					}
					else if (sf::Mouse::getPosition().x < hMid + 2 * 32 * scaleF && sf::Mouse::getPosition().x > hMid + 1 * 32 * scaleF && tines.at(guess).getTexture() == &circle)
					{
						correct_guess++;
						tines.at(guess).setColor(sf::Color::White);
					}
					else {
						tines.at(guess).setColor(sf::Color::Red);
					}
					guess++;
				}
			}
		}


		window.clear();
		window.draw(backBack);
		window.draw(backSprite);
		window.draw(keySprite);
		window.draw(triangleSprite);
		window.draw(squareSprite);
		window.draw(starSprite);
		window.draw(circleSprite);
		for (int i = 0; i < 4; i++)
		{
			window.draw(tines.at(i));
		}

		if (guess > 3)
		{
			return correct_guess;
		}

		window.display();
	}

	return correct_guess;
}