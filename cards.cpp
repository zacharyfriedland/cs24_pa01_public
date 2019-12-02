//cards.cp constp
//Authors: Zachary Friedland
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <string>
#include <iostream>
using namespace std;

ostream& operator <<(ostream& out, const Player& p){
	string playerHand = "";
	for(int i = 1; i <= p.getHandSize(); i++){
		playerHand += p.getComboAtPos(i) + "\n";
	}
	out << playerHand;
	return out;
}



bool Player::operator ==(const string other){ //== operator for Card
	Card* iter = this->first;
	string fullHand = "";
	while(iter){
		fullHand+= iter->combo + "\n";
		iter = iter->next;
	}
	return fullHand == other;


}

Player::Player(const Player& source){ 
	Card *cpy = source.first;
	first = last = nullptr;
	while(cpy){
		this->insert(cpy->combo);
		cpy = cpy->next;
	}
}

Player::~Player(){
	Card* iter = first;
	while(iter){
		Card* tmp = iter;
		iter = iter->next;
		delete tmp;
	}
	first = nullptr;
	last = nullptr;
}	

string Player::getComboAtPos(int n) const{
	//must be greater than 0 and less than or equal to the size of the hand

	Card* x = this->first;
	if(n <= 0)
		return first->combo;
	if(n >= this->getHandSize())
		return last->combo;
	for(int i = 1; i < n; i++){
		x = x->next;
	}
	return x->combo;
}

int Player::getHandSize() const{
	Card* iter = this->first;
	int count = 0;
	while(iter){
		count++;
		iter = iter->next;
	}
	return count;
}



void Player::insert(const string c){ 
	Card* n = new Card(c);
	if(first == nullptr && last == nullptr){
		//if empty hand, c becomes first card in Player
		first = n;
		last = n;
	}
	else{
		//if Player not empty, add c to end of Player
		Card* temp = last;
		last = n;
		temp->next = n;
	}
	
}

void Player::deleteCard(string target){
	if(target == first->combo){ //if the target = first
		if(first->next == nullptr){
			delete first;
			first = nullptr;
		}
		else{
			Card* tmp = first;
			first = first->next;
			delete tmp;
			tmp = NULL;
		}
	}
	else if(target == last->combo){ //if target = last
		Card* fix = first;
		while(fix->next != last){
			fix = fix->next;
		}
		last = fix;
		fix = fix->next;
		delete fix;
		fix = NULL;
		last->next = nullptr;
	}
	else{
		//link the cards before and after target card and delete target
		Card* linker = first;
		while(linker->next->combo != target){
			linker = linker->next;
		}
		Card* temp = linker->next;
		linker->next = temp->next;
		delete temp;
		temp = NULL;
	}
	
}

bool Player::search(string target){ //return true if target is in Player
	Card* finder = first;
	while(finder){
		if(finder->combo == target)
			return true;
		finder = finder->next;
	}
	return false;
}

void Player::takeTurn(Player& other){
	for(int i = 1; i <= this->getHandSize(); i++){
		if(other.search(this->getComboAtPos(i))){
		  cout << this->getName() << " picked matching card " << this->getComboAtPos(i)<<endl;
			other.deleteCard(this->getComboAtPos(i));
			this->deleteCard(this->getComboAtPos(i));
			return;
		}
	}
}



