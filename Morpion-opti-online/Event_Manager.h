#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

namespace sf {
	class Event;
	class RenderWindow;
}

class Event_Manager
{
public:

	Event_Manager();

	sf::Vector2i get_pos(sf::RenderWindow* window);

	bool isClick(sf::Event event);

};

