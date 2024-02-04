#include <SFML/Graphics.hpp>
#include "Game_Manager.h"
#include <iostream>
#include "Player.h"

int main()
{
    Game_Manager* game_manager = new Game_Manager();

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

	std::string name1;
	std::string name2;

	std::cout << "Quel est votre nom joueur 1 ? : ";
	std::cin >> name1;

	std::cout << std::endl;

	std::cout << "Quel est votre nom joueur 2 ? : ";
	std::cin >> name2;

	Player* oPlayer1 = new Player('c', name1);
	Player* oPlayer2 = new Player('r', name2);

    game_manager->gameLoop(&window, oPlayer1, oPlayer2);

    return 0;
}
