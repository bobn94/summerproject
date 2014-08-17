#pragma once
#include "stdafx.h"
#include "SkeletonWarrior.h"
#include "PlayerObject.h"

SkeletonWarrior::SkeletonWarrior(){

}
SkeletonWarrior::SkeletonWarrior(float speed, float armorValue, float strength, int level, sf::String name, sf::Vector2f position, sf::Vector2f extention) : Enemy(speed, armorValue, strength, level, name, position, extention){

}
SkeletonWarrior::SkeletonWarrior(float speed, float armorValue, float strength, int level, sf::String name, Skills* skill, sf::Vector2f position, sf::Vector2f extention) : Enemy(speed, armorValue, strength, level, name, skill, position, extention){

}
bool Enemy::Update(PlayerObject player, float deltatime){
	sf::Vector2f target = player.GetPosition();
	sf::Vector2f origin = GetPosition();
	float AngleX = player.GetPosition().x - GetPosition().x;
	float AngleY = player.GetPosition().y - GetPosition().y;
	float m_pi = 3.141592653589793238462643383279502884197169399375105820;
	float vectorLength = sqrt(AngleX * AngleX + AngleY * AngleY);

	float DirectionX = AngleX / vectorLength;
	float DirectionY = AngleY / vectorLength;
	sf::Vector2f m_velocity = sf::Vector2f(DirectionX * GetSpeed(), DirectionY * GetSpeed());

	
	/*else if (m_dirtLevel <= 0)
	{
		m_on_target = true;
	}*/
	if (vectorLength <= 25)
	{
		sf::Vector2f dirVec = sf::Vector2f(target.x - origin.x, target.y - origin.y);

		//Calculate the length^2
		float magSquare = std::sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

		//Change the mag to 1 (you dont need the y for getting the angle
		dirVec.x = (dirVec.x) / magSquare;

		//Get the angle and change it to deg (SFML need deg)
		float rotAngle = std::acos(dirVec.x) * (180 / m_pi);

		if (GetSprite().getPosition().y < target.y)
		{
			GetSprite().setRotation(90 + rotAngle);
		}
		else if (GetSprite().getPosition().x == target.x && GetSprite().getPosition().y == target.y)
		{
		}
		else
		{
			GetSprite().setRotation(90 - rotAngle);
		}

		/*if (m_attack_timer->Done() && m_dirtLevel > 0)
		{
			player->SetCurrentHealth(player->GetCurrentHealth() + 1.0f);
			if (player->GetCurrentHealth() > player->GetMaxHealth())
			{
				player->SetCurrentHealth(player->GetMaxHealth());
			}
			//std::cout << player->GetCurrentHealth();
			m_attack_timer->Reset();
			m_attack_timer->Start();
		}*/
		return true;
	}
	else if (vectorLength >= 25 && vectorLength <= 100 /*|| vectorLength >= 5*/)
	{
		SetPosition((GetPosition() + m_velocity * deltatime * 10000.0f));

		sf::Vector2f m_origin = GetSprite().getPosition();

		//Calculate the direction vector
		sf::Vector2f dirVec = sf::Vector2f(target.x - origin.x, target.y - origin.y);

		//Calculate the length^2
		float magSquare = std::sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

		//Change the mag to 1 (you dont need the y for getting the angle
		dirVec.x = (dirVec.x) / magSquare;

		//Get the angle and change it to deg (SFML need deg)
		float rotAngle = std::acos(dirVec.x) * (180 / m_pi);

		if (GetSprite().getPosition().y < target.y)
		{
			GetSprite().setRotation(90 + rotAngle);
		}
		else if (GetSprite().getPosition().x == target.x && GetSprite().getPosition().y == target.y)
		{
		}
		else
		{
			GetSprite().setRotation(90 - rotAngle);
		}


		/*
		if (m_current_animation != nullptr)
		{
		m_current_animation->Update(deltatime);
		}
		*/

		//m_position = GetSprite().getPosition();

		/*if (HasCollider())
		{
			m_collider->m_position = GetSprite().getPosition();
		}*/
	}
	/*if (vectorLength <= 55 && m_dirtLevel > 0)
	{
		if (m_attack_timer->Done())
		{
			player->SetCurrentHealth(player->GetCurrentHealth() + 1.0f);
			if (player->GetCurrentHealth() > player->GetMaxHealth()){
				player->SetCurrentHealth(player->GetMaxHealth());
			}
			//std::cout << player->GetCurrentHealth();
			m_attack_timer->Reset();
			m_attack_timer->Start();
		}
	}*/
	GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height / 2);
	return false;
}