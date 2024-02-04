#include <SFML/Graphics.hpp>
#include "Game_Manager.h"

int main()
{
    Game_Manager* game_manager = new Game_Manager();

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    game_manager->gameLoop(&window);

    return 0;
}
