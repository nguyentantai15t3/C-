#pragma once
#include "Virus_OOP.h"
#include <list>

using namespace std;

class Patient
{
public:
	Patient();
	~Patient();
	int InitResistance(int number_1, int number_2);
	void DoStart();
	//void TakeMedicine();


private:
	int m_resistance;
	list<Virus*> m_virusList;
	int m_state;
}
