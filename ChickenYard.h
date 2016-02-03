#ifndef ChickenYard_H
#define ChickenYard_H

#include "Bone.h"
#include <vector>

using namespace std;

class ChickenYard
{
public:
	ChickenYard();
	~ChickenYard();
	void ShuffleBones();
	bool DealBone(Bone*& aBone);
	bool isEmpty() const;
	void print() const;
	int getSize()const;

private:
	vector<Bone*> bones;

};

#endif
