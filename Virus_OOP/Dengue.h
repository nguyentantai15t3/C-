#pragma once
#include<string>
#include "Virus_OOP.h"

using namespace std;

class Dengue_Virus:public Virus
{
public:
	Dengue_Virus();
	~Dengue_Virus();
	void DoBorn() override;
	Dengue_Virus(Dengue_Virus* dengue_virus);
	int InitResistance(int number_1, int numner_2) override;
private:
	string m_protein;
};