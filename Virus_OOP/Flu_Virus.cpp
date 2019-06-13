#include "stdafx.h"
#include "Flu_Virus.h"
#include <iostream>

using namespace std;

Flu_Virus::Flu_Virus()
{
}

Flu_Virus::~Flu_Virus()
{
}

Flu_Virus::Flu_Virus(Flu_Virus * flu_virus):Virus(flu_virus)
{
	this->color = flu_virus->color;
	cout << color ;
}

void Flu_Virus::DoBorn()
{
	LoadADNInformation​();
	this->color = rand() % 2 + 1;
	if (this->color == 1)
	{
		this->Set_m_resistance=InitResistance(10, 20);
	}
	else
	{
		this->Set_m_resistance = InitResistance(10,15);
	}
}

int Flu_Virus::InitResistance(int number_1,int number_2)
{
	return rand() % (number_2 - number_1 + 1) + number_1; // trả về random từ number 1 -> number 2
}
