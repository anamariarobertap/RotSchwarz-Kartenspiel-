#include "Stack.h"
#include "Schlange.h"
#include "Tests.h"
#include <assert.h>

void testStack()
{
	Stack<int>* st = new Stack<int>;
	assert(st->isEmptyStack());
	st->addStack(1);
	st->addStack(2);
	assert(st->size() == 2);
	assert(st->elementStack() == 2);
	st->remove();
	assert(st->size() == 1);
	assert(st->elementStack() == 1);
	assert(st->isEmptyStack() == false);
}

void testSchlange()
{
	Schlange<int>* c = new Schlange<int>;
	assert(c->isEmptySchlange());
	c->addSchlange(1);
	c->addSchlange(2);
	c->addSchlange(3);
	assert(c->elemSchlange() == 1);
	assert(c->size() == 3);
	assert(c->isEmptySchlange() == false);
	c->delSchlange();
	assert(c->size() == 2);
	assert(c->elemSchlange() == 2);
}