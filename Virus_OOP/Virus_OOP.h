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
	void LoadADNInformation​();
	int ReduceResistance​(int medicine_resistance);
	void Set_m_resistance(int m_resistance);
	virtual void DoBorn() {};
	//virtual list<Virus>  DoClone();
	//virtual void DoDie();
	virtual int InitResistance(int number_1, int number_2) { return 0; };
};