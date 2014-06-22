#pragma once
#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(){
	m_range = 0;
	m_hitChanse = 0;
	m_weaponType = 0;
	m_speed = 0;
}
Weapon::Weapon(sf::String name, int level, sf::String description, int value, int range, float hitChanse, int weaponType, int speed) : Item(name, level, description, value){
	m_range = range;
	m_hitChanse = hitChanse;
	m_weaponType = weaponType;
	m_speed = speed;
}
void Weapon::SetRange(int range){
	m_range = range;
}
void Weapon::SetHitChanse(float hitChanse){
	m_hitChanse = hitChanse;
}
void Weapon::SetWeaponType(int weaponType){
	m_weaponType = weaponType;
}
void Weapon::SetSpeed(int speed){
	m_speed = speed;
}
int Weapon::GetRange(){
	return m_range;
}
float Weapon::GetHitChanse(){
	return m_hitChanse;
}
int Weapon::GetWeaponType(){
	return m_weaponType;
}
int Weapon::GetSpeed(){
	return m_speed;
}