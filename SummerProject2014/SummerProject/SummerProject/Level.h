#pragma once
#include "stdafx.h"

class Ally;
class SkeletonWarrior;
class MapObject;
class PlayerObject;
class Level
{
	friend class GameObject;
public:
	Level();
	Level(sf::RenderWindow &m_window);
	void Load(sf::RenderWindow &m_window);
	bool Update(sf::RenderWindow &m_window, float deltatime);
	bool Update(sf::RenderWindow &m_window, bool nej);
	SkeletonWarrior* GetCurrentEnemy();
	PlayerObject* GetPlayer();
	float GetPlayerCombatStrength();
	float GetEnemyCombatStrength();
	std::vector<SkeletonWarrior*> m_skeletonWarriors;
	int m_currentEnemy;
private:
	bool m_firstRun;
	MapObject* m_winscreen;
	sf::Texture m_winTexture;
	sf::Texture m_dirtTexture;
	sf::Texture m_stoneTexture;
	sf::Texture m_fireTexture;
	sf::Texture m_playerTexture;
	sf::Texture m_skeletonWarrior_Texture;
	sf::Texture m_skeletonWarrior_Texture2;
	sf::Texture m_shopkeeperTexture;

	std::vector<Ally*> m_allies;
	std::vector<MapObject*> m_mapObject;
	PlayerObject* m_player;
};