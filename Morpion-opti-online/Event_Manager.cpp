#include "Event_Manager.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics.hpp>


Event_Manager::Event_Manager() {

}

sf::Vector2i Event_Manager::get_pos(sf::RenderWindow* window) {

	return sf::Mouse::getPosition(*window);
};

bool Event_Manager::isClick(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            return true;
        }
    }
    return false;
};