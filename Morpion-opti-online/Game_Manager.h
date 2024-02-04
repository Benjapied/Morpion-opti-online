#pragma once
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Case.h"

namespace sf {
	class RectangleShape;
	class RenderWindow;
};

class Player;

class Game_Manager
{
public:
	std::vector <std::vector<Case*>> m_grid = { {nullptr,nullptr,nullptr },{nullptr,nullptr,nullptr },{nullptr,nullptr,nullptr } };
	std::vector <sf::RectangleShape*> m_graphicGrid;

	Game_Manager();

	void Init_grid();

	void Draw(sf::RenderWindow* window);

	void print_grid(sf::RenderWindow* window);

	void gameLoop(sf::RenderWindow* window, Player* oPlayer1, Player* oPlayer2);

	bool placeSign(sf::Vector2i coo, char sign);

	void print__tab();

	bool isWin(char current_sign);
};

