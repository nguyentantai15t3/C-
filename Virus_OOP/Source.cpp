#include "stdafx.h"
#include <iostream>
#include "Patient.h"
#include <time.h>
#include "vld.h"

using namespace std;

void main()
{
	srand(time(NULL));
	Patient patient;
	char t = 0;
	while ((patient.GetState()==1 && patient.GetVirusList()>0))
	{
		if (patient.ResistanceOfAllVirus() > patient.GetResistance())
		{
			patient.SetState(0);
			break;
		}
		cout << patient.GetVirusList() << " virus exist in patients" << endl;
		cout << "Health of all viruss is " << patient.ResistanceOfAllVirus() << endl << endl;
		cout << "Take Medicine (0 = NO, 1 = YES) : ";
		cin >> t;
		cin.ignore();
		if (t == 49) // 49 là kí tự 1 :D
		{
			patient.TakeMedicine(patient.InitMecdicien_Resistance(6,10)); // random thuốc 6-10 dame
		}
		else if (t == 48) // 0
		{
			exit(0);
		}
		else
		{
			cout << "Error, Input again" << endl;
			continue;
		}
	}
	if (patient.GetState() == 0)
	{
		cout << "The patient is dead" << endl;
	}
	else
	{
		cout << "The patient has healed" << endl;
	}
	system("pause");
}