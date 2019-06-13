#pragma once

class Virus
{
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

private:
	char* m_dna;
	int m_resistance;
};