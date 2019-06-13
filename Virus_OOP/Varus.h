#pragma once

class Varus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Varus();
	Varus(const Varus *varus);
	~Varus();
	void LoadADNInformation​();
	int ReduceResistance​(int medicine_resistance);
	void SetResistance(int m_resistance);
	virtual void DoBorn() {};
	//virtual list<Virus>  DoClone();
	//virtual void DoDie();
	virtual int InitResistance(int number_1, int number_2) { return 0; };
};