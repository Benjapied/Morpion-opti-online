#pragma once
#include <string>

class Player
{
public:

	std::string m_name;
	int m_iPoints;
	char m_cSign;

	Player(char sign, std::string name);
};

