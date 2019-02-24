#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace sf;

//int miniGameRangedAttack(sf::Image projectileImage, sf::RenderWindow &window, double difficulty);
int miniGameDodgeAttack(RenderWindow &window);