#pragma once
#include "stdafx.h"
#include <iostream>
#include "Level.h"
#include "Ally.h"
#include "SkeletonWarrior.h"
#include "MapObject.h"
#include "PlayerObject.h"

Level::Level(){
	
}
Level::Level(sf::RenderWindow &m_window){
	
}
void Level::Load(sf::RenderWindow &m_window){
	m_firstRun = true;
	if (!m_dirtTexture.loadFromFile("../data/images/ground/dirt1.png"))
	{
		std::cout << "Error Loading dirt1 Texture";
	}
	m_dirtTexture.setSmooth(true);
	if (!m_stoneTexture.loadFromFile("../data/images/ground/stone1.png"))
	{
		std::cout << "Error Loading stone1 Texture";
	}
	m_stoneTexture.setSmooth(true);
	if (!m_fireTexture.loadFromFile("../data/images/ground/fire1.png"))
	{
		std::cout << "Error Loading fire1 Texture";
	}
	m_fireTexture.setSmooth(true);
	if (!m_playerTexture.loadFromFile("../data/images/Characters/player.png"))
	{
		std::cout << "Error Loading player Texture";
	}
	m_playerTexture.setSmooth(true);
	if (!m_shopkeeperTexture.loadFromFile("../data/images/Characters/shopkeeper.png"))
	{
		std::cout << "Error Loading shopkeeper Texture";
	}
	m_shopkeeperTexture.setSmooth(true);
	if (!m_skeletonWarrior_Texture.loadFromFile("../data/images/Characters/skeletonWarrior1.png"))
	{
		std::cout << "Error Loading SkeletonWarrior Texture";
	}
	m_skeletonWarrior_Texture.setSmooth(true);
	if (!m_skeletonWarrior_Texture2.loadFromFile("../data/images/Characters/skeletonWarrior3.png"))
	{
		std::cout << "Error Loading SkeletonWarrior3 Texture";
	}
	m_skeletonWarrior_Texture2.setSmooth(true);
	if (!m_winTexture.loadFromFile("../data/images/Gui/YouWon.png"))
	{
		std::cout << "Error Loading Win Texture";
	}
	m_winTexture.setSmooth(true);

	for(int i = 0; i *32 <= m_window.getSize().x; i++){
			m_mapObject.push_back(new MapObject(sf::String(""), 0, sf::Vector2f((32*i), 0), sf::Vector2f(32, 32)));
			m_mapObject.push_back(new MapObject(sf::String(""), 0, sf::Vector2f((32*i), (m_window.getSize().y - 32)), sf::Vector2f(32, 32)));
		}
		for(int i = 0; i *32 <= m_window.getSize().y; i++){
			m_mapObject.push_back(new MapObject("", 0, sf::Vector2f(0, (32*i)), sf::Vector2f(32, 32)));
			m_mapObject.push_back(new MapObject("", 0, sf::Vector2f(m_window.getSize().x - 32, (32*i)), sf::Vector2f(32, 32)));
		}
		int size = 0;
		for(int i = 0; i <= m_mapObject.size() - 1; i++){
			m_mapObject[i]->SetSprite(sf::Sprite(m_stoneTexture));
			size++;
		}
		m_skeletonWarriors.push_back(new SkeletonWarrior(1, 0, 1, 1, "Skeleton Warrior", sf::Vector2f(256, 256), sf::Vector2f(32, 32)));
		m_skeletonWarriors.push_back(new SkeletonWarrior(1, 0, 1, 1, "Skeleton Warrior", sf::Vector2f(512, 256), sf::Vector2f(32, 32)));
		m_skeletonWarriors.push_back(new SkeletonWarrior(1, 0, 1, 1, "Skeleton Warrior", sf::Vector2f(256, 512), sf::Vector2f(32, 32)));
		m_skeletonWarriors.push_back(new SkeletonWarrior(1, 0, 1, 1, "Skeleton Warrior", sf::Vector2f(512, 128), sf::Vector2f(32, 32)));
		for(int i = 0; i <= m_skeletonWarriors.size() - 1; i++){
			m_skeletonWarriors[i]->SetSprite(sf::Sprite(m_skeletonWarrior_Texture));
		}
		
		m_skeletonWarriors.push_back(new SkeletonWarrior(2.1f, 0, 1, 1, "Skeleton Warrior", sf::Vector2f(512, 512), sf::Vector2f(64, 64)));
		m_skeletonWarriors[m_skeletonWarriors.size() - 1]->SetSprite(sf::Sprite(m_skeletonWarrior_Texture2));
		m_skeletonWarriors[m_skeletonWarriors.size() - 1]->SetSpeed(2.1f);
		m_player = new PlayerObject(2, 0, 1, 1, "Player", sf::Vector2f(64, 64), sf::Vector2f(32, 32));
		m_player->SetSprite(sf::Sprite(m_playerTexture));
}
bool Level::Update(sf::RenderWindow &m_window, float deltatime){
	if(m_firstRun){
		m_winscreen = new MapObject("Win Gui", 0, sf::Vector2f(390.0f, 322.5f), sf::Vector2f(300.0f, 75.0f));
		m_winscreen->SetSprite(sf::Sprite(m_winTexture));
		m_firstRun = false;
	}
	if(m_skeletonWarriors.size() == 0){
		for(int i = 0; i < 2000; i++){
			m_winscreen->Draw(&m_window);
		}
	}
	for(int i = 0; i < m_mapObject.size() - 1; i++){
		sf::Vector2f offset;
		if(m_mapObject[i]->GetCollider().Overlap(m_mapObject[i]->GetCollider(), m_player->GetCollider(), offset)){
			m_player->SetPosition(m_player->GetPosition() - offset);
		}
	}
	for(int i = 0; i < m_skeletonWarriors.size(); i++){
		if(m_skeletonWarriors.size() > 0){
			if(m_skeletonWarriors[i]->Update(*m_player, deltatime)){
				m_currentEnemy = i;
				return true;
			}
		}
	}
	m_player->Update();
	for(int i = 0; i < m_mapObject.size(); i++){
		m_mapObject[i]->Draw(&m_window);
	}
	for(int i = 0; i < m_skeletonWarriors.size(); i++){
		m_skeletonWarriors[i]->Draw(&m_window);
	}
	m_player->Draw(&m_window);
	if(m_skeletonWarriors.size() == 0){
		for(int i = 0; i < 2000; i++){
			m_winscreen->Draw(&m_window);
			m_window.display();
		}
	}
	return false;
}

bool Level::Update(sf::RenderWindow &m_window, bool nej){
	for(int i = 0; i < m_mapObject.size(); i++){
		sf::Vector2f offset;
		if(m_mapObject[i]->GetCollider().Overlap(m_mapObject[i]->GetCollider(), m_player->GetCollider(), offset)){
			m_player->SetPosition(m_player->GetPosition() - offset);
		}
	}
	for(int i = 0; i < m_mapObject.size(); i++){
		m_mapObject[i]->Draw(&m_window);
	}
	//m_player->Draw(&m_window);
	return false;
}
SkeletonWarrior* Level::GetCurrentEnemy(){
	return m_skeletonWarriors[m_currentEnemy];
}
PlayerObject* Level::GetPlayer(){
	return m_player;
}
float Level::GetEnemyCombatStrength(){
	return m_skeletonWarriors[m_currentEnemy]->GetSpeed() * m_skeletonWarriors[m_currentEnemy]->GetStrenght();
}
float Level::GetPlayerCombatStrength(){
	return m_player->GetSpeed() * m_player->GetStrenght();
}