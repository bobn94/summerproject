#pragma once
#include "stdafx.h"

class GameObject
{
public:
	GameObject();
	GameObject(sf::String name, int level);
	void SetName(sf::String name);
	void SetLevel(int level);
	void SetSprite(sf::Sprite sprite);
	sf::Sprite GetSprite();
	sf::String GetName();
	int GetLevel();
private:
	sf::String m_name;
	int m_level;
	sf::Sprite m_sprite;
};