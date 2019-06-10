
#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#define MAX 100

using namespace std;

void Select(int);
static int length = 0;

struct Studient
{
	int id;
	float score;
	string name;
};

Studient* studient = new Studient[MAX];

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
void checkID()
{

}
void InputStudient()
{
	system("cls");
	cout << "INPUT INFORMATION STUDIENT " << endl;
	cout << "INPUT ID:";
	cin >> studient[length].id;
	cin.ignore();
	cout << "INPUT NAME:";
	getline(cin, studient[length].name);
	cout << "INPUT SCORE:";
	cin >> studient[length].score;
	while (studient[length].score < 0 || studient[length].score>10)
	{
		cout << "ERRO INPUT" << endl;
		cout << "INPUT SCORE AGAIN:";
		cin >> studient[length].score;
	}
	system("cls");
	length++;
	cout << "ADD STUDIENT SUCCESS" << endl;
	int choose = PrintMenu();
	Select(choose);
}

void Display()
{
	system("cls");
	cout << "ID\tNAME\tSCORE" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << studient[i].id << "\t" << studient[i].name << "\t" << studient[i].score << endl;
	}
	cout << endl << endl;
	int choose = PrintMenu();
	Select(choose);
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

