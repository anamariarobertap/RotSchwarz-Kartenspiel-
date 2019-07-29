#include "Tests.h"
#include "joc.h"

int main() {
	testStiva();
	testCoada();
	int n = 0;
	Stiva<std::string>* st1 = new Stiva<std::string>;
	Stiva<std::string>* st2 = new Stiva<std::string>;
	//creeazaJoc(n, st1, st2);
	std::vector<std::string> vect{ "rosie","neagra","neagra","rosie","neagra","rosie" };
	std::vector<std::string> vect2{ "rosie","neagra","neagra","rosie","neagra","rosie", "rosie","neagra","neagra","rosie","neagra","rosie", "neagra","neagra","rosie","rosie","neagra","neagra","rosie","neagra","rosie", "rosie","neagra","neagra","rosie","neagra","rosie", "neagra","neagra","rosie", };
	creeazaJocVector(vect, st1, st2);
	castigator(st1, st2);
	return 0;
}