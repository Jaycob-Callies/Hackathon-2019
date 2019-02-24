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

	int index = 0;
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
		obsticleLocations.push_back(6+ (rand() % 8));
		obsticleHeights.push_back(rand() % window.getSize().y);
	}
	
	//sum total distances
	distance = obsticleLocations.at(0) + obsticleLocations.at(1) + obsticleLocations.at(2) + obsticleLocations.at(3) + 2*(window.getSize().x - window.getSize().y)/32/scaleF;

	//load Textures
	sf::Texture projectileTexture;
	projectileTexture.loadFromFile(projectileImage);
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
	wallSprite.setColor(sf::Color::Color(222, 184, 135, 255));

	//hitbox
	sf::RectangleShape hitBox(sf::Vector2f(25*scaleF, 2*scaleF));

	//set locations of obsticles based on reandom values
	for (int i = 0; i < 4; i++)
	{
		obsticles.push_back(sf::Sprite(wallSprite));
		obsticles.at(2*i).setPosition(obsticleLocations.at(i)*32 * scaleF, obsticleHeights.at(i) + 48*scaleF);
		obsticles.push_back(sf::Sprite(wallSprite));
		obsticles.at(2*i+1).setPosition(obsticleLocations.at(i) * 32 * scaleF, obsticleHeights.at(i) - window.getSize().y);

		if (i > 0)//offset the concurrent onsticles so they dont stack
		{
			obsticles.at(2*i).move(obsticles.at(2*i - 2).getPosition().x, 0);
			obsticles.at(2*i+1).move(obsticles.at(2*i - 1).getPosition().x, 0);
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
		if (projectileSprite.getPosition().y < -8 * 2* scaleF )
		{
			projectileSprite.setPosition(0, -8 *2* scaleF);
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