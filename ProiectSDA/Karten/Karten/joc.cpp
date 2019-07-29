#include "joc.h"

void createGame(int n, Stack<std::string>* st1, Stack<std::string>* st2)
{
	std::string c1, c2;
	cin >> n;
	for (int i = 1; i <= n / 2; i++)
	{
		cin >> c1 >> c2;
		st1->addStack(c1);
		st2->addStack(c2);
	}
	cout << endl;
}

void createGameVct(std::vector<std::string> v, Stack<std::string>* st1, Stack<std::string>* st2)
{
	int j = 0;
	for (int i = 1; i <= v.size() / 2; i++)
	{
		st1->addStack(v[j++]);
		st2->addStack(v[j++]);
	}
	cout << endl;
}

void afisare(Stack<std::string>* st1, Stack<std::string>* st2)
{
	cout << "Player 1:";
	auto aux = st1->prim;
	while (aux)
	{
		cout << aux->getElem() << " ";
		aux = aux->getUrm();
	}

	cout << endl;

	cout << "Player 2:";
	aux = st2->prim;
	while (aux)
	{
		cout << aux->getElem() << " ";
		aux = aux->getUrm();
	}

	cout << endl << endl;
}

void rebuildStack(Stack<std::string>* st, Schlange<std::string>* c)
{
	Stack<std::string>* st3 = new Stack<std::string>;
	while (!(st->isEmptyStack()))
	{
		auto e = st->elementStack();
		st3->addStack(e);
		st->remove();
	}

	while (!(c->isEmptySchlange()))
	{
		auto e = c->elemSchlange();
		st->addStack(e);
		c->delSchlange();
	}

	while (!(st3->isEmptyStack()))
	{
		auto e = st3->elementStack();
		st->addStack(e);
		st3->remove();
	}
}

void winner(Stack<std::string>* st1, Stack<std::string>* st2)
{
	afisare(st1, st2);

	Schlange<std::string>* c= new Schlange<std::string>;
	while (!(st1->isEmptyStack()) && !(st2->isEmptyStack()))
	{
		auto e = st1->elementStack();
		st1->remove();
		c->addSchlange(e);
		cout << "Karte von Player 1 ist " << e << endl;
		if (e == "rot")
		{
			rebuildStack(st2, c);
			afisare(st1, st2);
		}

		e = st2->elementStack();
		st2->remove();
		c->addSchlange(e);
		cout << "Karte von Player 2 ist " << e << endl;

		if (e == "rot")
		{
			rebuildStack(st1, c);
			afisare(st1, st2);
		}
	}

	if (!(st1->isEmptyStack()))
		cout << "Player 1 hat gewonnen!" << endl;
	else if (!(st2->isEmptyStack()))
		cout << "Player 2 hat gewonnen!" << endl;


	

}