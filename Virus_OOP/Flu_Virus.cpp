#include "stdafx.h"
#include "Flu_Virus.h"

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

int Flu_Virus::InitResistance(int number_1,int number_2)
{
	return rand() % (number_2 - number_1 + 1) + number_1; // trả về random từ number 1 -> number 2
}
