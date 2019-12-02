//cards.h
//Authors: Zachary Friedland
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <string>
#include <iostream>
using namespace std;


class Player{	
public:
	Player():name(""), first(nullptr), last(nullptr){} //non-parameterized constructor
	Player(const string Name):name(Name), first(nullptr), last(nullptr){} //parameterized constructor
	~Player(); //activate Card destructor to delete hand
	Player(const Player& source); //copy constructor
	string getName() const{return name;} //accessor functions
	string getComboAtPos(int n) const;
	int getHandSize() const;
	void setName(const string modify){name = modify;}
	void insert(const string c); 
	bool search(const string target);
	void deleteCard(const string target);
	void takeTurn(Player& other);
	bool operator ==(const string other); //== operator for Player
	
private:
	class Card{
	public:	
		Card(string sV):combo(sV), next(nullptr){} //creating a card object
		string combo; // suit *space* value
		Card* next; //points to next card in the list, null if no succeeding cards
	};
	string name; //of player
	Card* first; 
	Card* last;
};

ostream& operator <<(ostream& out, const Player& p);


	


#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
