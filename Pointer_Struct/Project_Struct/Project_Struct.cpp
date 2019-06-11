
#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
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
int checkID(int id)
{
	for (int i = 0; i < length; i++)
	{
		if (id == studient[i].id) return false;
	}
	
	return true;
}
void InputStudient()
{
	int temp;
	system("cls");
	cout << "INPUT INFORMATION STUDIENT " << endl;
	cout << "INPUT ID:";
	cin >> temp;
	cin.ignore();
	while (!checkID(temp))
	{
		cout << "ERRO INPUT, INPUT ID AGAIN:";
		cin >> temp;
		cin.ignore();
	};
	studient[length].id = temp;
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

void SaveToFile(string fileName)
{
	ofstream outFile;
	outFile.open(fileName);
	if (outFile.is_open())
	{
		//save number
		for (int i = 0; i < length; i++)
		{
			Studient std = studient[i];

			string name(std.name);

			//Replace(name, ' ', '_');

			outFile << std.id << " " << name << " " << std.score << endl;
		}

		cout << "Save to " << fileName << endl;

		outFile.close();
	}
	else
	{
		cout << "ERROR" << endl;
	}
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
		SaveToFile("saveFile.dat");
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

