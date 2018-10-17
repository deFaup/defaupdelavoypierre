#include <string>

#include "define.hpp"
#include "Player.h"

using namespace state;
using namespace std;

Player::Player(): name("Un-named Player"){}

Player::Player(string name): name(name){}

void Player::add_character(Characters new_character){
	if(this->number_of_characters < MAX_NB_CHARACTER){
		std::unique_ptr<Characters> ptr(&new_character);
		this->characters.push_back(std::move(ptr));
		(this->number_of_characters)++;
	}
	return;
}

void Player::select_character(Characters character){
	this->current_character = character;	
	return;
}

unsigned int Player::get_number_of_characters (){
	return(this->number_of_characters);
}

void Player::set_number_of_characters (unsigned int number){
	this->number_of_characters = number;
	return;
}

