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
		displayed = false;
		floorType = rand() % 4;//{Dirt, Grass, Wood, Stone};//4
		roomType = rand() % 6;//{Trap, Monster, Chest, Empty, Hostage, Healing};//6
		pLeft = NULL;
		pRight = NULL;
		pTop = NULL;
		pBottom = NULL;
		for (int i = 0; i < 16; i++)
		{
			if (i == 0)
			{
				switch (roomType)
				{
				case 0:
					decorations.push_back("PitFullOfSpikes.png");
					break;
				case 1:
					decorations.push_back("WMTop.png");
					break;
				case 2:
					decorations.push_back("ChestTop.png");
					break;
				case 3:
					decorations.push_back("Empty.png");
					break;
				case 4:
					decorations.push_back("DIDTop.png");
					break;
				default:
					decorations.push_back("HealthTemple.png");
					break;
				}
				i++;
			}
			switch (rand() % 16)
			{
			case 0:
				if (floorType < 2)
					decorations.push_back("GrassBlades.png");
				else
					decorations.push_back("Shield.png");
				break;
			case 1:
				decorations.push_back("Knapsack.png");
				break;
			case 2:
				if (floorType < 2)
					decorations.push_back("Sword.png");
				else
					decorations.push_back("Table.png");
				default:
					decorations.push_back("Empty.png");
				break;
			}
		}
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
		explored = true;
		Room* temp = NULL;
		if (pTop == NULL)
		{
			temp = new(Room);
			temp->setpBottom(this);
			this->pTop = temp;
		}
		if (pBottom == NULL)
		{
			temp = new(Room);
			temp->setpTop(this);
			this->pBottom = temp;
		}
		if (pLeft == NULL)
		{
			temp = new(Room);
			temp->setpRight(this);
			this->pLeft = temp;
		}
		if (pRight == NULL)
		{
			temp = new(Room);
			temp->setpLeft(this);
			this->pRight = temp;
		}
	}
	bool getExplore() {
		return explored;
	}
	Room* getpTop() {
		return pTop;
	}	
	Room* getpBottom() {
		return pBottom;
	}
	Room* getpLeft() {
		return pLeft;
	}
	Room* getpRight() {
		return pRight;
	}
	int getFloorType()
	{
		return floorType;
	}
	int getRoomType()
	{
		return roomType;
	}
	void kill() {
		roomType = 3;
	}
	void draw(int startx, int starty, sf::RenderWindow &window)
	{
		Room* temp = NULL;
		if (pTop == NULL)
		{
			temp = new(Room);
			temp->setpBottom(this);
			this->pTop = temp;
		}
		if (pBottom == NULL)
		{
			temp = new(Room);
			temp->setpTop(this);
			this->pBottom = temp;
		}
		if (pLeft == NULL)
		{
			temp = new(Room);
			temp->setpRight(this);
			this->pLeft = temp;
		}
		if (pRight == NULL)
		{
			temp = new(Room);
			temp->setpLeft(this);
			this->pRight = temp;
		}
		sf::Texture background;
		sf::Texture wall;
		sf::Texture doorToOut;
		sf::Texture doorToIn;
		
		//background
		switch (floorType)//{Dirt, Grass, Wood, Stone};//4
		{
		case 0:
			background.loadFromFile("Dirt.png");
			break;
		case 1:
			background.loadFromFile("Grass.png");
			break;
		case 2:
			background.loadFromFile("WoodFloor.png");
			break;
		default:
			background.loadFromFile("StoneTile.png");
			break;
		}
		background.setRepeated(true);
		sf::Sprite backgroundSprite(background, sf::IntRect(0, 0, 192, 192));
		backgroundSprite.move(startx, starty);
		backgroundSprite.setScale(window.getSize().y/32.0/ 18.0, window.getSize().y / 32.0 / 18.0);
		window.draw(backgroundSprite);

		//decos
		sf::Texture decoration;
		decoration.loadFromFile(decorations.at(0));
		sf::Sprite decorationSp(decoration);
		//decorationSp.setScale(window.getSize().y / 32.0 / 18.0, window.getSize().y / 32.0 / 18.0);
		//decorationSp.setPosition(startx + window.getSize().y / 32.0 / 18.0, starty + window.getSize().y / 32.0 / 18.0);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				decoration.loadFromFile(decorations.at(4 * i + j));
				decorationSp.setTexture(decoration);
				decorationSp.setScale(window.getSize().y / 32.0 / 18.0, window.getSize().y / 32.0 / 18.0);
				decorationSp.setPosition(startx + window.getSize().y / 18.0 * (1.0 + j), starty + window.getSize().y / 18.0 * (1.0 + i));
				window.draw(decorationSp);
			}
		}
		this->displayed = true;

		if (pTop->explored == true && pTop->displayed == false)
			pTop->draw(startx, starty- window.getSize().y  / 18 * 6, window);
		if (pBottom->explored == true && pBottom->displayed == false)
			pBottom->draw(startx, starty + window.getSize().y  / 18 * 6, window);
		if (pLeft->explored == true && pLeft->displayed == false)
			pLeft->draw(startx - window.getSize().y / 18 * 6,  starty, window);
		if (pRight->explored == true && pRight->displayed == false)
			pRight->draw(startx + window.getSize().y / 18 * 6,  starty, window);

	}
	void refresh() {
		this->displayed = false;

		if (pTop->displayed == true)
			pTop->refresh();
		if (pBottom->displayed == true)
			pBottom->refresh();
		if (pLeft->displayed == true)
			pLeft->refresh();
		if (pRight->displayed == true)
			pRight->refresh();

	}
	/*void dropItem(std::string itemFile){
		dropped.push_back(itemFile);
	}
	std::string pickupItem(std::string itemFile) {
		for (std::vector<std::string>::iterator i = dropped.begin(); i != dropped.end(); i++)
		{
			if ((*i).data == itemFile)
			{
				dropped.erase(i, i);
				return itemFile;
			}
		}
		return "";
	}*/

