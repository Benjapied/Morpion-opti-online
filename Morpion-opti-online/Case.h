#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Case
{
public:
	char m_value;
	sf::Shape* m_form;
	sf::Vector2f m_coo;

	Case(char value, sf::Vector2f coo);

	void SetForme(char sign);
};

