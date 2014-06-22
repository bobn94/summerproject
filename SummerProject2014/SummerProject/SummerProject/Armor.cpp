#pragma once
#include "stdafx.h"
#include "Armor.h"

Armor::Armor() : Item(){
	m_armorType = 0;
	m_armorValue = 0;
	m_speedDecrease = 0;
}
Armor::Armor(sf::String name, int level, sf::String description, int value, int armorType, int armorValue, int speedDec) : Item(name, level, description, value){
	m_armorType = armorType;
	m_armorValue = armorValue;
	m_speedDecrease = speedDec;
}
void Armor::SetArmorType(int armorType){
	m_armorType = armorType;
}
void Armor::SetArmorValue(int armorValue){
	m_armorValue = armorValue;
}
void Armor::SetSpeedDecrease(int speed){
	m_speedDecrease = speed;
}
int Armor::GetArmorType(){
	return m_armorType;
}
int Armor::GetArmorValue(){
	return m_armorValue;
}
int Armor::GetSpeedDecrease(){
	return m_speedDecrease;
}