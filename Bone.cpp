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
	if(FirstEnd == SecEnd)
		return true;

	else
		return false;
}

void Bone::print() const
{
	cout << "|" <<FirstEnd << "|" << SecEnd << "|";
}

