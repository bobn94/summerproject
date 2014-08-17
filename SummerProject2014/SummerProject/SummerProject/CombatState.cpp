#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "CombatState.h"
#include "StateManager.h"
#include "Level.h"
#include "PlayerObject.h"
#include "SkeletonWarrior.h"


CombatState::CombatState() {
	m_done = false;
};


bool CombatState::Enter() {
	if (!m_attackGuiTexture.loadFromFile("../data/images/Gui/CombatGuiAttackSmall.png"))
	{
		std::cout << "Error Loading CombatGuiAttack Texture";
	}
	
	if (!m_abilitiesGuiTexture.loadFromFile("../data/images/Gui/CombatGuiAbilitiesSmall.png"))
	{
		std::cout << "Error Loading CombatGuiAbilities Texture";
	}
	if (!m_inventoryGuiTexture.loadFromFile("../data/images/Gui/CombatGuiInventorySmall.png"))
	{
		std::cout << "Error Loading CombatGuiInventory Texture";
	}
	if (!m_tauntGuiTexture.loadFromFile("../data/images/Gui/CombatGuiTauntSmall.png"))
	{
		std::cout << "Error Loading CombatGuiTaunt Texture";
	}
	if (!m_skeleWarrTexture.loadFromFile("../data/images/Characters/skeletonWarrior2.png"))
	{
		std::cout << "Error Loading skeletonWarrior2 Texture";
	}
	if (!m_enemyHitTexture.loadFromFile("../data/images/Gui/KilledByEnemy.png"))
	{
		std::cout << "Error Loading KilledByEnemy Texture";
	}
	if (!m_selfHitTexture.loadFromFile("../data/images/Gui/EnemyKilled.png"))
	{
		std::cout << "Error Loading EnemyKilled Texture";
	}
	m_selfHitSprite = sf::Sprite(m_selfHitTexture);
	m_enemyHitSprite = sf::Sprite(m_enemyHitTexture);
	m_selfHitChanse = 1.0f;
	m_enemyHitChanse = 1.0f;
	m_selected = 1;
	m_continue = true;
	m_first_run = true;
	return true;
};

void CombatState::Exit() {


};

