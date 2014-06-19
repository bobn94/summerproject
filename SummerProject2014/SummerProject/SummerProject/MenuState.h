#pragma once

#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include "State.h"


class SpriteManager;
class Sprite;
class DrawManager;
class GameObject;

class MenuState : public State {
public:
	MenuState();
	
	bool Enter();
	void Exit();
	bool Update(float deltatime, sf::RenderWindow& m_window, Level& level);
	void Initialize();
	std::string Next();
	bool IsType(const std::string &type);
	



private:
	
	bool m_done;
	std::string m_next_state;
};

