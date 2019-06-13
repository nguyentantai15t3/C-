#include "stdafx.h"
#include "Dengue.h"

Dengue_Virus::Dengue_Virus()
{
}

Dengue_Virus::~Dengue_Virus()
{
}

Dengue_Virus::Dengue_Virus(Dengue_Virus * dengue_virus):Virus(dengue_virus)
{
	this->m_protein = dengue_virus->m_protein;
}

int Dengue_Virus::InitResistance(int number_1, int numner_2)
{
	return rand() % (numner_2 - number_1 + 1) + number_1; // trả về random từ number 1 -> number 2

}
