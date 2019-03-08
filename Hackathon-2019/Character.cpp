#include "Header.h"


std::vector<Character> characterSelect(sf::RenderWindow &window)
{
	std::vector<Character> temp;
	int vMid = 0, hMid = 0; //Variable Declaration.
	float textureBitsX = 32.0, textureBitsY = 32.0, minTexturesPerAxis = 4.0, scaleF = 0.0, yOffset = 0.0, xOffset = 0.0;//32x32
	bool moreCharacters = true;
	std::string characterFile = "", characterTop = "";
	sf::Event event;
	sf::Mouse mouse;
	std::vector<sf::Sprite> characters;
	std::vector<sf::Texture> characterTextures;
	std::vector<sf::Texture> characterTopTextures;

	//set scaleF to scale needed in order to make a minTexturesPerScreenLength long square of tiles in the center of the screen
	if (window.getSize().x / textureBitsX > window.getSize().y / textureBitsY)//landscape view(horizontal longer than vertical)
	{
		scaleF = window.getSize().y / textureBitsY/ minTexturesPerAxis;
		xOffset = ((window.getSize().x - (textureBitsX * scaleF * minTexturesPerAxis)) / 2.0);
	}
	else//portrait view(horizontal narrower than vertical)
	{
		scaleF = window.getSize().x / textureBitsX/ minTexturesPerAxis;
		yOffset = ((window.getSize().y - (textureBitsY * scaleF * minTexturesPerAxis)) / 2.0);
	}

	//create vector of all characters
	for (int i = 0; i < 4; i++)//loop through all colours
	{
		for (int j = 0; j < 4; j++)//loop through all playertypes
		{
			//make a new blank filename
			characterFile = "";
			//add colour to filename
			switch (i)
			{
			case 1:
				characterFile = "Red";
				characterTop = "R";
				break;
			case 2:
				characterFile = "Blue";
				characterTop = "B";
				break;
			case 3:
				characterFile = "Green";
				characterTop = "G";
				break;
			default:
				characterFile = "Yellow";
				characterTop = "Y";
				break;
			}
			//add playertype to filename
			switch (j)
			{
			case 1:
				characterFile = characterFile + "Rogue.png";
				characterTop = characterTop + "RTop.png";
				break;
			case 2:
				characterFile = characterFile + "Mage.png";
				characterTop = characterTop + "MTop.png";
				break;
			case 3:
				characterFile = characterFile + "Bard.png";
				characterTop = characterTop + "BTop.png";
				break;
			default:
				characterFile = characterFile + "Warrior.png";
				characterTop = characterTop + "WTop.png";
				break;
			}
			characterTextures.push_back(*new(sf::Texture));
			characterTextures.at(characterTextures.size() - 1).loadFromFile(characterFile);
			characterTopTextures.push_back(*new(sf::Texture));
			characterTopTextures.at(characterTopTextures.size() - 1).loadFromFile(characterTop);
		}
	}

	//load default character texture
	sf::Texture characterTexture;

	//Load vector of all selectable sprites
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			characters.push_back(*new(sf::Sprite)(characterTextures.at(4 * i + j)));//push new character with loaded texture
			characters.at(characters.size() - 1).setScale(scaleF, scaleF);//set character scale
			characters.at(characters.size() - 1).setPosition(xOffset + scaleF * textureBitsX * (j), yOffset + scaleF * textureBitsY * (i));//move to appropriate position
		}
	}
	
	//main activity
	while (moreCharacters)
	{
		window.clear();//clear screen

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				for (int i = 0; i < 16; i++)//for each character
				{
					if (characters.at(i).getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))//if cursor over character
					{
						temp.push_back(*new(Character));//add new character
						temp.at(temp.size() - 1).setFile(characterTextures.at(i));//side texture
						temp.at(temp.size() - 1).setTopFile(characterTextures.at(i));//top texture
						temp.at(temp.size() - 1).setName(characterNaming(window, moreCharacters));//prompt for name
						//Add character as player
					}
				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
				for (int i = 0; i < 16; i++)//for each character
				{
					if (characters.at(i).getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))//if cursor over character
					{
						characters.at(i).setColor(sf::Color(255,255,255,60));//darken the character
					}
					else//if not selected
					{
						characters.at(i).setColor(sf::Color::White);//reset to default
					}
				}
			}
		}
		//draw all character selections
		for (int i = 0; i < 16; i++)
		{
			window.draw(characters.at(i));
		}
		window.display();//display screen
	}
	return temp;
}

