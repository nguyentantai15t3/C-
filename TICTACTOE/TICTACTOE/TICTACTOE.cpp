// TICTACTOE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int isPlay ;
int row, column;
const int max = 3;


// bàn cờ hiện tại
void printSquare(int square[][max])
{
	system("cls");

	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[0][0] << "  |  " << square[0][1] << "  |  " << square[0][2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[1][0] << "  |  " << square[1][1] << "  |  " << square[1][2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[2][0] << "  |  " << square[2][1] << "  |  " << square[2][2] << endl;

	cout << "     |     |     " << endl << endl;
} 

// Đánh vào bàn cờ
void checkPoint(int square[][max])
{
	if (isPlay == 1) // lượt người 1
	{
		do
		{
			cout << " (1) Nhap vi tri danh row - column :";
			cin >> row >> column;
		} while ((row < 0) || (row > 2) || (column < 0) || (column > 2) || (square[row][column] != 0));  // check vị trị ngoài bàn cờ và đã có giá trị
		square[row][column] = 1;
		printSquare(square); // in bàn cờ vừa đánh
		isPlay = 2; // đổi lượt
	}
	else // lượt người 2
	{
		do
		{
			cout << " (2) Nhap vi tri danh row - column :";
			cin >> row >> column;
		} while ((row < 0) || (row > 2) || (column < 0) || (column > 2) || (square[row][column] != 0)); // check vị trị ngoài bàn cờ và đã có giá trị
		square[row ][column] = 2;
		printSquare(square); // in bàn cờ vừa đánh
		isPlay = 1; // đổi lượt
	}
} 

// Check hàng ngang
int checkRow(int square[][max], int x)
{
	/*if ((square[x][0] == square[x][1]) && (square[x][1] == square[x][2]) && (square[x][1] != 0))
	{
		if (square[x][0] == 1) return 1;
		else return 2;
	}
	else return 0;*/

	int temp = square[x][0]; // gán giá trị tạm = ô đầu tiên của hàng
	bool isCheck = true;
	for (int i = 0; i<max; i++)
	{
		if (temp != square[x][i] || square[x][i]==0) // so sánh không bằng nhau hoặc có giá trị == 0 thì false
		{	
			return 0;
		}
	}
	return temp; // nếu cùng thì trả về giá trị của cột
}

// Check hàng dọc
int checkColumn(int square[][max], int y)
{
	/*if ((square[0][y] == square[1][y]) && (square[1][y] == square[2][y]) && (square[0][y] != 0))
	{
		if (square[0][y] == 1) return 1;
		else return 2;
	}
	else return 0;*/

	int temp = square[0][y]; // gán giá trị tạm = ô đầu tiên của cột
	bool isCheck = true;
	for (int i = 0; i<max; i++)
	{
		if (temp != square[i][y] || square[i][y] == 0) // so sánh không bằng nhau hoặc có giá trị == 0 thì false
		{
			return 0;
		}
	}
	return temp; // nếu cùng thì trả về giá trị của cột
}

// Check hàng chéo
int checkCrossRow(int square[][max])
{
	/*if ((square[0][0] == square[1][1]) && (square[1][1] == square[2][2]) || (square[2][0] == square[1][1]) && (square[1][1] == square[0][2]))
	{
		if (square[1][1] == 1) return 1;
		else if (square[1][1] == 2) return 2;
		else return 0;
	}
	else return 0;*/
	int temp1=0, temp2=0; // 2 biến đếm
	for (int i = 0; i < max; i++)
	{
		if (square[i][i] == square[0][0]) temp1++; // so sánh hàng chéo "\"
		if (square[i][max - 1 - i] == square[0][max-1]) temp2++; // so sánh hàng chéo "/"
	}
	if (temp1 == max) return square[0][0];
	if (temp2 == max) return square[0][max-1];
	return 0;
}

// Kiểm tra thắng thua
int checkResult(int square[][max], int x, int y)
{
	if ( x!=y && (x == 1 || y == 1)) // tọa độ không nằm trong đường chéo
	{
		if (checkRow(square,x) != 0) return checkRow(square, x); // check hàng ngang của x
		else if (checkColumn(square,y) != 0) return checkColumn(square, y); // check hàng dọc của x
		else
			return 0;
	}
	else // tọa độ nằm trong đường chéo
	{ 
		if (checkRow(square, x) != 0) return checkRow(square, x); // check hàng ngang của x
		else if (checkColumn(square, y) != 0) return checkColumn(square, y); // check hàng dọc của x
		else if (checkCrossRow(square) != 0) return checkCrossRow(square); // check 2 hàng chéo
		else
			return 0;
	}
} 


int main()
{
	char name1[20], name2[20];
	int square[max][max] = {};
	int temp = 0;

	cout << "Chao mung ban den voi game TIC TAC TOE" << endl;
	cout << "Nhap ten nguoi choi 1:";
	cin >> name1;
	cout << "Nhap ten nguoi choi 2:";
	cin >> name2;

	cout << "Nhap nguoi choi danh truoc "<< endl << "Neu la " << name1 << " nhap 1" << endl << "Neu la " << name2 << " nhap 2" << endl<< "Nhap: ";
	cin >> isPlay;

	printSquare(square);
	while (temp < (max*max)) // check win
	{
		checkPoint(square);
		int result = checkResult(square,row,column);
		if (result == 1) 
		{
			cout << name1 << " WIN" << endl;
			break;
		}
		else if (result == 2)
		{
			cout << name2 << " WIN" << endl;
			break;
		}
		else temp ++;
	}
	if (temp == (max*max)) cout << "Draw" << endl;

	system("pause");
	return 0;
	
}
