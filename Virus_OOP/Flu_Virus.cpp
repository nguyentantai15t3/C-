#include "stdafx.h"
#include "Flu_Virus.h"

Flu_Virus::Flu_Virus()
{
}

Flu_Virus::~Flu_Virus()
{
}

Flu_Virus::Flu_Virus(Flu_Virus * flu_virus):Virus(flu_virus)
{
	this->color = flu_virus->color;
}
