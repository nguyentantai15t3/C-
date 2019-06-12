#pragma once

using namespace std;

class MyPoint
{
private:
	int mPosX;
	int mPosY;
public:
	MyPoint(int,int);
	~MyPoint();
	void SetX(int);
	int GetX();
	void SetY(int);
	int SetY();
	void Display();
};