#include "stdafx.h"
#include "Virus_OOP.h"
#include <fstream>
#include <iostream>

using namespace std;

Virus::Virus()
{
}

Virus::Virus(const Virus* viruss)
{
	this->m_dna = viruss->m_dna;
	this->m_resistance = viruss->m_resistance;
}

Virus::~Virus() {}

void Virus::LoadADNInformation​()
{
	ifstream inFile;
	inFile.open("ATGX.bin");
	if (inFile.is_open())
	{
		inFile >> this->m_dna;
	}
	else
	{
		cout << "LOAD ERROR" << endl;
	}
	cout << this->m_dna << endl;
}

int Virus::ReduceResistance​(int medicine_resistance)
{
	return this->m_resistance = this->m_resistance - medicine_resistance; // trả về máu của virus
}

void Virus::Set_m_resistance(int m_resistance)
{
	this->m_resistance=m_resistance;
	cout << this->m_resistance << endl;
}



