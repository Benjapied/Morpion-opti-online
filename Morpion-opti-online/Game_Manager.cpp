
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game_Manager.h"
#include "Event_Manager.h"
#include "Player.h"
#include "Case.h"

Game_Manager::Game_Manager() {
	this->Init_grid();

};

void Game_Manager::Init_grid() {
	//Définition des éléments de ma grille
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m_grid[i][j] = new Case('o',sf::Vector2f(1920*(j+3)/9,1080*(i + 1)/5));
		}
	}

	//Définition des traits constituants la grille de jeu
	m_graphicGrid.push_back(new sf::RectangleShape(sf::Vector2f(5, 1080 * 3 / 5)));
	m_graphicGrid[0]->setPosition(float(1920 * 4 / 9), float(1080 * 1 / 5));
	m_graphicGrid.push_back(new sf::RectangleShape(sf::Vector2f(5, 1080 * 3 / 5)));
	m_graphicGrid[1]->setPosition(float(1920 * 5 / 9), float(1080 * 1 / 5));
	m_graphicGrid.push_back(new sf::RectangleShape(sf::Vector2f(1920/3, 5)));
	m_graphicGrid[2]->setPosition(float(1920 * 3 / 9), float(1080 * 2 / 5));
	m_graphicGrid.push_back(new sf::RectangleShape(sf::Vector2f(1920/3, 5)));
	m_graphicGrid[3]->setPosition(float(1920 * 3 / 9), float(1080 * 3 / 5));

};

void Game_Manager::Draw(sf::RenderWindow* window) {
	
	window->clear();
	this->print_grid(window);
	window->display();
};

void Game_Manager::print_grid(sf::RenderWindow* window) {
	for (int i = 0; i < m_graphicGrid.size(); i++) {
		window->draw(*m_graphicGrid[i]);
	}

	for (int i = 0; i < m_grid.size(); i++) {
		for (int j = 0; j < m_grid.size(); j++) {
			if (m_grid[i][j]->m_form != (nullptr)) {
				window->draw(*(m_grid[i][j]->m_form));
			}
		}
	}
}

void Game_Manager::gameLoop(sf::RenderWindow* window) {

	sf::Event event;
	Event_Manager* oEvent_Manager = new Event_Manager();

	Player* oPlayer1 = new Player('c');
	Player* oPlayer2 = new Player('r');

	Player* current_player = oPlayer1;

	int round = 0;

	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		//Placement de signe 
		if (oEvent_Manager->isClick(event) == true) {
			if (this->placeSign(oEvent_Manager->get_pos(window), current_player->m_cSign)) {

				//Actions à effectuer à chaque round du jeu 

				this->print__tab();

				round++;

				if (this->isWin(current_player->m_cSign)) {
					std::cout << current_player->m_cSign << " wins" << std::endl;
					break;
				}

				if (round == 9) {
					std::cout << " Tie " << std::endl;
					break;
				}

				if (current_player == oPlayer2) { current_player = oPlayer1; }
				else if (current_player == oPlayer1) { current_player = oPlayer2; };
			};
		};

		//Draw
		this->Draw(window);
	}

}

bool Game_Manager::placeSign(sf::Vector2i coo, char sign) {
	//Renvoie true si le signe s'est placé
	int x = floor(coo.x * 5 /1080);
	int y = floor(coo.y * 9 / 1920) ;

	if (x > 6 || x < 3 || y > 3 || y < 1) {
		return false;
	};

	y--;
	x -= 3;

	if (m_grid[y][x]->m_value != 'o') { return false; };

	m_grid[y][x]->m_value = sign;

	m_grid[y][x]->SetForme(sign);
	return true;
}

void Game_Manager::print__tab() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << m_grid[i][j]->m_value;
		}
		std::cout << std::endl;
	};
	std::cout << std::endl;
}

bool Game_Manager::isWin(char current_sign) {
	for (int i = 0; i < 3; i++) {
		if (m_grid[i][0]->m_value == current_sign && m_grid[i][1]->m_value == current_sign && m_grid[i][2]->m_value == current_sign) {
			return true;
		}
	};
	for (int i = 0; i < 3; i++) {
		if (m_grid[0][i]->m_value == current_sign && m_grid[1][i]->m_value == current_sign && m_grid[2][i]->m_value == current_sign) {
			return true;
		}
	};
	if (m_grid[0][0]->m_value == current_sign && m_grid[1][1]->m_value == current_sign && m_grid[2][2]->m_value == current_sign) {
		return true;
	}
	if (m_grid[2][0]->m_value == current_sign && m_grid[1][1]->m_value == current_sign && m_grid[0][2]->m_value == current_sign) {
		return true;
	}
	return false;
}