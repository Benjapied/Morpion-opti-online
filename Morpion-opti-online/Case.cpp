#include "Case.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

Case::Case(char value, sf::Vector2f coo) {
	m_value = value;
	m_coo = coo;
	m_form = nullptr;
}

void Case::SetForme(char sign)
{
	if (sign == 'r') {
		m_form = new sf::CircleShape(1080/10 - 20);
		m_form->setPosition(m_coo.x + 20, m_coo.y + 20);
		m_form->setFillColor(sf::Color(255, 0, 0));
	}else if(sign == 'c') {
		m_form = new sf::RectangleShape(sf::Vector2f(2160 / 10 - 20,2160 / 10 - 20));
		m_form->setPosition(m_coo.x + 10, m_coo.y + 10);
		m_form->setFillColor(sf::Color(0, 255, 0));
	};
};
