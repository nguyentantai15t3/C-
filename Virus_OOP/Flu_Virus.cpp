#include "stdafx.h"
#include "Flu_Virus.h"
#include <iostream>

using namespace std;

Flu_Virus::Flu_Virus()
{
	this->DoBorn();
}

Flu_Virus::~Flu_Virus()
{
}

Flu_Virus::Flu_Virus(const Flu_Virus* flu_virus):Varus(flu_virus)
{
	this->color = flu_virus->color;
}

void Flu_Virus::DoBorn()
{
	this->LoadADNInformation​();
	this->color = rand() % 2;
	if (this->color == 0)
	{
		cout << "Red_color " ;
		this->SetResistance(InitResistance(10, 20)); // 10-20 máu
	}
	else
	{
		cout << "Blue_color " ;
		this->SetResistance(InitResistance(10,15)); // 10-15 máu
	}
}

void Flu_Virus::DoDie()
{
	delete this;
}

list<Varus *> Flu_Virus::DoClone()
{
	Flu_Virus *virus = new Flu_Virus(this); // sao chép
	list<Varus*> clonevirus; // tạo list mới
	clonevirus.push_back(virus); // add vào
	return clonevirus; // trả về list
}

int Flu_Virus::InitResistance(int number_1,int number_2)
{
	return rand() % (number_2 - number_1 + 1) + number_1; // trả về random từ number 1 -> number 2
}

int Flu_Virus::GetCoLor()
{
	return this->color;
}
