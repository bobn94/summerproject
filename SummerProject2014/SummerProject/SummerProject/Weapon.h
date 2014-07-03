#pragma once
#include "stdafx.h"
#include "Item.h"

enum WeaponTypes
{
	OneHandedSword,
	TwoHandedSword,
	OneHandedAxe,
	TwoHandedAxe,
	OneHandedMace,
	TwoHandedMace,
	Spear,
	Staff,
	Bow
};

class Weapon : public Item{
public:
	Weapon();
	Weapon(sf::String name, int level, sf::String description, int value, int range, float hitChanse, int weaponType, int speed, sf::Vector2f position, sf::Vector2f extention);
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