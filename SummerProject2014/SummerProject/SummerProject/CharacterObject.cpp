#pragma once
#include "stdafx.h"
#include "CharacterObject.h"

CharacterObject::CharacterObject() : GameObject(){
		
	}
CharacterObject::CharacterObject(int speed, int armorValue, int strength, int level, sf::String name) : GameObject(name, level){
		m_speed = speed;
		m_armorValue = armorValue;
		m_strength = strength;
		for(int i = 0; i < 8; i++){
			m_skillLevel[i] = 1;
		}
		for(int i = 0; i < 7; i++){
			m_equiped[i] = 0;
		}
	}
	void CharacterObject::SetSkillLevel(int weapon, int level){
		m_skillLevel[weapon] = level;
	}
	void CharacterObject::SetSpeed(int speed){
		m_speed = speed;
	}
	void CharacterObject::SetArmorValue(int armor){
		m_armorValue = armor;
	}
	void CharacterObject::SetEquiped(int slot, int *item){
		m_equiped[slot] = item;
	}
	void CharacterObject::strenght(int strength){
		m_strength = strength;
	}
	int CharacterObject::GetSpeed(){
		return m_speed;
	}
	int CharacterObject::GetArmorValue(){
		return m_armorValue;
	}
	int CharacterObject::GetStrenght(){
		return m_strength;
	}
	int CharacterObject::GetSkillLevel(int Weapon){
		return m_skillLevel[Weapon];
	}
	int *CharacterObject::GetEquiped(int slot){
		return m_equiped[slot];
	}