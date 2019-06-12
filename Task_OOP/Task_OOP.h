#pragma once
class MyPoint
{
private:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	MyPoint(int mPosX,int mPosY);
	~MyPoint();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	void Display();
	double Distance(MyPoint* p);
};