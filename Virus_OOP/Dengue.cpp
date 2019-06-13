#include "stdafx.h"
#include "Dengue.h"
#include <iostream>

using namespace std;

Dengue_Virus::Dengue_Virus()
{
	DoBorn();
}

Dengue_Virus::~Dengue_Virus()
{
}

void Dengue_Virus::DoBorn()
{
	this->LoadADNInformation​();
	int number_name = rand() % 3 + 1;
	if (number_name == 1)
	{
		this->m_protein = "NS3";
		cout << this->m_protein << endl;
		this->Set_m_resistance(InitResistance(1,10));			// 1-10 máu
	}
	else if (number_name==2)
	{
		this->m_protein = "NS5";
		cout << this->m_protein << endl;
		this->SetResistance(InitResistance(11, 20));			// 11-20 máu
	}
	else
	{
		this->m_protein = "E";
		cout << this->m_protein << endl;
		this->SetResistance(InitResistance(21, 30));			// 21-30 máu
	}
}

Dengue_Virus::Dengue_Virus(Dengue_Virus * dengue_virus):Virus(dengue_virus)
{
	this->m_protein = dengue_virus->m_protein;
}

int Dengue_Virus::InitResistance(int number_1, int numner_2)
{
	return rand() % (numner_2 - number_1 + 1) + number_1; // trả về random từ number 1 -> number 2

}
