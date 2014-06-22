#pragma once
#include "stdafx.h"
#include "Item.h"

class Armor : Item{
public:
	Armor();
	Armor(sf::String name, int level, sf::String description, int value, int armorType, int armorValue, int speedDec);
	void SetArmorType(int armorType);
	void SetArmorValue(int armorValue);
	void SetSpeedDecrease(int speed);
	int GetArmorType();
	int GetArmorValue();
	int GetSpeedDecrease();
private:
	int m_armorType;
	int m_armorValue;
	int m_speedDecrease;
};