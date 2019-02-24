#include "Header.h"


 int main()
{
	 //initialize values

	 //initialize randomization
	 srand(time(NULL));
	
	 //create fullscreen window size of users screen
	 sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	 window.create(sf::VideoMode(sf::VideoMode::getFullscreenModes().at(0)), "SFML Window", sf::Style::Fullscreen);
	 window.setFramerateLimit(65);

	 mainMenu(window);

	return 0;
}