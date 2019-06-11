
#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#define MAX 100

using namespace std;

void Select(int);
static int length = 0; // đếm số phần tử của struct

struct Studient
{
	int id;
	float score;
	string name;
};

Studient* studient = new Studient[MAX];

int PrintMenu() // In menu 
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
int CheckID(int id) // check trùng OD
{
	Studient* ptr = &studient[0]; 

	for (int i = 0; i < length-1; i++)
	{
		if (id == ((ptr + i)->id))
		{
			return false;
		}
	}
	return true;
}
void InputStudient() // Nhập sinh viên
{
	Studient* ptr = &studient[length]; // con trỏ ptr trỏ tới studient[length];
	system("cls");
	cout << "INPUT INFORMATION STUDIENT " << endl;
	cout << "INPUT ID:";
	cin >> ptr -> id;
	cin.ignore();
	while (!CheckID(ptr -> id)) // false thì nhập lại
	{
		cout << "ERRO INPUT, INPUT ID AGAIN:";
		cin >> ptr -> id;
		cin.ignore();
	};
	cout << "INPUT NAME:";
	getline(cin, ptr->name);
	cout << "INPUT SCORE:";
	cin >> ptr->score;
	while (ptr->score < 0 || ptr->score>10) // điểm lỗi thì nhập lại
	{
		cout << "ERRO INPUT" << endl;
		cout << "INPUT SCORE AGAIN:";
		cin >> ptr->score;
	}
	system("cls");
	length++;
	cout << "ADD STUDIENT SUCCESS" << endl;
	int choose = PrintMenu();			// Quay lại menu
	Select(choose);						// Kiểm tra lựa chọn
}

void Display()
{
	Studient* ptr = &studient[0];		// trỏ tới phần tử đầu tiên của struct
	system("cls");
	cout << "ID\tNAME\tSCORE" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << (ptr+i)->id << "\t" << (ptr + i)->name << "\t" << (ptr + i)->score << endl;
	}
	cout << endl << endl;
	int choose = PrintMenu();
	Select(choose);
}

void SaveToFile(string fileName)		// save file
{
	ofstream outFile;
	outFile.open(fileName);				// mở file_name
	if (outFile.is_open())
	{
		//save number
		outFile << length << endl;

		for (int i = 0; i < length; i++)
		{
			Studient* ptr = &studient[i];

			string name(ptr->name);

			//Replace(name, ' ', '_');

			outFile << ptr->id << " " << ptr->name << " " << ptr->score << endl;
		}
		system("cls");
		cout << "Save to " << fileName << " success." << endl << endl;

		outFile.close();
	}
	else
	{
		system("cls");
		cout << "ERROR" << endl;
	}
	int choose = PrintMenu();			// Quay lại menu
	Select(choose);						// Kiểm tra lựa chọn
}

void LoadToFile(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);

	if (inFile.is_open())
	{
		int number; // số lượng phần tử struct

		inFile >> number;

		for (int i = 0; i < number; i++)
		{
			Studient* ptr = &studient[i];

			inFile >> ptr->id;
			inFile >> ptr->name;
			inFile >> ptr->score;

			//Replace(std.name, '_', ' ');
			//studient.push_back(std);
		}

		inFile.close();
		system("cls");
		cout << "Load to " << fileName << " success." << endl << endl ;
	}
	else
	{
		system("cls");
		cout << "LOAD ERROR" << endl;
	}
	int choose = PrintMenu();			// Quay lại menu
	Select(choose);						// Kiểm tra lựa chọn

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
		LoadToFile("saveFile.dat");
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

