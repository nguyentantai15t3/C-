
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
int main()
{
    return 0;
}

