
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

void InputStudient()
{
	cout << "This is InputStudient Function " << endl;
}

void Display()
{
	cout << "This is Display Function " << endl;
}

void SaveToFile()
{
	cout << "This is SaveToFile Function " << endl;
}

void LoadToFile()
{
	cout << "This is LoadToFile Function " << endl;
}

void Select(int select)
{
	switch (select)
	{
	case 1:
		InputStudient();
		break;
	case 2:
		Display();
		break;
	case 3:
		SaveToFile();
		break;
	case 4:
		LoadToFile();
		break;
	case 0:
		break;
	default:
		break;
	}
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
	Select(choose);
	system("pause");
}

