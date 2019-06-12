#include "Task_OOP.h"
#include <iostream>

void main()
{
	MyPoint *P1 = new MyPoint(2, 3);
	MyPoint *P2 = new MyPoint(3, 4);
	cout << P1->Distance(*P2) << endl;
}