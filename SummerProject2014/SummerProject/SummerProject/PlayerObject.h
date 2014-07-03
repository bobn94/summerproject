#pragma once
#include "stdafx.h"
#include "CharacterObject.h"
#include "Input.h"

class PlayerObject : public CharacterObject{
public:
	PlayerObject();
	PlayerObject(int speed, int armorValue, int strength, int level, sf::String name, sf::Vector2f position, sf::Vector2f extention);
	void SetSkillpoints(int skillpoints);
	void SetMoney(int money);
	void LearnSkill(int skillSlot);
	void LevelUp();
	int GetSkillPoints();
	int GetMoney();
	int GetLearnedSkillLevel(int slot);
	int GetLevel();
	void Update();
private:
	Keyboard m_keyboard;
	Mouse m_mouse;
	int m_level;
	int m_skillPoints;
	int m_money;
	int m_learnedSkills[15];
};