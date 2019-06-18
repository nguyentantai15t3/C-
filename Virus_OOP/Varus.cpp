#pragma warning(disable:4996)
#include "stdafx.h"
#include "Varus.h"
#include <fstream>
#include <iostream>
#include <string>
#include <list>

using namespace std;

Varus::Varus()
{
}

Varus::Varus(const Varus* varus)
{
	this->m_resistance = varus->m_resistance;
	this->m_dna = new char[strlen(varus->m_dna)];
	for (int i = 0; i < strlen(varus->m_dna); i++)
	{
		this->m_dna[i] = varus->m_dna[i];
	}
}

Varus::~Varus() 
{
	delete[]this->m_dna;
}

void Varus::LoadADNInformation​()
{
	ifstream inFile;
	inFile.open("ATGX.bin");
	if (inFile.is_open())
	{
		string str;
		getline(inFile, str);
		this->m_dna = new char[str.length() + 1];
		for (int i = 0; i < str.size(); i++)
		{
			this->m_dna[i] = str[i];
		}
	}
	else
	{
		cout << "LOAD ERROR" << endl;
	}
}

bool Varus::ReduceResistance​(int medicine_resistance)
{
	this->m_resistance -= medicine_resistance;
	if (this->m_resistance <= 0) {
		return true;
	}
	return false;
}

void Varus::SetResistance(int m_resistance) // set lại máu của virus
{
	this->m_resistance=m_resistance;
	cout << this->m_resistance << endl;
}

int Varus::GetResistance()
{
	return this->m_resistance;
}



