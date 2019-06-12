#include "stdafx.h"
#include "Task_OOP.h"
#include <iostream>

using namespace std;

void main()
{
	MyPoint* P1 = new MyPoint();
	MyPoint* P2 = new MyPoint();
	P1->SetX(2);
	P1->SetY(1);
	P1->Display();
	P2->SetX(6);
	P2->SetY(4);
	P2->Display();
	cout <<"Distance between current point and p: "<< P1->Distance(P2) << endl;
	system("pause");
}