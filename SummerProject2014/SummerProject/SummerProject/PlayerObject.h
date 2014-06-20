#pragma once
#include "CharacterObject.h"

class PlayerObject : CharacterObject{
public:
	PlayerObject();
	PlayerObject(int speed, int armorValue, int strength, int level, sf::String name);
	void SetSkillpoints(int skillpoints);
	void SetMoney(int money);
	void LearnSkill(int skillSlot);
	int GetSkillPoints();
	int GetMoney();
	int GetLearnedSkillLevel(int slot);
private:
	int m_skillPoints;
	int m_money;
	int m_learnedSkills[15];
};