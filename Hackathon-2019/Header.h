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
	Room(sf::Vector2i originOff) {
		explored = 0;
		displayed = false;
		searchedForReference = false;
		floorType = rand() % 4;//{Dirt, Grass, Wood, Stone};//4
		roomType = rand() % 6;//{Trap, Monster, Chest, Empty, Hostage, Healing};//6
		pLeft = NULL;
		pRight = NULL;
		pTop = NULL;
		pBottom = NULL;
		originOffset = originOff;
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
		if (pTop == NULL)///////////////////////////////////////////////////////////////////////////////////
		{
			temp = this->findReference(sf::Vector2i(this->originOffset.x, this->originOffset.y - 1));
			if (temp == NULL)
			{
				temp = new(Room)(sf::Vector2i(this->originOffset.x, this->originOffset.y - 1));
			}
			temp->setpBottom(this);
			this->pTop = temp;
		}
		if (pBottom == NULL)
		{
			temp = this->findReference(sf::Vector2i(this->originOffset.x, this->originOffset.y + 1));
			if (temp == NULL)
			{
				temp = new(Room)(sf::Vector2i(this->originOffset.x, this->originOffset.y + 1));
			}
			temp->setpTop(this);
			this->pBottom = temp;
		}
		if (pLeft == NULL)
		{
			temp = this->findReference(sf::Vector2i(this->originOffset.x-1, this->originOffset.y));
			if (temp == NULL)
			{
				temp = new(Room)(sf::Vector2i(this->originOffset.x-1, this->originOffset.y));
			}			
			temp->setpRight(this);
			this->pLeft = temp;
		}
		if (pRight == NULL)
		{
			temp = this->findReference(sf::Vector2i(this->originOffset.x + 1, this->originOffset.y));
			if (temp == NULL)
			{
				temp = new(Room)(sf::Vector2i(this->originOffset.x + 1, this->originOffset.y));
			}	
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
	void addPlayer(std::string player) {
		this->players.push_back(player);
	}
	void removePlayer(std::string player) {
		std::vector<std::string> temp;
		for (int i = 0; i < this->players.size() - 1; i++)
		{
			if (player == players.at(i))
			{
				for (int j = 0; j < this->players.size() - 1; j++) {
					if (j != i)
					{
						temp.push_back(players.at(i));
					}
				}
				players = temp;
				i = this->players.size();
			}
		}
	}
	void draw(int startx, int starty, sf::RenderWindow &window)
	{
		float scaleF = window.getSize().y / (float)32.0 / (float)18.0;
		Room* temp = NULL;
		if (pTop == NULL)///////////////////////////////////////////////////////////////////////////////////
		{
			temp = this->findReference(sf::Vector2i(this->originOffset.x, this->originOffset.y - 1));
			if (temp == NULL)
			{
				temp = new(Room)(sf::Vector2i(this->originOffset.x, this->originOffset.y - 1));
			}
			temp->setpBottom(this);
			this->pTop = temp;
		}
		if (pBottom == NULL)
		{
			temp = this->findReference(sf::Vector2i(this->originOffset.x, this->originOffset.y + 1));
			if (temp == NULL)
			{
				temp = new(Room)(sf::Vector2i(this->originOffset.x, this->originOffset.y + 1));
			}
			temp->setpTop(this);
			this->pBottom = temp;
		}
		if (pLeft == NULL)
		{
			temp = this->findReference(sf::Vector2i(this->originOffset.x - 1, this->originOffset.y));
			if (temp == NULL)
			{
				temp = new(Room)(sf::Vector2i(this->originOffset.x - 1, this->originOffset.y));
			}
			temp->setpRight(this);
			this->pLeft = temp;
		}
		if (pRight == NULL)
		{
			temp = this->findReference(sf::Vector2i(this->originOffset.x + 1, this->originOffset.y));
			if (temp == NULL)
			{
				temp = new(Room)(sf::Vector2i(this->originOffset.x + 1, this->originOffset.y));
			}
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
		backgroundSprite.move((float)startx, (float)starty);
		backgroundSprite.setScale(window.getSize().y/ (float)32.0/ (float)18.0, window.getSize().y / (float)32.0 / (float)18.0);
		window.draw(backgroundSprite);

		//walls
		sf::Texture wallT, wallB, wallR, wallL, wallTR, wallTL, wallBR, wallBL;
		//load texture corresponding to floor type
		if (this->floorType < 2 && this->pTop->getFloorType() < 2)
		{
			wallT.loadFromFile("WoodFenceCorners.png", sf::IntRect(32, 0, 32, 32));
		}
		else
		{
			wallT.loadFromFile("StoneWallCorners.png", sf::IntRect(32, 0, 32, 32));
		}
		if (this->floorType < 2 && this->pBottom->getFloorType() < 2)
		{
			wallB.loadFromFile("WoodFenceCorners.png", sf::IntRect(32, 64, 32, 32));
		}
		else
		{
			wallB.loadFromFile("StoneWallCorners.png", sf::IntRect(32, 64, 32, 32));
		}
		if (this->floorType < 2 && this->pLeft->getFloorType() < 2)
		{
			wallL.loadFromFile("WoodFenceCorners.png", sf::IntRect(0, 32, 32, 32));
		}
		else
		{
			wallL.loadFromFile("StoneWallCorners.png", sf::IntRect(0, 32, 32, 32));
		}
		if (this->floorType < 2 && this->pRight->getFloorType() < 2)
		{
			wallR.loadFromFile("WoodFenceCorners.png", sf::IntRect(64, 32, 32, 32));
		}
		else
		{
			wallR.loadFromFile("StoneWallCorners.png", sf::IntRect(64, 32, 32, 32));
		}
		if (this->floorType < 2 && this->pRight->getFloorType() < 2 && this->pTop->getFloorType() < 2)
		{
			wallTR.loadFromFile("WoodFenceCorners.png", sf::IntRect(64, 0, 32, 32));
		}
		else
		{
			wallTR.loadFromFile("StoneWallCorners.png", sf::IntRect(64, 0, 32, 32));
		}
		if (this->floorType < 2 && this->pLeft->getFloorType() < 2 && this->pTop->getFloorType() < 2)
		{
			wallTL.loadFromFile("WoodFenceCorners.png", sf::IntRect(0, 0, 32, 32));
		}
		else
		{
			wallTL.loadFromFile("StoneWallCorners.png", sf::IntRect(0, 0, 32, 32));
		}
		if (this->floorType < 2 && this->pRight->getFloorType() < 2 && this->pBottom->getFloorType() < 2)
		{
			wallBR.loadFromFile("WoodFenceCorners.png", sf::IntRect(64, 64, 32, 32));
		}
		else
		{
			wallBR.loadFromFile("StoneWallCorners.png", sf::IntRect(64, 64, 32, 32));
		}
		if (this->floorType < 2 && this->pLeft->getFloorType() < 2 && this->pBottom->getFloorType() < 2)
		{
			wallBL.loadFromFile("WoodFenceCorners.png", sf::IntRect(0, 64, 32, 32));
		}
		else
		{
			wallBL.loadFromFile("StoneWallCorners.png", sf::IntRect(0, 64, 32, 32));
		}
		//tile sides
		wallR.setRepeated(true);
		wallL.setRepeated(true);
		wallB.setRepeated(true);
		wallT.setRepeated(true);
		//turn textures to sprites
		sf::Sprite wallTSp(wallT, sf::IntRect(0,0,4*32,32)), wallBSp(wallB, sf::IntRect(0, 0, 4 * 32, 32)), wallRSp(wallR, sf::IntRect(0, 0, 32, 4 * 32)), wallLSp(wallL, sf::IntRect(0, 0, 32, 4 * 32)), wallTRSp(wallTR, sf::IntRect(0, 0, 32, 32)), wallTLSp(wallTL, sf::IntRect(0, 0, 32, 32)), wallBRSp(wallBR, sf::IntRect(0, 0, 32, 32)), wallBLSp(wallBL, sf::IntRect(0, 0, 32, 32));
		//scale sprites
		wallTSp.setScale(scaleF, scaleF);
		wallBSp.setScale(scaleF, scaleF);
		wallLSp.setScale(scaleF, scaleF);
		wallRSp.setScale(scaleF, scaleF);
		wallTRSp.setScale(scaleF, scaleF);
		wallTLSp.setScale(scaleF, scaleF);
		wallBRSp.setScale(scaleF, scaleF);
		wallBLSp.setScale(scaleF, scaleF);
		//move sprites
		wallTLSp.setPosition(startx, starty);
		wallTSp.setPosition(startx + scaleF * 32, starty);
		wallTRSp.setPosition(startx+ scaleF * 5 * 32, starty);
		wallLSp.setPosition(startx, starty + scaleF * 32);
		wallBLSp.setPosition(startx, starty + scaleF * 5 * 32);
		wallRSp.setPosition(startx + scaleF * 5 * 32, starty + scaleF * 32);
		wallBSp.setPosition(startx + scaleF * 32, starty + scaleF * 5 * 32);
		wallBRSp.setPosition(startx + scaleF * 5 * 32, starty + scaleF * 5 * 32);
		//draw sprites
		window.draw(wallTLSp);
		window.draw(wallTRSp);
		window.draw(wallBLSp);
		window.draw(wallBRSp);
		window.draw(wallLSp);
		window.draw(wallRSp);
		window.draw(wallTSp);
		window.draw(wallBSp);

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
				decorationSp.setScale(window.getSize().y / (float)32.0 / (float)18.0, window.getSize().y / (float)32.0 / (float)18.0);
				decorationSp.setPosition(startx + window.getSize().y / (float)18.0 * (float)(1.0 + j), starty + window.getSize().y / (float)18.0 * (float)(1.0 + i));
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
	Room* findReference(sf::Vector2i coords) {
		Room* reference = this->searchForReference(coords);
		this->endSearch();
		return reference;
	}
	Room* searchForReference(sf::Vector2i coords) {//returns pointer to room at coor or null if not found
		Room* value = NULL;
		this->searchedForReference = true;
		if (this->originOffset == coords)//this is the cell looking for
		{
			return this;
		}
		else//still looking
		{
			if (this->pTop != NULL && this->pTop->searchedForReference == false)//if you can search top
			{
				value = this->pTop->searchForReference(coords);//search top
				if (value != NULL)//if coords found
				{
					return value;
				}
			}
			if (this->pBottom != NULL && this->pBottom->searchedForReference == false)
			{
				value = this->pBottom->searchForReference(coords);//search top
				if (value != NULL)//if coords found
				{
					return value;
				}
			}
			if (this->pLeft != NULL && this->pLeft->searchedForReference == false)
			{
				value = this->pLeft->searchForReference(coords);//search top
				if (value != NULL)//if coords found
				{
					return value;
				}
			}
			if (this->pRight != NULL && this->pRight->searchedForReference == false)
			{
				value = this->pRight->searchForReference(coords);//search top
				if (value != NULL)//if coords found
				{
					return value;
				}
			}
			return value;
		}
	}
	void endSearch() {
		this->searchedForReference = false;

		if (this->pTop != NULL && this->pTop->searchedForReference == true)//if you can search top
		{
			this->pTop->searchedForReference = false;
			this->pTop->endSearch();
		}
		if (this->pBottom != NULL && this->pBottom->searchedForReference == true)//if you can search top
		{
			this->pBottom->searchedForReference = false;
			this->pBottom->endSearch();
		}
		if (this->pLeft != NULL && this->pLeft->searchedForReference == true)//if you can search top
		{
			this->pLeft->searchedForReference = false;
			this->pLeft->endSearch();
		}
		if (this->pRight != NULL && this->pRight->searchedForReference == true)//if you can search top
		{
			this->pRight->searchedForReference = false;
			this->pRight->endSearch();
		}
	}

private:
	bool explored;
	bool displayed;
	bool searchedForReference;
	int floorType; //{Dirt, Grass, Wood, Stone};//4
	int roomType; //{Trap, Monster, Chest, Empty, Hostage, Healing};//6
	//std::vector<std::string> dropped;
	std::vector<std::string> decorations;
	Room* pLeft;
	Room* pTop;
	Room* pRight;
	Room* pBottom;
	std::vector<std::string> players;
	sf::Vector2i originOffset;
};


class Character{

public:
	Character() {
		location = NULL;
		stats = { 10,10,5,5,5,5 };
		weapon = potion = follower = name = "";
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
	void setFile(sf::Texture newFile) {
		file = newFile;
	}
	void setTopFile(sf::Texture newTopFile) {
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
	sf::Texture getFile() {
		return file;
	}
	sf::Texture getTopFile() {
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
		float scaleF = window.getSize().y / 32 / 18;
		float offset = scaleF, hMid = window.getSize().x/2 - offset, vMid = window.getSize().y/2 - offset;

		sf::Texture fog;
		fog.loadFromFile("FogCorners.png", sf::IntRect(32, 32, 32, 32));
		fog.setRepeated(true);
		sf::Sprite fogback(fog, sf::IntRect(32, 32, window.getSize().x, window.getSize().y));
		sf::Sprite character(this->topFile);
		character.setScale(scaleF,scaleF);
		fogback.setScale(scaleF, scaleF);
		fogback.setPosition(0,0);

		window.draw(fogback);
		if (location != NULL)
		{
			location->draw(window.getSize().x/2 - window.getSize().y/18*3, window.getSize().y / 2 - window.getSize().y / 18 * 3, window);
		}
		character.setPosition(window.getSize().x/2 - window.getSize().y / 18/2 , window.getSize().y / 2 - window.getSize().y / 18/2);
		window.draw(character);
	}
private:
	Room* location;
	Stats stats;
	std::string weapon;
	std::string potion;
	std::string follower;
	sf::Texture file;
	sf::Texture topFile;
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
void play(sf::RenderWindow &window, Character &player);
std::string characterNaming(sf::RenderWindow &window, bool &moreCharacters);