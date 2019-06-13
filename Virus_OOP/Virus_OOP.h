#pragma once
#include <list>

class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	Virus(const Virus *virus);
	~Virus();
	void LoadADNInformation​();
	void ReduceResistance​(int medicine_resistance);
	virtual void DoBorn();
	virtual list<Virus>  DoClone();
	virtual void DoDie();
	virtual void InitResistance();

};