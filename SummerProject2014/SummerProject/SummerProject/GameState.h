#pragma once

#include "stdafx.h"
#include "State.h"


class Collider;
class CountdownTimer;
class PlayerObject;
class ProjectileObject;
class SlowKid;
class BikeKid;
class Enemy;
class SpriteObject;
class ParentUI;
class Arrow;
class Indicator;
class ParentBall;


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
	/////////////////////////////////////SOUND

	
	//////////////////////////////////////

	

	//StateManager * mgr;
	CountdownTimer* m_timer;
	PlayerObject * m_player;
	

	float m_global_speed;



	bool m_first_run;

	bool m_continue;
};

