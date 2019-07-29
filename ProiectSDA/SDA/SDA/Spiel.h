#pragma once
#include <iostream>
#include "Stack.h"
#include "Schlange.h"
#include <string>
#include <vector>

using namespace std;


void create_Spiel(int n, Stack<std::string>* st1, Stack<std::string>* st2);

void remakeStack(Stack<std::string>* st, Schlange<std::string>* c);

void gewinner(Stack<std::string>* st1, Stack<std::string>* st2);

void create_Spiel_Vektor(std::vector<std::string> v, Stack<std::string>* st1, Stack<std::string>* st2);