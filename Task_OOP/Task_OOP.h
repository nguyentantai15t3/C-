#pragma once

using namespace std;

class MyPoint
{
private:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	MyPoint(int mPosX,int mPosY);
	~MyPoint();
	void SetX(int mPosX);
	int GetX();
	void SetY(int mPosY);
	int GetY();
	void Display();
	double Distance(MyPoint &p);
};