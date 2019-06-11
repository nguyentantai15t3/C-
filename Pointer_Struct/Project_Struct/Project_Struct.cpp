
#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#define MAX 100

using namespace std;

void Select(int);
void Replace(string &, char, char);
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
int CheckID(int id) // check trùng ID và chữ
{
	Studient* ptr = studient; 
	for (int i = 0; i < length; i++)
	{
		if (id == (ptr++)->id)
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
		cout << "ERROR INPUT, INPUT ID AGAIN:";
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
	length++;							// tăng số phần tử lên 1 đơn vị
	cout << "ADD STUDIENT SUCCESS" << endl;
	int choose = PrintMenu();			// Quay lại menu
	Select(choose);						// Kiểm tra lựa chọn
}

void Display()							// hàm hiển trị danh sách sinh viên
{
	if (length == 0)
	{
		system("cls");
		cout << "NULL" << endl << endl;
	}
	else
	{
		Studient* ptr = studient;		// trỏ tới phần tử đầu tiên của struct
		system("cls");
		cout << "ID\tNAME\t\tSCORE" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << (ptr + i)->id << "\t" << (ptr + i)->name << "\t\t" << (ptr + i)->score << endl;
		}
		cout << endl << endl;
	}
	int choose = PrintMenu();
	Select(choose);
}

void SaveToFile(string fileName)		// save file (tên file lưu)
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

			Replace(name,' ', '_');

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
	
	studient = new Studient[MAX];
	ifstream inFile;
	inFile.open(fileName);

	if (inFile.is_open())
	{
		inFile >> length;
		Studient* ptr = &studient[0];

		for (int i = 0; i < length; i++)
		{
			inFile >> (ptr+i)->id;
			inFile >> (ptr+i)->name;
			inFile >> (ptr+i)->score;

			Replace(ptr->name, '_', ' ');
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
	Display();
	int choose = PrintMenu();			// Quay lại menu
	Select(choose);						// Kiểm tra lựa chọn

}

void Replace(string &str, char to, char by)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == to)
		{
			str.at(i) = by;
		}
	}
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
		exit(0);
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

