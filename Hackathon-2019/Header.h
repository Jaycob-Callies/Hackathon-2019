#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>
#include <ctime>

int miniGameRangedAttack(sf::Image projectileImage, sf::RenderWindow &window, double difficulty);
int miniGameKeyPuzzle(sf::RenderWindow &window, double difficulty)
