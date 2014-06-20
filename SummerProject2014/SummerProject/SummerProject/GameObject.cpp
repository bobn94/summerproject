#pragma once
#include "GameObject.h"

GameObject::GameObject(){
	m_level = 1;
	m_name = "Something is wrong";
}
GameObject::GameObject(sf::String name, int level){
	m_level = level;
	m_name = name;
}
void GameObject::SetName(sf::String name){
	m_name = name;
}
void GameObject::SetLevel(int level){
	m_level = level;
}
sf::String GameObject::GetName(){
	return m_name;
}
int GameObject::GetLevel(){
	return m_level;
}
	void GameObject::SetSprite(sf::Sprite sprite){
		m_sprite = sprite;
	}
	sf::Sprite GameObject::GetSprite(){
		return m_sprite;
	}