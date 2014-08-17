
#include "stdafx.h"
#include <iostream>
#include "GameState.h"
#include "MapObject.h"
#include "Enemy.h"
#include "PlayerObject.h"
#include "Level.h"
#include <cmath>
#include <iostream>


GameStateA::GameStateA()
{
	
};


bool GameStateA::Enter()
{
	
	m_continue = true;
	return true;
};

bool GameStateA::Update(float deltatime, sf::RenderWindow &m_window, Level& level)
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			return false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_window.close();
			return false;

		}

	}

	if (m_first_run)
	{
		
		m_first_run = false;
	}
	
	

	
	m_window.clear(sf::Color(104, 50, 3, 0));
	if(level.Update(m_window, deltatime)){
		m_next_state = "CombatState";
		m_continue = false;
	}
	m_window.display();

	return m_continue;
};

void GameStateA::Exit() {
	
};

std::string GameStateA::Next() {
	return m_next_state;
};

bool GameStateA::IsType(const std::string &type) {
	return type.compare("GameStateA") == 0;
};