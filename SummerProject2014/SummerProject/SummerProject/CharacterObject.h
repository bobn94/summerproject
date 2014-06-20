#pragma once
#include "stdafx.h"
#include "GameObject.h"

class CharacterObject : GameObject{
	
public:
	CharacterObject();
	CharacterObject(int speed, int armorValue, int strength, int level, sf::String name);
	void SetSkillLevel(int weapon, int level);
	void SetSpeed(int speed);
	void SetArmorValue(int armor);
	void SetEquiped(int slot, int *item);
	void strenght(int strength);
	int GetSpeed();
	int GetArmorValue();
	int GetStrenght();
	int GetSkillLevel(int Weapon);
	int* GetEquiped(int slot);
private:
	int m_speed;
	int m_armorValue;
	int m_strength;
	int m_skillLevel[8];
	int* m_equiped[7];
};