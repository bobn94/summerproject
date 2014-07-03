#pragma once
#include "stdafx.h"
#include "Armor.h"
#include "Weapon.h"
#include "PlayerObject.h"

class ItemGenerator{
public:
	ItemGenerator();
	void SetFilePaths(sf::String FirstPath);
	sf::String GetFirstPath();
	Armor GenerateNewArmor(PlayerObject player);
	Weapon GenerateNewWeapon(PlayerObject player);
private:
	sf::String randomArmorNames[10];
	sf::String randomWeaponNames[10];
	sf::String name;
	int level;
	sf::String description;
	int value;
	int armorType;
	int armorValue;
	int armorSlot;
	int speedDec;
	int range;
	float hitChanse;
	int weaponType;
	int speed;
	sf::String ItemNameFilePathFirst;
};