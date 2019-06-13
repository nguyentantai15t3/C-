#include "stdafx.h"
#include "Virus_OOP.h"

using namespace std;

Virus::Virus()
{
}

Virus::Virus(const Virus* viruss)
{
	this->m_dna = viruss->m_dna;
	this->m_resistance = viruss->m_resistance;
}

Virus::~Virus() {};