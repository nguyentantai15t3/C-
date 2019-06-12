
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Task_OOP.h"

MyPoint::MyPoint() {};

MyPoint::MyPoint(int mPosX, int mPosY)
{
	this->mPosX;
	this->mPosY;
}

MyPoint::~MyPoint() {};

void MyPoint::SetX(int mPosx)
{
	this->mPosX = mPosx;
}

int MyPoint::GetX()
{
	return this->mPosX;
}

void MyPoint::SetY(int mPosy)
{
	this->mPosY = mPosy;
}

int MyPoint::GetY()
{
	return this->mPosY;
}

void MyPoint::Display()
{
	cout << "Value of mPosX:" << mPosX << " and value of mPosY:" << mPosY << endl;
}

int main()
{
    return 0;
}

