#include "Hand.h"

Hand::Hand(){}

Hand::~Hand()
{
	for (vector<Bone*>::iterator it = bones.begin(); it != bones.end(); it++)
	{
		delete *it;
	}
}

void Hand::AddBone(Bone* aBone)
{
	bones.push_back(aBone);
}

bool Hand::RemoveBone( int position, Bone*& aBone)
{
	if(position < 0 ||  position >= bones.size())
		return false;
	int index = 0;
	for(vector<Bone*>::iterator it = bones.begin(); it != bones.end(); it++, index++)
	{
		if(index == position)
		{
			aBone = *it;
			bones.erase(it);
			break;
		}
	}
	return true;
}

void Hand::print() const
{
	for (auto it = bones.cbegin(); it != bones.cend(); it++)
	{
		(*it)->print();
		cout << endl;
	}
	cout << endl;
}

int Hand::size() const
{
	return bones.size();
}
