#pragma once
#include "stdafx.h"
#include "CharacterObject.h"

class Ally : public CharacterObject{
public:
	Ally();
	Ally(int speed, int armorValue, int strength, int level, sf::String name, sf::Vector2f position, sf::Vector2f extention);
	Ally(int speed, int armorValue, int strength, int level, sf::String name, bool isShop, sf::Vector2f position, sf::Vector2f extention);
	bool AddDialog(sf::String line);
	sf::String GetLine(int line);

private:
	bool m_isShop;
	sf::String m_dialog[20];
};