bool CombatState::Update(float deltatime, sf::RenderWindow& m_window, Level& level) {

	if (m_first_run)
	{
		m_skelewarr = new MapObject("Skeleton Warrior", 0, sf::Vector2f(750.0f, 50.0f), sf::Vector2f(150.0f, 200.0f));
		m_skelewarr->SetSprite(sf::Sprite(m_skeleWarrTexture));
		m_gui = new MapObject("Combat Gui", 0, sf::Vector2f(0.0f, 605.0f), sf::Vector2f(1080.0f, 115.0f));
		m_gui->SetSprite(sf::Sprite(m_attackGuiTexture));
		m_hitGui = new MapObject("Hit Gui", 0, sf::Vector2f(390.0f, 322.5f), sf::Vector2f(300.0f, 75.0f));
		m_hitGui->SetSprite(m_selfHitSprite);
		m_continue = true;
		m_first_run = false;
	}

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
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			if(m_selected == 1){

			}
			else if(m_selected == 2){
				m_selected = 1;
				m_gui->SetSprite(sf::Sprite(m_attackGuiTexture));
			}
			else if(m_selected == 3){

			}
			else if(m_selected == 4){
				m_selected = 3;
				m_gui->SetSprite(sf::Sprite(m_abilitiesGuiTexture));
			}
			else{
				//Error stuff goes here
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			if(m_selected == 1){
				m_selected = 2;
				m_gui->SetSprite(sf::Sprite(m_inventoryGuiTexture));
			}
			else if(m_selected == 2){

			}
			else if(m_selected == 3){
				m_selected = 4;
				m_gui->SetSprite(sf::Sprite(m_tauntGuiTexture));
			}
			else if(m_selected == 4){

			}
			else{
				//Error stuff goes here
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			if(m_selected == 1){

			}
			else if(m_selected == 2){

			}
			else if(m_selected == 3){
				m_selected = 1;
				m_gui->SetSprite(sf::Sprite(m_attackGuiTexture));
			}
			else if(m_selected == 4){
				m_selected = 2;
				m_gui->SetSprite(sf::Sprite(m_inventoryGuiTexture));
			}
			else{
				//Error stuff goes here
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			if(m_selected == 1){
				m_selected = 3;
				m_gui->SetSprite(sf::Sprite(m_abilitiesGuiTexture));
			}
			else if(m_selected == 2){
				m_selected = 4;
				m_gui->SetSprite(sf::Sprite(m_tauntGuiTexture));
			}
			else if(m_selected == 3){

			}
			else if(m_selected == 4){

			}
			else{
				//Error stuff goes here
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			if(m_selected == 1){ //Attack
				if(level.GetCurrentEnemy()->GetSpeed() < level.GetPlayer()->GetSpeed()){

					if((level.GetCurrentEnemy()->GetSpeed() + level.GetCurrentEnemy()->GetStrenght()) < (level.GetPlayer()->GetSpeed() + level.GetPlayer()->GetStrenght()) * m_selfHitChanse){
						m_hitGui->SetSprite(m_selfHitSprite);
						for(int i = 0; i < 2000; i++){
							bool nej = true;
							m_window.clear(sf::Color(0, 0, 0, 0));
							if(level.Update(m_window, nej)){

							}
							m_skelewarr->Draw(&m_window);
							m_gui->Draw(&m_window);
							m_hitGui->Draw(&m_window);
							m_window.display();
						}
						if(level.m_skeletonWarriors.size() > 0){
							level.m_skeletonWarriors.erase(level.m_skeletonWarriors.begin() + level.m_currentEnemy);
						}
						m_next_state = "GameStateA";
						m_continue = false;
					}
				}
				else if(level.GetCurrentEnemy()->GetSpeed() > level.GetPlayer()->GetSpeed()){

					if((level.GetCurrentEnemy()->GetSpeed() + level.GetCurrentEnemy()->GetStrenght()) * m_enemyHitChanse > (level.GetPlayer()->GetSpeed() + level.GetPlayer()->GetStrenght())){
						m_hitGui->SetSprite(m_enemyHitSprite);
						for(int i = 0; i < 2000; i++){
							bool nej = true;
							m_window.clear(sf::Color(0, 0, 0, 0));
							if(level.Update(m_window, nej)){

							}
							m_skelewarr->Draw(&m_window);
							m_gui->Draw(&m_window);
							m_hitGui->Draw(&m_window);
							m_window.display();
						}
						m_window.close();
					}
				}
				else{
					if((level.GetCurrentEnemy()->GetSpeed() + level.GetCurrentEnemy()->GetStrenght()) < (level.GetPlayer()->GetSpeed() + level.GetPlayer()->GetStrenght()) * m_selfHitChanse){
						m_hitGui->SetSprite(m_selfHitSprite);
						for(int i = 0; i < 2000; i++){
							bool nej = true;
							m_window.clear(sf::Color(0, 0, 0, 0));
							if(level.Update(m_window, nej)){

							}
							m_skelewarr->Draw(&m_window);
							m_gui->Draw(&m_window);
							m_hitGui->Draw(&m_window);
							m_window.display();
						}
						if(level.m_skeletonWarriors.size() > 0){
							level.m_skeletonWarriors.erase(level.m_skeletonWarriors.begin() + level.m_currentEnemy);
						}
						m_next_state = "GameStateA";
						m_continue = false;
					}
					else if((level.GetCurrentEnemy()->GetSpeed() + level.GetCurrentEnemy()->GetStrenght()) * m_enemyHitChanse > (level.GetPlayer()->GetSpeed() + level.GetPlayer()->GetStrenght())){
						m_hitGui->SetSprite(m_enemyHitSprite);
						for(int i = 0; i < 2000; i++){
							bool nej = true;
							m_window.clear(sf::Color(0, 0, 0, 0));
							if(level.Update(m_window, nej)){

							}
							m_skelewarr->Draw(&m_window);
							m_gui->Draw(&m_window);
							m_hitGui->Draw(&m_window);
							m_window.display();
						}
						m_window.close();
					}
				}
			}
			else if(m_selected == 2){ //Inventory

			}
			else if(m_selected == 3){ //Abilities

			}
			else if(m_selected == 4){ //Taunt
				
				
				if(m_enemyHitChanse > 0.5f){
					m_enemyHitChanse =- 0.05;
				}
				if((level.GetCurrentEnemy()->GetSpeed() + level.GetCurrentEnemy()->GetStrenght()) * m_enemyHitChanse >= (level.GetPlayer()->GetSpeed() + level.GetPlayer()->GetStrenght())){
						m_hitGui->SetSprite(m_enemyHitSprite);
						for(int i = 0; i < 2000; i++){
							bool nej = true;
							m_window.clear(sf::Color(0, 0, 0, 0));
							if(level.Update(m_window, nej)){

							}
							m_skelewarr->Draw(&m_window);
							m_gui->Draw(&m_window);
							m_hitGui->Draw(&m_window);
							m_window.display();
						}
						m_window.close();
					}
			}
			else{ //Error stuff goes here

			}

		}
		
	
	bool nej = true;
	m_window.clear(sf::Color(0, 0, 0, 0));
	if(level.Update(m_window, nej)){

	}
	m_skelewarr->Draw(&m_window);
	m_gui->Draw(&m_window);
	m_window.display();
	return m_continue;
};

void CombatState::Initialize() {
	
}


std::string CombatState::Next() {
	return m_next_state;
};

bool CombatState::IsType(const std::string &type) {
	return type.compare("CombatState") == 0;
};