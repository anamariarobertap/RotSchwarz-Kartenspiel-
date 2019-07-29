#include "joc.h"

void creeazaJoc(int n, Stiva<std::string>* st1, Stiva<std::string>* st2) {
	std::string c1, c2;
	cin >> n;
	for (int i = 1; i <= n / 2; i++) {
		cin >> c1 >> c2;
		st1->adaugaStiva(c1);
		st2->adaugaStiva(c2);
	}
	cout << endl;
}

void creeazaJocVector(std::vector<std::string> v, Stiva<std::string>* st1, Stiva<std::string>* st2) {
	int j = 0;
	for (int i = 1; i <= v.size() / 2; i++) {

		st1->adaugaStiva(v[j++]);
		st2->adaugaStiva(v[j++]);
	}
	cout << endl;
}

void afisareIntermediara(Stiva<std::string>* st1, Stiva<std::string>* st2) {
	cout << "Jucatorul 1 :";
	auto aux = st1->prim;
	while (aux) {
		cout << aux->getElem() << " ";
		aux = aux->getUrm();
	}

	cout << endl;

	cout << "Jucatorul 2 :";
	aux = st2->prim;
	while (aux) {
		cout << aux->getElem() << " ";
		aux = aux->getUrm();
	}

	cout << endl << endl;
}


void refacereStiva(Stiva<std::string>* st, Coada<std::string>* c) {
	Stiva<std::string>* st3 = new Stiva<std::string>;
	while (!(st->stVida())) {
		auto e = st->elementStiva();
		st3->adaugaStiva(e);
		st->remove();
	}

	while (!(c->cVida())) {
		auto e = c->elementCoada();
		st->adaugaStiva(e);
		c->stergeCoada();
	}

	while (!(st3->stVida())) {
		auto e = st3->elementStiva();
		st->adaugaStiva(e);
		st3->remove();
	}

}

void castigator(Stiva<std::string>* st1, Stiva<std::string>* st2) {
	afisareIntermediara(st1, st2);

	Coada<std::string>* c = new Coada<std::string>;
	while (!(st1->stVida()) && !(st2->stVida())) {
		//cout << "se joaca" << endl;
		auto e = st1->elementStiva();
		st1->remove();
		c->adaugaCoada(e);
		cout << "Jucatorul 1 a dat o carte de culoare " << e << endl;
		if (e == "rosie") {
			refacereStiva(st2, c);
			afisareIntermediara(st1, st2);
		}

		e = st2->elementStiva();
		st2->remove();
		c->adaugaCoada(e);
		cout << "Jucatorul 2 a dat o carte de culoare " << e << endl;

		if (e == "rosie") {
			refacereStiva(st1, c);
			afisareIntermediara(st1, st2);
		}

		
	}
	if (!(st1->stVida()))
		cout << "Castigatorul este jucatorul 1";
	else if (!(st2->stVida()))
		cout << "Castigatorul este jucatorul 2";
}