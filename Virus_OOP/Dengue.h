#pragma once
#include<string>
#include "Varus.h"

using namespace std;

class Dengue_Virus:public Varus
{
public:
	Dengue_Virus();
	~Dengue_Virus();
	Dengue_Virus(Dengue_Virus* dengue_virus);
	int InitResistance(int number_1, int numner_2) override;
	void DoBorn() override;
	void DoDie() override;
	list<Varus *>  DoClone() override;

private:
	string m_protein;
};