﻿#include "stdafx.h"
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
	int number_name = rand() % 3 + 3;
	if (number_name == 3)
	{
		this->m_protein = "NS3";
		cout << this->m_protein << " ";
		this->SetResistance(InitResistance(1,10));				// 1-10 máu
	}
	else if (number_name == 4)
	{
		this->m_protein = "NS5";
		cout << this->m_protein << " ";
		this->SetResistance(InitResistance(11, 20));			// 11-20 máu
	}
	else
	{
		this->m_protein = "E";
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
	Varus *virus_1 = new Dengue_Virus(this); // sao chép
	Varus *virus_2 = new Dengue_Virus(this);	// sao chép thêm 1 con
	list<Varus*> clonevirus;				// tạo list	
	clonevirus.push_back(virus_1);			// add 2 con vào
	clonevirus.push_back(virus_2);
	return clonevirus;						// trả về list
}

Dengue_Virus::Dengue_Virus(const Dengue_Virus * dengue_virus):Varus(dengue_virus)
{
	m_protein = new char[4];
	this->m_protein = dengue_virus->m_protein;
}

int Dengue_Virus::InitResistance(int number_1, int numner_2)
{
	return rand() % (numner_2 - number_1 + 1) + number_1; // trả về random từ number 1 -> number 2

}
