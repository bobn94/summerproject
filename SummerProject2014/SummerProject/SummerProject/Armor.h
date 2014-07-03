#pragma once
#include "stdafx.h"
#include "Item.h"

enum ArmorSlots
{
	Head,
	Hands,
	Legs,
	Feet
};
enum ArmorTypes
{
	Cloth,
	Leather,
	Mail,
	Plate,
	Shield
};

class Armor : public Item{
public:
	Armor();
	Armor(sf::String name, int level, sf::String description, int value, int armorType, int armorValue, int speedDec, int armorSlot, sf::Vector2f position, sf::Vector2f extention);
	void SetArmorType(int armorType);
	void SetArmorValue(int armorValue);
	void SetSpeedDecrease(int speed);
	int GetArmorType();
	int GetArmorValue();
	int GetSpeedDecrease();
private:
	int m_armorType;
	int m_armorSlot;
	int m_armorValue;
	int m_speedDecrease;
};