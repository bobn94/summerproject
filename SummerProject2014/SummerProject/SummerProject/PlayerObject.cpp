#pragma once
#include "stdafx.h"
#include "PlayerObject.h"

	PlayerObject::PlayerObject() : CharacterObject(){
		m_level = 1;
	}
	PlayerObject::PlayerObject(int speed, int armorValue, int strength, int level, sf::String name, sf::Vector2f position, sf::Vector2f extention) : CharacterObject(speed, armorValue, strength, level, name, position, extention){
		m_level = 1;
	}
	void PlayerObject::SetSkillpoints(int skillpoints){
		m_skillPoints = skillpoints;
	}
	void PlayerObject::SetMoney(int money){
		m_money = money;
	}
	void PlayerObject::LearnSkill(int skillSlot){
		if(m_skillPoints > 0){
			m_skillPoints --;
			m_learnedSkills[skillSlot] ++;
		}
	}
	void PlayerObject::LevelUp(){
		m_level++;
	}
	void PlayerObject::Update(){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			SetPosition(sf::Vector2f(GetPosition().x - 0.01 * GetSpeed(), GetPosition().y));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			SetPosition(sf::Vector2f(GetPosition().x + 0.01 * GetSpeed(), GetPosition().y));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			SetPosition(sf::Vector2f(GetPosition().x, GetPosition().y - 0.01 * GetSpeed()));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			SetPosition(sf::Vector2f(GetPosition().x, GetPosition().y + 0.01 * GetSpeed()));
		}
		
	}
	int PlayerObject::GetSkillPoints(){
		return m_skillPoints;
	}
	int PlayerObject::GetMoney(){
		return m_money;
	}
	int PlayerObject::GetLearnedSkillLevel(int slot){
		return m_learnedSkills[slot];
	}
	int PlayerObject::GetLevel(){
		return m_level;
	}