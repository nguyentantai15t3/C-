#include "stdafx.h"
#include "Patient.h"
#include "Flu_Virus.h"
#include "Dengue.h"
#include "Varus.h"
#include <iostream>

using namespace std;

Patient::Patient()
{
	this->DoStart();
	this->m_resistance = this->InitResistance(1000, 3000);			// 1000->3000
}

Patient::~Patient()
{
}

inline int Patient::InitResistance(int number_1, int number_2)
{
	int rad =  rand() % (number_2 - number_1 + 1) + number_1;		// random máu của bệnh nhân
	cout << "Resistance of Patient = " << rad << endl;
	return rad;
}

int Patient::InitMecdicien_Resistance(int number_1, int number_2)
{
	int rad = rand() % (number_2 - number_1 + 1) + number_1;		// random máu của bệnh nhân
	cout << "Mecdicien Resistance ("<<number_1<<","<<number_2<<") = " << rad << endl;
	return rad;
}

void Patient::DoStart()
{
	int value_random_virus = rand() % 11 + 10;	// random số lượng virut từ 10 -> 20 con
	this->m_state = 1;	// trạng thái
	Varus* virus;
	for (int i = 0; i < value_random_virus; i++)// random virut
	{
		int type_virus = rand() % 2 + 1;		// loại 1 hoặc 2
		if (type_virus == 1)					// loại Flu
		{	
			cout << "Flu_Virus ";
			virus = new Flu_Virus();		// tạo virus Flu
			this->m_virusList.push_back(virus);		// thêm vào list virus
		}
		else
		{
			cout << "Dengue_Virus ";
			virus = new Dengue_Virus();		// tạo virus Dengue
			this->m_virusList.push_back(virus);				// thêm vào list virus
		}
	}

}

void Patient::TakeMedicine(int medicine_resistance)	// uống thuốc
{
	auto member_virusList = this->m_virusList.begin();	// khai báo con trỏ trỏ đến vị trí đầu list
	int size = this->m_virusList.size();
	for (int i = 0; i < size; i++)
	{
		if ((*member_virusList)->ReduceResistance​(medicine_resistance) <= 0) // máu virus <=0
		{
			(*member_virusList)->DoDie();
			this->m_virusList.erase(member_virusList++);		// xóa khỏi list và tăng con trỏ lên
		}
		else
		{
			list<Varus*> clonelist = (*member_virusList)->DoClone(); // lấy mảng clone
	
			this->m_virusList.insert(this->m_virusList.end(),clonelist.begin(),clonelist.end()); // add vào list hiện tại
			member_virusList++;	// tăng con trỏ 
		}
	}
}

int Patient::GetState()
{
	return this->m_state;
}

void Patient::SetState(int state)
{
	this->m_state = state;
}

int Patient::GetVirusList()
{
	return this->m_virusList.size();
}

int Patient::ResistanceOfAllVirus()
{
	int healthofvirus = 0;
	auto member_virusList = this->m_virusList.begin();	// khai báo con trỏ trỏ đến vị trí đầu list
	for (int i = 0; i < this->m_virusList.size(); i++)
	{
		healthofvirus += (*member_virusList)->GetResistance();
		member_virusList++;
	}
	return healthofvirus;
}

int Patient::GetResistance()
{
	return this->m_resistance;
}

