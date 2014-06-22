#pragma once
#include "stdafx.h"
#include "Ally.h"

	Ally::Ally(){
		m_isShop = false;
		for(int i = 0; i < 20; i++){
			m_dialog[i] = "";
		}
	}
	Ally::Ally(int speed, int armorValue, int strength, int level, sf::String name){
		m_isShop = false;
		for(int i = 0; i < 20; i++){
			m_dialog[i] = "";
		}
	}
	Ally::Ally(int speed, int armorValue, int strength, int level, sf::String name, bool isShop){
		m_isShop = isShop;
		for(int i = 0; i < 20; i++){
			m_dialog[i] = "";
		}
	}
	bool Ally::AddDialog(sf::String line){
		for(int i = 0; i < 20; i++){
			if(m_dialog[i] == ""){
				m_dialog[i] = line;
				return true;
			}
			return false;
		}
	}
	sf::String Ally::GetLine(int line){
		return m_dialog[line];
	}