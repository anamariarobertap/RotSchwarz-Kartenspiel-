// SDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Spiel.h"

int main() {

	int n = 0;
	Stack<std::string>* st1 = new Stack<std::string>;
	Stack<std::string>* st2 = new Stack<std::string>;
	//creeazaJoc(n, st1, st2);
	std::vector<std::string> vect{ "rote","schwarze","schwarze","rote","schwarze","rote" };
	std::vector<std::string> vect2{ "rote","schwarze","schwarze","rote","schwarze","rote", "rote","schwarze","schwarze","rote","schwarze","rote", "schwarze","schwarze","rote","rote","schwarze","schwarze","rote","schwarze","rote", "rote","schwarze","schwarze","rote","schwarze","rote", "schwarze","schwarze","rote", };
	create_Spiel_Vektor(vect, st1, st2);
	gewinner(st1, st2);
	return 0;
}