#pragma once
#include<string>
#include "Varus.h"

class Flu_Virus:public Varus
{
public:
	Flu_Virus();
	~Flu_Virus();
	Flu_Virus(const Flu_Virus* flu_virus);
	void DoBorn() override;
	void DoDie() override;
	list<Varus *>  DoClone() override;
	int InitResistance(int number_1,int numner_2) override;
private:
	int color;

};