#include "Header.h"
using namespace sf;
#define WIDTH 1500
#define HEIGHT 300

//int difficulty = 0;

struct Position
{
	int x;
	int y;
};

int MiniGameEvasion(sf::RenderWindow &window)
{
	//sf::Image character, int difficulty, sf::RenderWindow &window
	window.setFramerateLimit(60);

/*	Texture t1;
	Texture t2;
	t1.loadFromFile("images/character1.png");*/ //probably dont need both of these images for the character.
	//t2.loadFromFile("images/character2.png");

	/*Sprite character[2];
	character[0] = Sprite(t1);
	character[1] = Sprite(t2);*/

	CircleShape character(100.f, 8000);
	character.setFillColor(sf::Color::Magenta);
	Vector2<int> rip = { 0, 0 };

	static const int CHARACTER_Y_BOTTOM = HEIGHT + 400; //replace 0 with t1.getSize().y.
	Position characterPos;
	characterPos.x = 50;
	characterPos.y = CHARACTER_Y_BOTTOM;

	int index = 0, amountOfCorrectResponses = 0;
	float frame = 0.f, frameSpeed = 0.4f;
	const int changeCount = 5;

	const int gravity = 5;
	bool isJumping = true;
	bool isBottom = false;

/*	Texture t3;
	t3.loadFromFile("images/obstacle.png");*/ //add more obstacles and randomize obstacles user encounters.
	/*Sprite obstacle(t3);*/

	CircleShape obstacle(100.f, 3);
	obstacle.setFillColor(sf::Color::Cyan);

	static const int OBSTACLE_Y_BOTTOM = HEIGHT + 450; //replace 0 with - t3.getSize().y.
	Position obstaclePos;
	obstaclePos.x = WIDTH - 20;
	obstaclePos.y = OBSTACLE_Y_BOTTOM;

	const int obstacleSpeed = 4; //Control the speed at which obstacles scroll at you (impliment this into dificulty later?)

	while (window.isOpen()) //while the window is open this will run.
	{
		Event event;

		while (window.pollEvent(event)) //While there are pending events this will run.
		{
			if (event.type == Event::Closed) //close out game.
			{
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed) //if a mouse button is pressed, continue...
			{
				if (isBottom && isJumping) //if feet on ground and press mouse button to jump...
				{
					isJumping = true; //jump will happen...
					isBottom = false; //no longer have feet on ground...
				}
			}


			//need to add collision detection between character and objects.
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			characterPos.y = -10;

			if (characterPos.y > 500) //if jumping is true... (isJumping)
			{
				characterPos.y -= gravity; //character position in y-direction = character pos in y-direction minus gravity.
			}
			else if (characterPos.y < 500)//otherwise...
			{
				characterPos.y = 500; //character position in y-direction = character pos in y-direction plus gravity.
			}

			//if (characterPos.y >= CHARACTER_Y_BOTTOM) //if character pos in y-dir is GREATER than OR EQUAL TO the bottom of lvl...
			//{
			//	characterPos.y = CHARACTER_Y_BOTTOM; //then char pos in y-dir equal to bottom of lvl...
			//	isBottom = true; //and feet on ground is true.
			//}
			//if (characterPos.y <= CHARACTER_Y_BOTTOM) //if char pos in y-dir is less than or equal to bottom of lvl...
			//{
			//	isJumping = false; //then you are not jumping.
			//}
		}
		//if (characterPos.y > 500) //if jumping is true... (isJumping)
		//{
		//	characterPos.y -= gravity; //character position in y-direction = character pos in y-direction minus gravity.
		//}
		//else if (characterPos.y < 500)//otherwise...
		//{
		//	characterPos.y = 500; //character position in y-direction = character pos in y-direction plus gravity.
		//}

		//if (characterPos.y >= CHARACTER_Y_BOTTOM) //if character pos in y-dir is GREATER than OR EQUAL TO the bottom of lvl...
		//{
		//	characterPos.y = CHARACTER_Y_BOTTOM; //then char pos in y-dir equal to bottom of lvl...
		//	isBottom = true; //and feet on ground is true.
		//}
		//if (characterPos.y <= CHARACTER_Y_BOTTOM) //if char pos in y-dir is less than or equal to bottom of lvl...
		//{
		//	isJumping = false; //then you are not jumping.
		//}

		frame += frameSpeed;
		if (frame > changeCount)
		{
			frame -= changeCount;
			++index;
			if (index >= 2) { index = 0; }
		}

		if (obstaclePos.x <= 0)
		{
			obstaclePos.x = WIDTH;
		}
		else
		{
			obstaclePos.x -= obstacleSpeed;
		}

		obstacle.setPosition(obstaclePos.x, obstaclePos.y);

		character.setPosition(characterPos.x, characterPos.y); //replace character[index]

		window.clear(Color::Black); //Maybe change this black background to something more colorful.
		window.draw(character); //replace character[index]
		window.draw(obstacle);

		window.display();

	}

	return amountOfCorrectResponses;
}

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




int miniGameDodgeAttack(sf::RenderWindow &window)
{
	int limit = 0, direction = 0, direction2 = 0, direction3 = 0, randYValue = 0, randValue = 0, score = 0, clicked = 4;
double scaleF = window.getSize().y / 32.0 / 8;
std::vector<int> characterx, charactery;

	//set locations of obsticles based on reandom values
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


		//if not display next frame
		window.draw(attackerSprite);
		window.draw(attackerSprite2);
		window.draw(attackerSprite3);
			
		window.draw(attackerSprite3);
		window.draw(treasureSprite);
		window.draw(attacker);
		window.display();
		clicked--;
	}
}

int miniGameKeyPuzzle(sf::RenderWindow &window, double difficulty)
{
	int correct_guess = 0;
	sf::Texture key1Texture;
	key1Texture.loadFromFile("PossibleKey1.png");

	sf::Sprite key1Sprite;
	key1Sprite.setTexture(key1Texture);

	window.draw(key1Sprite);
	window.draw(key1Sprite);

	sf::Texture key2Texture;
	key2Texture.loadFromFile("PossibleKey2.png");

	sf::Sprite key2Sprite;
	key2Sprite.setTexture(key2Texture);

	window.draw(key2Sprite);
	window.draw(key2Sprite);

	sf::Texture key3Texture;
	key3Texture.loadFromFile("PossibleKey3.png");

	sf::Sprite key3Sprite;
	key3Sprite.setTexture(key1Texture);

	window.draw(key3Sprite);
	window.draw(key3Sprite);

	
	// wanting a memory matching game
	
	//put the images into an array, randomize the array

	//have another image on top, that when selected it disapears until another is selected, and if they match both images disapear
	//if not the same image, then the top image reappears ontop, and they have to select again
	//continues until all the same images are matched

	//exits
	return correct_guess;
}
int miniGameDoorPuzzle(sf::RenderWindow &window /*unsure what else it might need*/)
{
	//opens a picture, displays it

	// then the puzzle, the moving type, the picture is cut into 8 parts, having 9 sections

	// 3 4 6
	// 8 2 1
	// 7 5

	// v v v

	// 1 2 3
	// 4 5 6
	// 7 8 

	//can move the pieces to open slot. When the image matches the image shown then it is done

	//would need to display both the original image and the cut up version
}