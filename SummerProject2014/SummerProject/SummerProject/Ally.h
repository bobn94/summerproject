#pragma once
#include "stdafx.h"
#include "CharacterObject.h"

class Ally : CharacterObject{
public:
	Ally();
	Ally(int speed, int armorValue, int strength, int level, sf::String name);
	Ally(int speed, int armorValue, int strength, int level, sf::String name, bool isShop);
	bool AddDialog(sf::String line);
	sf::String GetLine(int line);

private:
	bool m_isShop;
	sf::String m_dialog[20];
};