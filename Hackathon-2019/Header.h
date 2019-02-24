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

int miniGameRangedAttack(std::string projectileImage, sf::RenderWindow &window, double difficulty);
int miniGameKeyPuzzle(sf::RenderWindow &window, double difficulty);
