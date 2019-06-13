#include "Patient.h"
#include "Flu_Virus.h"

Patient::Patient()
{
	DoStart();
	DoStart();
}

Patient::~Patient()
{
}

inline int Patient::InitResistance(int number_1, int number_2)
{
	return rand() % (number_2 - number_1 + 1) + number_1;
}

inline void Patient::DoStart()
{
	int value_random_virus = rand() % 11 + 10; // 10 - 20
	this->m_state = 1;
	for (int i = 0; i < value_random_virus; i++)
	{
		int type_virus = rand() % 2 + 1; // 1 or 2
		if (type_virus = 1)
		{
			Flu_Virus* flu_Virus = new Flu_Virus();
			
		}
	}
}