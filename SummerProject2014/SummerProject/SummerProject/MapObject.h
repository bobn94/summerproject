#pragma once
#include "stdafx.h"
#include "GameObject.h"

class MapObject : public GameObject{
public:
	MapObject();
	MapObject(sf::String name, int level, sf::Vector2f position, sf::Vector2f extention);
private:

};