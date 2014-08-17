#pragma once
#include "stdafx.h"
#include "GameObject.h"

class CharacterObject : public GameObject{
	
public:
	CharacterObject();
	CharacterObject(float speed, float armorValue, float strength, int level, sf::String name, sf::Vector2f position, sf::Vector2f extention);
	void SetSkillLevel(int weapon, int level);
	void SetSpeed(float speed);
	void SetArmorValue(float armor);
	void SetEquiped(int slot, int *item);
	void SetStrenght(float strength);
	float GetSpeed();
	float GetArmorValue();
	float GetStrenght();
	int GetSkillLevel(int Weapon);
	int* GetEquiped(int slot);

private:
	float m_speed;
	float m_armorValue;
	float m_strength;
	int m_weaponSkillLevel[8];
	int* m_equiped[7];
};