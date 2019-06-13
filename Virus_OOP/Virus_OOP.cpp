#include "stdafx.h"
#include "Virus_OOP.h"

using namespace std;

Virus::Virus()
{
	this->m_dna;
	this->m_resistance = 10;
}

Virus::Virus(const Virus* viruss)
{

}


Virus::~Virus() {};