std::string characterNaming(sf::RenderWindow &window, bool &moreCharacters) {
	sf::Font font;
	std::string str = "";
	std::string temp = "";
	sf::Event event;
	sf::Text textD;
	sf::Text prompt;
	bool aquiringName = true;
	sf::RectangleShape selectionBox;
	sf::RectangleShape disselectionBox;

	int vMid = 0, hMid = 0; //Variable Declaration.
	float textureBitsX = 32.0, textureBitsY = 32.0, minTexturesPerAxis = 20.0, scaleF = 0.0, yOffset = 0.0, xOffset = 0.0;//32x32
	textureBitsX = textureBitsY = prompt.getCharacterSize();
	//set scaleF to scale needed in order to make a minTexturesPerScreenLength long square of tiles in the center of the screen
	if (window.getSize().x / textureBitsX > window.getSize().y / textureBitsY)//landscape view(horizontal longer than vertical)
	{
		scaleF = window.getSize().y / textureBitsY / minTexturesPerAxis;
		xOffset = ((window.getSize().x - (textureBitsX * scaleF * minTexturesPerAxis)) / 2.0);
	}
	else//portrait view(horizontal narrower than vertical)
	{
		scaleF = window.getSize().x / textureBitsX / minTexturesPerAxis;
		yOffset = ((window.getSize().y - (textureBitsY * scaleF * minTexturesPerAxis)) / 2.0);
	}

	font.loadFromFile("8bit.ttf");
	textD.setFont(font);
	textD.setFillColor(sf::Color::White);
	textD.setString(str);
	textD.setScale(scaleF, scaleF);
	prompt.setFont(font);
	prompt.setFillColor(sf::Color::White);
	prompt.setString("Enter Character Name:");
	prompt.setPosition(xOffset, yOffset);
	prompt.setScale(scaleF, scaleF);
	
	while (aquiringName)
	{
		window.clear();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)//backspace
				{	
					if (str.size() >= 1)//if characters left to delete
					{
						temp = "";
						for (int i = 0; i < str.size() - 1; i++)
						{
							temp += str.at(i);
						}
						str = temp;
						textD.setString(str);
					}
				}
				else if (event.text.unicode == 13)
				{
					//ask for more characters
					aquiringName = false;
				}
				// Handle ASCII characters only
				else if (event.text.unicode < 128)
				{
					str += static_cast<char>(event.text.unicode);
					textD.setString(str);
					//set scaleF to scale needed in order to make a minTexturesPerScreenLength long square of tiles in the center of the screen
					if (window.getSize().x / textureBitsX > window.getSize().y / textureBitsY)//landscape view(horizontal longer than vertical)
					{
						scaleF = window.getSize().y / textureBitsY / minTexturesPerAxis;
						xOffset = ((window.getSize().x - (textureBitsX * scaleF * minTexturesPerAxis)) / 2.0);
					}
					else//portrait view(horizontal narrower than vertical)
					{
						scaleF = window.getSize().x / textureBitsX / minTexturesPerAxis;
						yOffset = ((window.getSize().y - (textureBitsY * scaleF * minTexturesPerAxis)) / 2.0);
					}
					textD.setScale(scaleF,scaleF);
					prompt.setScale(scaleF, scaleF);
					textD.setPosition(xOffset, yOffset+scaleF*textureBitsY);
				}
			}
		}
		window.draw(prompt);
		window.draw(textD);
		window.display();
	}

	prompt.setString("Add another Character?");

	selectionBox.setSize(sf::Vector2f(window.getSize().x / 2, window.getSize().y));
	selectionBox.setPosition(0, textureBitsY * scaleF);
	disselectionBox.setSize(sf::Vector2f(window.getSize().x / 2, window.getSize().y));
	disselectionBox.setPosition(window.getSize().x / 2, textureBitsY * scaleF);
	selectionBox.setFillColor(sf::Color(0, 0, 0, 0));
	disselectionBox.setFillColor(sf::Color(0, 0, 0, 0));

	while (1)
	{
		window.clear();//clear screen
		window.draw(prompt);

		textD.setString("Yes");
		textD.setPosition(selectionBox.getPosition().x + selectionBox.getSize().x / 2 - 1.5 * scaleF * textureBitsX, selectionBox.getPosition().y + selectionBox.getSize().y / 2 - .5 * scaleF * textureBitsY);
		window.draw(textD);
		textD.setString("No");
		textD.setPosition(disselectionBox.getPosition().x + disselectionBox.getSize().x / 2 - 1.0 * scaleF * textureBitsX, disselectionBox.getPosition().y + disselectionBox.getSize().y / 2 - .5 * scaleF * textureBitsY);
		window.draw(textD);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (selectionBox.getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))//if cursor over character
				{
					moreCharacters = true;
					for (int i = 0; i < 5; i++)
					{
						window.draw(prompt);
						window.display();
					}
					return str;
				}
				else if (disselectionBox.getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))//if not selected
				{
					moreCharacters = false;
					return str;
				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
					if (selectionBox.getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))//if cursor over character
					{
						selectionBox.setFillColor(sf::Color(0, 0, 0, 80));
						disselectionBox.setFillColor(sf::Color(0, 0, 0, 0));
					}
					else if (disselectionBox.getGlobalBounds().contains(sf::Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))//if not selected
					{
						disselectionBox.setFillColor(sf::Color(0, 0, 0, 80));
						selectionBox.setFillColor(sf::Color(0, 0, 0, 0));
					}
					else
					{
						selectionBox.setFillColor(sf::Color(0, 0, 0, 0));
						disselectionBox.setFillColor(sf::Color(0, 0, 0, 0));
					}
			}
		}
		//draw all character selections
		window.draw(selectionBox);
		window.draw(disselectionBox);
		window.display();//display screen
	}
}

