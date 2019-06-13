#include "stdafx.h"
#include "Dengue.h"

Dengue_Virus::Dengue_Virus()
{
}

Dengue_Virus::~Dengue_Virus()
{
}

Dengue_Virus::Dengue_Virus(Dengue_Virus * dengue_virus):Virus(dengue_virus)
{
	this->m_protein = dengue_virus->m_protein;
}
