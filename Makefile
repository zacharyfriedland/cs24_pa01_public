game: cards.cpp main.cpp
	g++ -g -std=c++11 cards.cpp main.cpp -o game

testcards: cards.cpp  testcards.cpp
	g++ -g -std=c++11 cards.cpp testcards.cpp -o testcards

clean:
	rm game testcards

