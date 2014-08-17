#pragma once

#include "stdafx.h"
#include "State.h"
#include <vector>


class Collider;
class PlayerObject;
class Enemy;
class Ally;
class MapObject;


class GameStateA : public State {
public:
	GameStateA();

	bool Enter();
	void Exit();
	bool Update(float deltatime, sf::RenderWindow& m_window, Level& level);
	std::string Next();
	bool IsType(const std::string &type);
private:
	
	sf::Vector2f m_mouse_position;

	std::string m_next_state;
	///////Textures

	

	float m_global_speed;



	bool m_first_run;

	bool m_continue;
};

