#pragma once
#include "stdafx.h"


struct Skills{
	int id;
	sf::String Name;
	sf::String Description;
	int target; //0 == no target, 1 == Self, 2 == Other // 3 == Ally
	float hitChanse;
	float duration;
};