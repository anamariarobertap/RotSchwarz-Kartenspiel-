#include "stdafx.h"
#include "Spiel.h"


void create_Spiel(int n, Stack<std::string>* st1, Stack<std::string>* st2) {
	std::string c1, c2;
	cin >> n;
	for (int i = 1; i <= n / 2; i++) {
		cin >> c1 >> c2;
		st1->add_Stack(c1);
		st2->add_Stack(c2);
	}
	cout << endl;
}

void create_Spiel_Vektor(std::vector<std::string> v, Stack<std::string>* st1, Stack<std::string>* st2) {
	int j = 0;
	for (int i = 1; i <= v.size() / 2; i++) {

		st1->add_Stack(v[j++]);
		st2->add_Stack(v[j++]);
	}
	cout << endl;
}

void afisareIntermediara(Stack<std::string>* st1, Stack<std::string>* st2) {
	cout << "Spieler 1 :";
	auto aux = st1->first;
	while (aux) {
		cout << aux->getElem() << " ";
		aux = aux->getNext();
	}

	cout << endl;

	cout << "Spieler 2 :";
	aux = st2->first;
	while (aux) {
		cout << aux->getElem() << " ";
		aux = aux->getNext();
	}

	cout << endl << endl;
}


void remakeStack(Stack<std::string>* st, Schlange<std::string>* c) {
	Stack<std::string>* st3 = new Stack<std::string>;
	while (!(st->stEmpty())) {
		auto e = st->stackElem();
		st3->add_Stack(e);
		st->remove();
	}

	while (!(c->ist_leer())) {
		auto e = c->elemSchlange();
		st->add_Stack(e);
		c->del_Schlange();
	}

	while (!(st3->stEmpty())) {
		auto e = st3->stackElem();
		st->add_Stack(e);
		st3->remove();
	}

}

void gewinner(Stack<std::string>* st1, Stack<std::string>* st2) {
	afisareIntermediara(st1, st2);

	Schlange<std::string>* c = new Schlange<std::string>;
	while (!(st1->stEmpty()) && !(st2->stEmpty())) {
		
		auto e = st1->stackElem();
		st1->remove();
		c->add_Schlange(e);
		cout << "Spieler 1 hate eine " << e << " Karte gegeben "<<endl;
		if (e == "rote") {
			remakeStack(st2, c);
			afisareIntermediara(st1, st2);
		}

		e = st2->stackElem();
		st2->remove();
		c->add_Schlange(e);
		cout << "Spieler 2 hat eine " << e <<" Karte gegeben "<< endl;

		if (e == "rote") {
			remakeStack(st1, c);
			afisareIntermediara(st1, st2);
		}


	}
	if (!(st1->stEmpty()))
		cout << "Der Gewinner ist Spieler 1 \n";
	else if (!(st2->stEmpty()))
		cout << "Der Gewinner ist Spieler 2 \n";
}
