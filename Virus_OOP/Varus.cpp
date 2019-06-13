#include "stdafx.h"
#include "Varus.h"
#include <fstream>
#include <iostream>

using namespace std;

Varus::Varus()
{
	this->m_dna = "";
	this->m_resistance = 0;
}

Varus::Varus(const Varus* varus)
{
	this->m_dna = varus->m_dna;
	this->m_resistance = varus->m_resistance;
}

Varus::~Varus() {}

void Varus::LoadADNInformation​()
{
	ifstream inFile;
	inFile.open("ATGX.bin");
	if (inFile.is_open())
	{
		char a[100];
		inFile >> a;
		m_dna = (char *)a;
	}
	else
	{
		cout << "LOAD ERROR" << endl;
	}
	cout << this->m_dna << endl;
}

int Varus::ReduceResistance​(int medicine_resistance)
{
	return this->m_resistance = this->m_resistance - medicine_resistance; // trả về máu của virus
}

void Varus::SetResistance(int m_resistance)
{
	this->m_resistance=m_resistance;
	cout << this->m_resistance << endl;
}



