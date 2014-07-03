#pragma once
#include "stdafx.h"
#include "CharacterObject.h"
#include "Skills.h"

class Enemy : public CharacterObject{
public:
	Enemy();
	Enemy(int speed, int armorValue, int strength, int level, sf::String name, sf::Vector2f position, sf::Vector2f extention);
	Enemy(int speed, int armorValue, int strength, int level, sf::String name, Skills* skill, sf::Vector2f position, sf::Vector2f extention);
	void SetSkill(Skills* skill);
	Skills* GetSkill();
	bool AddDialog(sf::String line);
	sf::String GetLine(int line);
private:
	bool m_inCombat;
	Skills* m_skill;
	sf::String m_dialog[5];
};