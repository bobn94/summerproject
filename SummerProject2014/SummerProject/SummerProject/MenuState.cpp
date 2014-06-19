#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "MenuState.h"
#include "StateManager.h"


MenuState::MenuState() {
	m_done = false;


};


bool MenuState::Enter() {

	return true;
};

void MenuState::Exit() {


};

bool MenuState::Update(float deltatime, sf::RenderWindow& m_window, Level& level) {
	
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

	

	return true;
};

void MenuState::Initialize() 
{

}


std::string MenuState::Next() 
{
	return m_next_state;
};

bool MenuState::IsType(const std::string &type)
{
	return type.compare("MenuState") == 0;
};

