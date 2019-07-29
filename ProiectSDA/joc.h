#pragma once

#include <iostream>
#include "Stiva.h"
#include "Coada.h"
#include <string>
#include <vector>

using namespace std;


void creeazaJoc(int n, Stiva<std::string>* st1, Stiva<std::string>* st2);

void refacereStiva(Stiva<std::string>* st, Coada<std::string>* c);

void castigator(Stiva<std::string>* st1, Stiva<std::string>* st2);

void creeazaJocVector(std::vector<std::string> v, Stiva<std::string>* st1, Stiva<std::string>* st2);