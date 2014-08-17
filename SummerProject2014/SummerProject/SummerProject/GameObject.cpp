#pragma once
#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(){
	m_level = 1;
	m_name = "Something is wrong";
	m_position.x = 0;
	m_position.y = 0;
	m_extention = m_position;
	m_center = m_extention;
	m_collider.m_extention = m_extention;
	m_collider.m_position = m_position;
}
GameObject::GameObject(sf::String name, int level, sf::Vector2f position, sf::Vector2f extention){
	m_level = level;
	m_name = name;
	m_position = position;
	m_extention = extention;
	m_center.x = m_position.x + m_extention.x / 2;
	m_center.y = m_position.y + m_extention.y / 2;
	m_collider.m_extention = m_extention;
	m_collider.m_position = m_position;
}
void GameObject::SetName(sf::String name){
	m_name = name;
}
void GameObject::SetLevel(int level){
	m_level = level;
}
void GameObject::Draw(sf::RenderWindow* window){
	window->draw(GetSprite());
}
sf::String GameObject::GetName(){
	return m_name;
}
int GameObject::GetLevel(){
	return m_level;
}
void GameObject::SetSprite(sf::Sprite sprite){
	m_sprite = sprite;
	m_sprite.setPosition(m_position.x, m_position.y);
	
}
void GameObject::SetPosition(sf::Vector2f pos){
	m_position = pos;
	if(m_sprite.getTexture() != nullptr){
		m_sprite.setPosition(m_position.x, m_position.y);
	}
	m_collider.m_position = m_position;
}
sf::Sprite GameObject::GetSprite(){
	return m_sprite;
}
Collider GameObject::GetCollider(){
	return m_collider;
}
sf::Vector2f GameObject::GetPosition(){
	return m_position;
}