#include "Player.h"
#include <string>

Player::Player(char sign,std::string name) {
	m_name = name;
	m_iPoints = 0;
	m_cSign = sign;
};