// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_append();
  test_equal();
  test_card();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  //test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  //test_equal_single_element_list();
  END_TEST("test_card");
}


void test_append_empty_list(){ 
// A test case for append single card node to LinkedList
	string testname = "case 0: insert Card to empty Player list";
	Player tester("Mouse");
	string compare = "h 8";
	tester.insert("h 8");
	assertEquals(compare, tester.getComboAtPos(1), testname);
}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)
	string testname = "case 1: insert Card to single element Player list";
	Player tester("Mouse");
	string compare = "h 8 s a";
	tester.insert("h 8");
	tester.insert("s a");
	string testString = tester.getComboAtPos(1) + " " + tester.getComboAtPos(2);
	assertEquals(compare, testString, testname);

}
void test_equal_empty_list(){ 
	string testname = "case 3: test == operator on empty list";
	Player tester("Mouse");
	string compare = "";
	assertEquals(compare, tester, testname);
}

void test_card_operator_double_equal(){
  // Test to check if == is overloaded for card
	string testname = "case 4: test == operator for Card";
	Player tester("Mouse");
	string compare = "s 9\nc j\n";
	tester.insert("s 9");
	tester.insert("c j");
	assertEquals(compare, tester, testname);

}




