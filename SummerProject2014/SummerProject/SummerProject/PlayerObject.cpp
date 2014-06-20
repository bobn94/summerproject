#pragma once
#include "stdafx.h"
#include "PlayerObject.h"

	PlayerObject::PlayerObject(){

	}
	PlayerObject::PlayerObject(int speed, int armorValue, int strength, int level, sf::String name){

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
	int PlayerObject::GetSkillPoints(){
		return m_skillPoints;
	}
	int PlayerObject::GetMoney(){
		return m_money;
	}
	int PlayerObject::GetLearnedSkillLevel(int slot){
		return m_learnedSkills[slot];
	}