#include "ChickenYard.h"
#include <algorithm>
#include <random>   
#include <chrono>
#include <iomanip>

ChickenYard::ChickenYard()
{
	int FirstEnd,  SecEnd;
	for(FirstEnd = 9; FirstEnd > 0; FirstEnd--)
	{
		for(SecEnd = FirstEnd; SecEnd > 0; SecEnd--)
		{
			bones.push_back(new Bone(FirstEnd, SecEnd));
		}
	}
}

ChickenYard::~ChickenYard()
{
	for (vector<Bone*>::iterator it = bones.begin(); it != bones.end(); it++)
	{
		delete *it;
	}
}

void ChickenYard::ShuffleBones()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle(bones.begin(), bones.end(), std::default_random_engine(seed));
}

bool ChickenYard::DealBone(Bone*& aBone)
{
	if (bones.size() == 0)
		return false;
	aBone = bones.back();
	bones.pop_back();
	return true;
}

bool ChickenYard::isEmpty() const
{
	return bones.size() == 0;
}

void ChickenYard::print() const
{
	for (auto it = bones.cbegin(); it != bones.cend(); it++)
	{
		cout << setw(10) ;
		(*it)->print();
	}	
	
}

int ChickenYard::getSize() const
{
	return bones.size();
}
