#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;
using namespace sf;

enum floorType {Dirt, Grass, Wood, Stone};//4
enum roomType {Trap, Monster, Chest, Empty, Hostage, Healing};//6

struct stats {
	int health;
	int maxHealth;
	int intelligence;
	int sanity;
	int strength;
	int speed;
}typedef Stats;

class Room
{
public:
	Room() {
		explored = 0;
		floorType = rand() % 4;
		roomType = rand() % 6;
		pLeft = NULL;
		pRight = NULL;
		pTop = NULL;
		pBottom = NULL;
	}
	~Room() {
		delete pLeft;
		delete pRight;
		delete pTop;
		delete pBottom;
	}
	void setpLeft(Room* newpLeft) {
		pLeft = newpLeft;
	}
	void setpRight(Room* newpRight) {
		pRight = newpRight;
	}
	void setpBottom(Room* newpBottom) {
		pBottom = newpBottom;
	}
	void setpTop(Room* newpTop) {
		pTop = newpTop;
	}
	void explore(){
		explored = 1;
	}


private:
	bool explored;
	int floorType;
	int roomType;
	std::vector<std::string> dropped;
	Room* pLeft;
	Room* pTop;
	Room* pRight;
	Room* pBottom;
};


class Character{

public:
	//void addWeapon(sf::Image){
		
	//}
	//void addHealth(int *currentHealth) {

	//}
	//void characterMovement() {

	//}
private:
	Room* location;
	Stats stats;
	std::string weapon;
	std::string potion;
	std::string follower;
};

int miniGameDodgeAttack(sf::RenderWindow &window);
int miniGameRangedAttack(std::string projectileImage, sf::RenderWindow &window, double difficulty);
int miniGameKeyPuzzle(sf::RenderWindow &window);
int miniGameEvasion(std::string characterImage, sf::RenderWindow &window, double evasionDifficulty);
int miniGameDodgeAttack(sf::RenderWindow &window);
void beachBall(sf::RenderWindow &window);
void mainMenu(sf::RenderWindow &window);
