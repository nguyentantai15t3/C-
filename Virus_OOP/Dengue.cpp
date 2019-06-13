#include "stdafx.h"
#include "Dengue.h"

Dengue_Virus::Dengue_Virus()
{
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
		this->Set_m_resistance = InitResistance(1,10);
	}
	else if (number_name==2)
	{
		this->m_protein = "NS5";
		this->Set_m_resistance = InitResistance(11, 20);
	}
	else
	{
		this->m_protein = "E";
		this->Set_m_resistance = InitResistance(21, 30);
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
