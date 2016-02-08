#include "Bone.h"
#include <iomanip>

using namespace std;

Bone::Bone():FirstEnd(0), SecEnd(0)
{

}

Bone::Bone(int FirstEnd, int SecEnd)
{
	setBone(FirstEnd, SecEnd);
}

Bone::~Bone()
{

}

void Bone::setBone(int FirstEnd,int SecEnd)
{
	this->FirstEnd = FirstEnd;
	this->SecEnd = SecEnd;
}

int Bone::getBoneScore()const
{
	int score;
	score = FirstEnd + SecEnd;
	return score;
}

int Bone::getFirstEnd() const
{
	return FirstEnd;
}

int Bone::getSecEnd() const
{
	return SecEnd;
}

bool Bone::isDouble() const
{
//	if(FirstEnd == SecEnd)
//		return true;
	return (FirstEnd == SecEnd);

//	else
//		return false;
}

void Bone::print() const
{
	cout << "|" <<FirstEnd << "|" << SecEnd << "|";
}
/*
bool operator ==(const Bone & End1, Bone & End2)
{
	if((End1.getFirstEnd() == End2.getSecEnd() && End1.getSecEnd() == End2.getFirstEnd()) || (End1.getFirstEnd() == End2.getFirstEnd() && End1.getSecEnd() == End2.getFirstEnd()))
		return true;

	return false;

}*/
