#pragma once
#include<string>
#include "Virus_OOP.h"

using namespace std;

class Dengue_Virus:public Virus
{
public:
	Dengue_Virus();
	~Dengue_Virus();
	Dengue_Virus(Dengue_Virus* dengue_virus);

private:
	string m_protein;
};