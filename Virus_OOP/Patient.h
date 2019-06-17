#pragma once
#include "Varus.h"
#include <list>

using namespace std;

class Patient
{
public:
	Patient();
	~Patient();
	int InitResistance(int number_1, int number_2);
	int InitMecdicien_Resistance(int number_1, int number_2);
	void DoStart();
	void TakeMedicine(int medicine_resistance);
	int GetState();
	void SetState(int state);
	int GetVirusList();
	int ResistanceOfAllVirus();
	int GetResistance();

private:
	int m_resistance;
	list<Varus*> m_virusList;
	int m_state;
};