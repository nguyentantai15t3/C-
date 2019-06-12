#include "stdafx.h"
#include <iostream>
#include "Task_OOP.h"
#include <cmath>

using namespace std;

MyPoint::MyPoint() 
{
	this->mPosX = 0;
	this->mPosY = 0;
}

MyPoint::MyPoint(int mPosX, int mPosY)
{
	this->mPosX;
	this->mPosY;
}


void MyPoint::SetX(int x)
{
	this->mPosX = x;
}

int MyPoint::GetX()
{
	return this->mPosX;
}

void MyPoint::SetY(int y)
{
	this->mPosY = y;
}

int MyPoint::GetY()
{
	return this->mPosY;
}

void MyPoint::Display()
{
	cout << "Value of mPosX:" << this->mPosX << " and value of mPosY:" << this->mPosY << endl;
}
double MyPoint::Distance(MyPoint* p)
{
	return sqrt(pow(this->mPosX - p->mPosX, 2) + pow(this->mPosY - p->mPosY, 2));
}

MyPoint::~MyPoint() {};
