
#include "stdafx.h"
#include <iostream>
#include "GameState.h"
#include "MapObject.h"
#include "Enemy.h"
#include "PlayerObject.h"

#include <cmath>
#include <iostream>


GameStateA::GameStateA()
{
	
};


bool GameStateA::Enter()
{
	if (!m_dirtTexture.loadFromFile("../data/images/ground/dirt1.png"))
	{
		// This shit shouldn't happen
	}
	m_dirtTexture.setSmooth(true);
	if (!m_stoneTexture.loadFromFile("../data/images/ground/stone1.png"))
	{
		// This shit shouldn't happen
	}
	m_stoneTexture.setSmooth(true);
	if (!m_fireTexture.loadFromFile("../data/images/ground/fire1.png"))
	{
		// This shit shouldn't happen
	}
	m_fireTexture.setSmooth(true);
	if (!m_playerTexture.loadFromFile("../data/images/Characters/player.png"))
	{
		// This shit shouldn't happen
	}
	m_playerTexture.setSmooth(true);
	if (!m_shopkeeperTexture.loadFromFile("../data/images/Characters/shopkeeper.png"))
	{
		// This shit shouldn't happen
	}
	m_shopkeeperTexture.setSmooth(true);
	if (!m_skeletonWarrior_Texture.loadFromFile("../data/images/Characters/skeletonWarrior1.png"))
	{
		// tThis shit shouldn't happen
	}
	m_skeletonWarrior_Texture.setSmooth(true);

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
		for(int i = 0; i *32 <= m_window.getSize().x + 32; i++){
			m_mapObject.push_back(new MapObject(sf::String(""), 0, sf::Vector2f((32*i), 0), sf::Vector2f(32, 32)));
			m_mapObject.push_back(new MapObject(sf::String(""), 0, sf::Vector2f((32*i), (m_window.getSize().y - 32)), sf::Vector2f(32, 32)));
		}
		for(int i = 0; i *32 <= m_window.getSize().y + 32; i++){
			m_mapObject.push_back(new MapObject("", 0, sf::Vector2f(0, (32*i)), sf::Vector2f(32, 32)));
			m_mapObject.push_back(new MapObject("", 0, sf::Vector2f(m_window.getSize().x - 32, (32*i)), sf::Vector2f(32, 32)));
		}
		int size = 0;
		for(int i = 0; i < m_mapObject.size() - 1; i++){
			m_mapObject[i]->SetSprite(sf::Sprite(m_stoneTexture));
			size++;
		}
		m_player = new PlayerObject(1, 0, 1, 1, "Player", sf::Vector2f(64, 64), sf::Vector2f(32, 32));
		m_player->SetSprite(sf::Sprite(m_playerTexture));

		m_first_run = false;
	}
	for(int i = 0; i < m_mapObject.size() - 1; i++){
		sf::Vector2f offset;
		if(m_mapObject[i]->GetCollider().Overlap(m_mapObject[i]->GetCollider(), m_player->GetCollider(), offset)){
			m_player->SetPosition(m_player->GetPosition() - offset);
		}
	}

	m_player->Update();
	m_window.clear(sf::Color(104, 50, 3, 0));
	for(int i = 0; i < m_mapObject.size() - 1; i++){
		m_mapObject[i]->Draw(&m_window);
	}
	m_player->Draw(&m_window);
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