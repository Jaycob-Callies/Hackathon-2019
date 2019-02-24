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

	return 0;
}
