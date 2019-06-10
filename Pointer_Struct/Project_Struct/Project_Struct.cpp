
#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#define MAX 100

using namespace std;

void Select(int);

struct Studient
{
	int id;
	float score;
	string name;
};

Studient* studient[MAX];

int PrintMenu()
{
	int choose;
	cout << "--------------MENU-----------" << endl;
	cout << "1. Input" << endl;
	cout << "2. Display" << endl;
	cout << "3. Save to file " << endl;
	cout << "4. Load from file" << endl;
	cout << "0. Exit" << endl;
	cout << "-----------------------------" << endl;
	cout << "Choose: ";
	cin >> choose;
	return choose;
}

void InputStudient()
{
	Studient studient;
	cout << "INPUT INFORMATION STUDIENT " << endl;
	cout << "INPUT ID:";
	cin >> studient.id;
	cin.ignore();
	cout << "INPUT NAME:";
	getline(cin, studient.name);
	cout << "INPUT SCORE:";
	cin >> studient.score;
	while (studient.score < 0 || studient.score>10)
	{
		cout << "ERRO INPUT" << endl;
		cout << "INPUT SCORE AGAIN:";
		cin >> studient.score;
	}
	system("cls");
	cout << "ADD STUDIENT SUCCESS" << endl;
	int choose = PrintMenu();
	Select(choose);
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



void main()
{
	int choose;
	choose = PrintMenu();
	Select(choose);
	system("pause");
}

