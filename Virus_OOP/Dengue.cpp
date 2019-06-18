#pragma warning( disable : 4996)
#include "stdafx.h"
#include "Dengue.h"
#include <iostream>
#include <string>

using namespace std;

Dengue_Virus::Dengue_Virus()
{
	this->DoBorn();
}

Dengue_Virus::~Dengue_Virus()
{
}

void Dengue_Virus::DoBorn()
{
	this->LoadADNInformation​();
	int number_name = rand() % 3;
	string s;
	if (number_name == 0)
	{
		s = "NS3";
		for (int i = 0; i < s.size(); i++)
		{
			this->m_protein[i] = s[i];
		}
		cout << this->m_protein << " ";
		this->SetResistance(InitResistance(1,10));				// 1-10 máu
	}
	else if (number_name == 1)
	{
		s = "NS5";
		for (int i = 0; i < s.size(); i++)
		{
			this->m_protein[i] = s[i];
		}
		cout << this->m_protein << " ";
		this->SetResistance(InitResistance(11, 20));			// 11-20 máu
	}
	else
	{
		s = "E";
		for (int i = 0; i < s.size(); i++)
		{
			this->m_protein[i] = s[i];
		}
		cout << this->m_protein << " ";
		this->SetResistance(InitResistance(21, 30));			// 21-30 máu
	}
}

void Dengue_Virus::DoDie()
{
	delete this;
}

list<Varus*> Dengue_Virus::DoClone()
{
	Dengue_Virus *virus;
	list<Varus*> clonevirus;					// tạo list	
	virus = new Dengue_Virus(this);			// sao chép
	clonevirus.push_back(virus);				// add vào
	virus = new Dengue_Virus(this);			// sao chép
	clonevirus.push_back(virus);				// add vào
	return clonevirus;							// trả về list
}

Dengue_Virus::Dengue_Virus(const Dengue_Virus* dengue_virus):Varus(dengue_virus)
{
	strcpy_s(this->m_protein, 4 , dengue_virus->m_protein);
}

int Dengue_Virus::InitResistance(int number_1, int numner_2)
{
	return rand() % (numner_2 - number_1 + 1) + number_1; // trả về random từ number 1 -> number 2
}
