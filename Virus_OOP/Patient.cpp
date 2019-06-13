#include "stdafx.h"
#include "Patient.h"
#include "Flu_Virus.h"
#include "Dengue.h"
#include "Varus.h"

using namespace std;

Patient::Patient()
{
	this->DoStart();
	this->m_resistance = this->InitResistance(1000, 9000);
}

Patient::~Patient()
{
}

inline int Patient::InitResistance(int number_1, int number_2)
{
	return rand() % (number_2 - number_1 + 1) + number_1;		// random máu của bệnh nhân
}

inline void Patient::DoStart()
{
	int value_random_virus = rand() % 11 + 10;	// random số lượng virut từ 10 -> 20 con
	this->m_state = 1;							// trạng thái
	for (int i = 0; i < value_random_virus; i++)// random virut
	{
		int type_virus = rand() % 2 + 1;		// loại 1 hoặc 2
		if (type_virus == 1)					// loại Flu
		{	
			Flu_Virus* flu_virus = new Flu_Virus();		// tạo virus Flu
			this->m_virusList.push_back(flu_virus);		// thêm vào list virus
		}
		else
		{
			Dengue_Virus* dengua_virus = new Dengue_Virus();		// tạo virus Dengue
			this->m_virusList.push_back(dengua_virus);				// thêm vào list virus
		}
	}
}

void Patient::TakeMedicine()	// uống thuốc
{
	int medicine_resistance = rand() % 60 + 1;			// dame thuốc random từ 1-60
	auto member_virusList = this->m_virusList.begin();	// khai báo con trỏ trỏ đến vị trí đầu list
	for (int i = 0; i < this->m_virusList.size(); i++)
	{
		if ((*member_virusList)->ReduceResistance​(medicine_resistance) <= 0) // máu virus <=0
		{
			(*member_virusList)->DoDie();
			this->m_virusList.erase(member_virusList++);
		}
		else
		{
			list<Varus*> clonelist = (*member_virusList)->DoClone();
			this->m_virusList.insert(this->m_virusList.end(),clonelist.begin(),clonelist.end();
			member_virusList++;
		}
	}
}
