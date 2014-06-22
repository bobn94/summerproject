#pragma once
#include "stdafx.h"
#include "Enemy.h"


	Enemy::Enemy(){
		m_inCombat = false;
		for(int i = 0; i < 5; i++){
			m_dialog[i] = "";
		}
	}
	Enemy::Enemy(int speed, int armorValue, int strength, int level, sf::String name) : CharacterObject(speed, armorValue, strength, level, name){
		m_inCombat = false;
		for(int i = 0; i < 5; i++){
			m_dialog[i] = "";
		}
	}
	Enemy::Enemy(int speed, int armorValue, int strength, int level, sf::String name, Skills* skill) : CharacterObject(speed, armorValue, strength, level, name){
		m_inCombat = false;
		m_skill = skill;
		for(int i = 0; i < 5; i++){
			m_dialog[i] = "";
		}
	}
	void Enemy::SetSkill(Skills* skill){
		m_skill = skill;
	}
	Skills* Enemy::GetSkill(){
		return m_skill;
	}
	bool Enemy::AddDialog(sf::String line){
		for(int i = 0; i < 5; i++){
			if(m_dialog[i] == ""){
				m_dialog[i] = line;
				return true;
			}
			return false;
		}
	}
	sf::String Enemy::GetLine(int line){
		return m_dialog[line];
	}