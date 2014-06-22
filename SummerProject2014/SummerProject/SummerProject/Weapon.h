#pragma once
#include "stdafx.h"
#include "Item.h"

class Weapon : Item{
public:
	Weapon();
	Weapon(sf::String name, int level, sf::String description, int value, int range, float hitChanse, int weaponType, int speed);
	void SetRange(int range);
	void SetHitChanse(float hitChanse);
	void SetWeaponType(int weaponType);
	void SetSpeed(int speed);
	int GetRange();
	float GetHitChanse();
	int GetWeaponType();
	int GetSpeed();
private:
	int m_range;
	float m_hitChanse;
	int m_weaponType;
	int m_speed;
};