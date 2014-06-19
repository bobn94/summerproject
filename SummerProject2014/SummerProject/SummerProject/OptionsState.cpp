#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "OptionsState.h"
#include "StateManager.h"


OptionsState::OptionsState() {
	m_done = false;
	m_resetHighScore = false;
	m_changetoGameState = false;

	
};


bool OptionsState::Enter() {
	return true;
};

void OptionsState::Exit() {


};

bool OptionsState::Update(float deltatime, sf::RenderWindow& m_window, Level& level) {
	
	
	
	return !m_done;
};

void OptionsState::Initialize() {
	
}


std::string OptionsState::Next() {
	return m_next_state;
};

bool OptionsState::IsType(const std::string &type) {
	return type.compare("OptionsState") == 0;
};

 

 void OptionsState::ResetHighscore(){
	if (m_resetHighScore = true) {
		std::ofstream ostream("../data/score/score.txt");
		ostream.clear();
		ostream << "10\n";
		for (int i = 0; i <= 9; ++i){
			ostream << (i+1);
			ostream << " ";
			ostream << 0;
			ostream << "\n";
		}
	};
}