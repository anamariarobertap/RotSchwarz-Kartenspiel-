// sda.cpp : Defines the entry point for the console application.
//

#include "joc.h"
#include <cstring>
#include <iostream>

#include <vector>



using namespace std;




int main()
{
	int n = 0;
	Stack<std::string>* st1 = new Stack<std::string>;
	Stack<std::string>* st2 = new Stack<std::string>;

	std::vector<std::string> vect{ "rot", "schwarz","schwarz","rot","schwarz","rot" };
	//std::vector<std::string> vect2{ "rot","schwarz","schwarz","rot","schwarz","rot", "rot","schwarz","schwarz","rot","schwarz","rot", "schwarz","schwarz","rot","rot","schwarz","schwarz","rot","schwarza","rot", "rot","schwarz","schwarz","rot","schwarz","rot", "schwarz","schwarz","rot", };

	//citire(st1, st2);

	createGameVct(vect, st1, st2);
	winner(st1, st2);

	//system("pause");
    return 0;
}

