#include "Stiva.h"
#include "Coada.h"
#include "Tests.h"
#include "assert.h"


void testStiva() {
	Stiva<int>* st = new Stiva<int>;
	assert(st->stVida());
	st->adaugaStiva(1);
	st->adaugaStiva(2);
	assert(st->size() == 2);
	assert(topStack() == 2);
	st->remove();
	assert(st->size() == 1);
	assert(st->elementStiva() == 1);
	assert(st->stVida() == false);

}

void testCoada() {
	Coada<int>* c = new Coada<int>;
	assert(c->cVida());
	c->adaugaCoada(1);
	c->adaugaCoada(2);
	c->adaugaCoada(3);
	assert(c->size() == 3);
	assert(c->elementCoada() == 1);
	assert(c->cVida() == false);
	c->stergeCoada();
	assert(c->size() == 2);
	assert(c->elementCoada() == 2);
	c->stergeCoada();
	assert(c->size() == 1);
	assert(c->cVida() == false);
	assert(c->elementCoada() == 3);
	

}