#include "Header.h"


 int main()
{
	 //initialize values

	 //initialize randomization
	 srand(time(NULL));
	
	 //create window
	 sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getFullscreenModes().at(0)), "SFML Window", sf::Style::Fullscreen);//set resolution to highest availiable to user, and open as fullscreen
	 //window.create(sf::VideoMode(window.getSize().x / 2.0, window.getSize().y, 2), "SFML Window", sf::Style::Default);//uncomment to test vertical orientation
	 window.setFramerateLimit(60);//set framerate cap of 60 fps
	 window.setVerticalSyncEnabled(true);//enforce vertical sync(disable screen tearing and artifacts)

	 mainMenu(window);//open main menu

	return 0;
}