private:
	bool explored;
	bool displayed;
	int floorType; //{Dirt, Grass, Wood, Stone};//4
	int roomType; //{Trap, Monster, Chest, Empty, Hostage, Healing};//6
	//std::vector<std::string> dropped;
	std::vector<std::string> decorations;
	Room* pLeft;
	Room* pTop;
	Room* pRight;
	Room* pBottom;
};


class Character{

public:
	Character() {
		location = NULL;
		stats = { 10,10,5,5,5,5 };
		weapon = potion = follower = file = name = "";
	}
	~Character() {
	}
	void setLocation(Room*newLocation) {
		location = newLocation;
	}
	void setStats(Stats newStats) {
		stats = newStats;
	}
	void setWeapon(std::string newWeapon) {
		weapon = newWeapon;
	}	
	void setPotion(std::string newPotion) {
		potion = newPotion;
	}
	void setFollower(std::string newFollower) {
		follower = newFollower;
	}
	void setFile(std::string newFile) {
		file = newFile;
	}
	void setTopFile(std::string newTopFile) {
		topFile = newTopFile;
	}
	void setName(std::string newName) {
		name = newName;
	}
	Room* getLocation() {
		return location;
	}
	Stats getStats() {
		return stats;
	}
	std::string getWeapon() {
		return weapon;
	}
	std::string getPotion() {
		return potion;
	}
	std::string getFollower() {
		return follower;
	}
	std::string getFile() {
		return file;
	}
	std::string getTopFile() {
		return topFile;
	}
	std::string getName() {
		return name;
	}
	void refresh()
	{
		location->refresh();
	}
	void display(sf::RenderWindow &window){
		double scaleF = window.getSize().y / 32 / 18;
		double offset = scaleF, hMid = window.getSize().x/2 - offset, vMid = window.getSize().y/2 - offset;

		sf::Texture fog;
		fog.loadFromFile("FogCorners.png", sf::IntRect(32, 32, 32, 32));
		fog.setRepeated(true);
		sf::Sprite fogback(fog, sf::IntRect(32, 32, window.getSize().x, window.getSize().y));
		fogback.setScale(scaleF, scaleF);
		fogback.setPosition(0,0);

		window.draw(fogback);
		if (location != NULL)
		{
			location->draw(window.getSize().x/2 - window.getSize().y/18*3, window.getSize().y / 2 - window.getSize().y / 18 * 3, window);
		}
	}
private:
	Room* location;
	Stats stats;
	std::string weapon;
	std::string potion;
	std::string follower;
	std::string file;
	std::string topFile;
	std::string name;
};

int miniGameDodgeAttack(sf::RenderWindow &window);
int miniGameRangedAttack(std::string projectileImage, sf::RenderWindow &window, double difficulty);
int miniGameKeyPuzzle(sf::RenderWindow &window);
int miniGameEvasion(std::string characterImage, sf::RenderWindow &window, double evasionDifficulty);
int miniGameDodgeAttack(sf::RenderWindow &window);
void beachBall(sf::RenderWindow &window);
void mainMenu(sf::RenderWindow &window);
std::vector<Character> characterSelect(sf::RenderWindow &window);
int game(std::vector<Character> players, sf::RenderWindow &window);
void play(sf::RenderWindow &window, Character player);
