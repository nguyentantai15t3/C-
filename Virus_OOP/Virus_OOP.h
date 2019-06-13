#pragma once

class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	Virus(const Virus *virus);
	~Virus();
	virtual void LoadADNInformation​();
	virtual void ReduceResistance​();
	virtual void DoBorn();
	virtual void DoClone();
	virtual void DoDie();
	virtual void InitResistance();

};