#pragma once
#include "stdafx.h"
#include "ItemGenerator.h"
#include <string>
#include <sstream>

	ItemGenerator::ItemGenerator(){
		ItemNameFilePathFirst = "";
		randomArmorNames[0] = " of Defence";
		randomArmorNames[1] = " of the Bear";
		randomArmorNames[2] = " of the Turtle";
		randomArmorNames[3] = " of Madness";
		randomArmorNames[4] = " of the Boar";
		randomArmorNames[5] = " of the Mountain";
		randomArmorNames[6] = " of Sturdyness";
		randomArmorNames[7] = " of the Rhino";
		randomArmorNames[8] = " of the Departed";
		randomArmorNames[9] = " of Infernal Strength";

		randomWeaponNames[0] = " of WABBAJACKS!!!";
		randomWeaponNames[1] = " of the Lost Soul";
		randomWeaponNames[2] = " of the Blazing Demon";
		randomWeaponNames[3] = " of Bizarre Horrors";
		randomWeaponNames[4] = " of Fluffyness";
		randomWeaponNames[5] = " of the Lion";
		randomWeaponNames[6] = " of the Monkey";
		randomWeaponNames[7] = " of the Ancient Hero";
		randomWeaponNames[8] = " of Mystic Origin";
		randomWeaponNames[9] = " of Madness";

	}
	void ItemGenerator::SetFilePaths(sf::String FirstPath){
		ItemNameFilePathFirst = FirstPath;
	}
	sf::String ItemGenerator::GetFirstPath(){
		return ItemNameFilePathFirst;
	}
	Armor ItemGenerator::GenerateNewArmor(PlayerObject player){
		int one = rand() % 2 + 1;
		int two = rand() % 4 + 1;
		int three = rand() % 7;
		int four = rand() % 10;
		armorType = rand() % 5;
		armorValue = (player.GetLevel() * one) + (armorType * two);
		speedDec = armorValue * (armorType / 2) - 10;
		armorSlot = rand() % 4;
		sf::String pre = "";

		if(one == 2){
			pre = "Superior ";
		}

		sf::String First;
		if(armorType == 0){
			First = "Cloth ";
		}
		else if(armorType == 1){
			First == "Leather ";
		}
		else if(armorType == 2){
			First == "Mail ";
		}
		else if(armorType == 3){
			First == "Plate ";
		}
		else{
			First == "Shield ";
		}

		sf::String Second;

		if(armorSlot == 0){
			Second = "Helmet";
		}
		else if(armorSlot == 1){
			Second = "Gloves";
		}
		else if(armorSlot == 2){
			Second = "Leggings";
		}
		else{
			Second = "Boots";
		}
		sf::String Last = randomArmorNames[four];
		name = pre + First + Second + Last;
		level = armorValue / 10;
		std::stringstream derp;
		derp << armorValue;
		std::string res;
		res = derp.str();
		description = "The " + name + " is a good armor, that any hero should treasure highly." + '\n' + "The piece gives " + res + " armor points.";
		speedDec = 100 - armorValue % 100 + 1;
		value = armorValue - speedDec + 10;
		return Armor(name, level, description, value, armorType, armorValue, speedDec, armorSlot, sf::Vector2f(0.0,0.0), sf::Vector2f(0.0, 0.0));
	}
	Weapon ItemGenerator::GenerateNewWeapon(PlayerObject player){
		int one = rand() % 30 + 11;
		int two = rand() % 2 + 1;
		int three = rand() % 8;
		int four = rand() % 10;
		range = 0;
		hitChanse = one + player.GetLevel() * two;
		weaponType = three;
		speed = player.GetLevel() * (2 - player.GetLevel() / 3);
		sf::String First = "";
		sf::String Second;
		sf::String Third;
		if(two == 2){
			First = "Superior ";
		}
		if(weaponType == 0){
			Second = "One Handed Sword";
		}
		else if(weaponType == 1){
			Second = "Two Handed Sword";
		}
		else if(weaponType == 2){
			Second = "One Handed Axe";
		}
		else if(weaponType == 3){
			Second = "Two Handed Axe";
		}
		else if(weaponType == 4){
			Second = "One Handed Mace";
		}
		else if(weaponType == 5){
			Second = "Two Handed Mace";
		}
		else if(weaponType == 6){
			Second = "Spear";
		}
		else if(weaponType == 7){
			Second = "Staff";
		}
		else if(weaponType == 8){
			Second = "Bow";
		}

		Third = randomWeaponNames[four];
		

		name = First + Second + Third;
		std::stringstream derp;
		derp << speed;
		std::string res;
		description = "The " + name + " is a good weapon, that any hero should treasure highly." + '\n' + "The weapon has a speed rating of " + res + ".";;
		value = speed + player.GetLevel() * 3 + 18;
		return Weapon(name, level, description, armorValue, range, hitChanse, weaponType, speed, sf::Vector2f(0.0, 0.0), sf::Vector2f(0.0, 0.0));
	}