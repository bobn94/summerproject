#pragma once
#include "StateManager.h"
#include "GameState.h"
#include "OptionsState.h"
#include "MenuState.h"
#include "LoadState.h"
#include "stdafx.h"
//#include "Level.h"

class PlayerObject;
class Collider;
class ProjectileObject;

class Engine{
public:
	Engine();
	~Engine();
	void Initialize();
	void Run();
	void Cleanup();

private:
	float m_deltatime;
	sf::Clock deltaClock;
	sf::RenderWindow* m_window;
	//Level m_level;
};