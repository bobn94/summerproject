#pragma once
#include "stdafx.h"
#include "Enemy.h"

class PlayerObject;
class SkeletonWarrior : public Enemy
{
public:
	SkeletonWarrior();
	SkeletonWarrior(float speed, float armorValue, float strength, int level, sf::String name, sf::Vector2f position, sf::Vector2f extention);
	SkeletonWarrior(float speed, float armorValue, float strength, int level, sf::String name, Skills* skill, sf::Vector2f position, sf::Vector2f extention);
	
private:

};