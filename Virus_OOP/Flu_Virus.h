#pragma once
#include<string>
#include "Virus_OOP.h"

class Flu_Virus:public Virus
{
public:
	Flu_Virus();
	~Flu_Virus();
	Flu_Virus(Flu_Virus* flu_virus);

private:
	int color;

};