#pragma once
#include "stdafx.h"
#include "Collider.h"

class GameObject
{
public:
	GameObject();
	GameObject(sf::String name, int level, sf::Vector2f position, sf::Vector2f extention);
	void SetName(sf::String name);
	void SetLevel(int level);
	void SetSprite(sf::Sprite sprite);
	void Draw(sf::RenderWindow* window);
	void SetPosition(sf::Vector2f pos);
	sf::Vector2f GetPosition();
	Collider GetCollider();
	sf::Sprite GetSprite();
	sf::String GetName();
	int GetLevel();
private:
	sf::Vector2f m_position;
	sf::Vector2f m_extention;
	sf::Vector2f m_center;
	sf::String m_name;
	int m_level;
	sf::Sprite m_sprite;
	Collider m_collider;
};