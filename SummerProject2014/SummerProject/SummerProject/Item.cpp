#pragma once
#include "stdafx.h"
#include "Item.h"


Item::Item() : GameObject(){
	m_value = 0;
	m_description = "Your mind is too simple to comprehend this item, or the game broke. Might be a mix of both.";
}
Item::Item(sf::String name, int level, sf::String description, int value, sf::Vector2f position, sf::Vector2f extention) : GameObject(name, level, position, extention){
	m_description = description;
	m_value = value;
}
void Item::SetDescription(sf::String description){
	m_description = description;
}
void Item::SetValue(int value){
	m_value = value;
}
sf::String Item::GetDescription(){
	return m_description;
}
int Item::GetValue(){
	return m_value;
}