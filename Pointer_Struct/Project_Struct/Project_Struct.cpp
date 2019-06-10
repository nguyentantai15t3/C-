
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

struct Studient
{
	int id;
	float score;
	string name;
};

void InputStudient(Studient std[])
{

}

int PrintMenu()
{
	int i;
	cout << "--------------MENU-----------" << endl;
	cout << "1. Input" << endl;
	cout << "2. Display" << endl;
	cout << "3. Save to file " << endl;
	cout << "4. Load from file" << endl;
	cout << "0. Exit" << endl;
	cout << "-----------------------------" << endl;
	cout << "Choose: ";
	cin >> i;
	return i;
}

void main()
{
	//Studient std[100];
	int choose = PrintMenu();
	switch (choose)
	{
	case 1:
		//InputStudient();
	case 2:
		//Display();
	case 3: 
		//SaveToFile();
	case 4:
		//LoadToFile();
	case 0:
		break;
	default:
		break;
	}
	system("pause");
}

