#ifndef HAND_H
#define HAND_H

#include "Bone.h"
#include <vector>

class Hand
{
public:
	Hand();
	~Hand();
	void AddBone(Bone* aBone);
	bool RemoveBone( int position, Bone*& aBone);
	void print() const;
	int size() const;

private:
	vector<Bone*> bones;
};
#endif
