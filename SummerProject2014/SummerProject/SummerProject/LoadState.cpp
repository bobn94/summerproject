#pragma once
#include "stdafx.h"
#include <iostream>
#include "LoadState.h"

LoadState::LoadState(){
	m_done = false;
}
bool LoadState::Enter()
{
	if (!m_continue_btn_texture.loadFromFile("../data/textures/continue_btn.png"))
	{
		std::cout << "Loading Error";
	}
	m_continue_btn_texture.setSmooth(true);
	
	if (!m_background_texture.loadFromFile("../data/textures/Loading.png"))
	{
		std::cout << "Loading Error";
	}
	m_background_texture.setSmooth(true);
	m_continue_btn_sprite.setTexture(m_continue_btn_texture);
	m_continue_btn_sprite.setOrigin(m_continue_btn_sprite.getLocalBounds().width / 2, m_continue_btn_sprite.getLocalBounds().height / 2);

	m_background_sprite.setTexture(m_background_texture);
	m_background_sprite.setOrigin(m_background_sprite.getLocalBounds().width / 2, m_background_sprite.getLocalBounds().height / 2);
	return true;
}

void LoadState::Exit()
{
	//delete things
}

void LoadState::Initialize(){

}

bool LoadState::Update(float deltatime, sf::RenderWindow& m_window, Level& level)
{
	
	return true;
}

std::string LoadState::Next()
{
	return m_next_state;
}

bool LoadState::IsType(const std::string &type)
{
	return type.compare("UpgradeState") == 0;
}