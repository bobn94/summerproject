#include "stdafx.h"
#include "Engine.h"
//#include "GameObject.h"
//#include "PlayerObject.h"
//#include "ProjectileObject.h"
//#include "Collider.h"
//#include "Level.h"
#include <cmath>
#include <iostream>

Engine::Engine(){
}

Engine::~Engine(){

}

void Engine::Initialize(){
	srand((unsigned int) time(0));
	

	
}
void Engine::Run(){
	StateManager mgr;
		mgr.Attach(new MenuState());
		mgr.Attach(new GameStateA());
		mgr.Attach(new OptionsState());
		mgr.Attach(new LoadState());
		mgr.Attach(new CombatState());
		mgr.SetState("GameStateA");
		mgr.isRunning = true;

		bool fullscreen = false;
		if (fullscreen)
		{
			m_window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Generic Dungeoncrawler", sf::Style::Fullscreen);
		}
		else
		{
			m_window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Generic Dungeoncrawler");
		}
		m_level = Level(*m_window);
		m_level.Load(*m_window);

		while (mgr.IsRunning())
		{
			m_deltatime = static_cast<float>(deltaClock.restart().asSeconds()) / 1000;
			//mgr.Update(m_deltatime, m_window, 
		
			if(!m_window->isOpen()){
				mgr.isRunning = false;
			}
			mgr.Update(m_deltatime, *m_window, m_level);
		
			
		}

}
void Engine::Cleanup(){
	

	

}