#pragma once

#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include "State.h"
#include "Enemy.h"
#include "MapObject.h"


class SpriteManager;
class Sprite;
class DrawManager;
class GameObject;
class PlayerObject;
class SkeletonWarrior;

class CombatState : public State {
public:
	CombatState();
	
	bool Enter();
	void Exit();
	bool Update(float deltatime, sf::RenderWindow& m_window, Level& level);
	void Initialize();
	void Draw(DrawManager* m_draw_manager);
	std::string Next();
	bool IsType(const std::string &type);


private:
	bool m_first_run;
	SkeletonWarrior* m_enemy;
	int m_selected;
	MapObject* m_gui;
	MapObject* m_skelewarr;
	MapObject* m_hitGui;
	sf::Texture m_attackGuiTexture;
	sf::Texture m_tauntGuiTexture;
	sf::Texture m_abilitiesGuiTexture;
	sf::Texture m_inventoryGuiTexture;
	sf::Texture m_skeleWarrTexture;
	sf::Texture m_enemyHitTexture;
	sf::Texture m_selfHitTexture;
	sf::Vector2u m_crosshairPos;
	sf::Sprite m_enemyHitSprite;
	sf::Sprite m_selfHitSprite;
	bool m_done;
	std::string m_next_state;
	float m_selfHitChanse;
	float m_enemyHitChanse;
	int m_countdown;
	bool m_continue;
};

