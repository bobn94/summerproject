#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Item : public GameObject{
public:
	Item();
	Item(sf::String name, int level, sf::String description, int value, sf::Vector2f position, sf::Vector2f extention);
	void SetDescription(sf::String description);
	void SetValue(int value);
	sf::String GetDescription();
	int GetValue();
private:
	int m_value;
	sf::String m_description;
	
};