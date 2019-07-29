#pragma once

#include <iostream>
#include "Stack.h"
#include "Schlange.h"
#include <string>
#include <vector>

using namespace std;

void createGame(int n, Stack<std::string>* st1, Stack<std::string>* st2);

void rebuildStack(Stack<std::string>* st, Schlange<std::string>* c);

void winner(Stack<std::string>* st1, Stack<std::string>* st2);

void createGameVct(std::vector<std::string> v, Stack<std::string>* st1, Stack<std::string>* st2);

void afisare(Stack<std::string>* st1, Stack<std::string>* st2);