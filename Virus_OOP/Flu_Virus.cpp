﻿#include "stdafx.h"
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
}

void Flu_Virus::DoBorn()
{
	this->LoadADNInformation​();
	this->color = rand() % 2 + 1;
	if (this->color == 1)
	{
		cout << "Red color" << endl;
		this->Set_m_resistance=InitResistance(10, 20); // 10-20 máu
	}
	else
	{
		cout << "Blue color" << endl;
		this->Set_m_resistance = InitResistance(10,15); // 10-15 máu
	}
}

int Flu_Virus::InitResistance(int number_1,int number_2)
{
	return rand() % (number_2 - number_1 + 1) + number_1; // trả về random từ number 1 -> number 2
}
