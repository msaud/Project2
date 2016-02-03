#ifndef Bone_H
#define Bone_H

#include <iostream>

using namespace std;

class Bone
{
public:
	Bone();
	Bone(int FirstEnd,int SecEnd);
	~Bone();
	
	void setBone(int FirstEnd, int SecEnd);
	int getFirstEnd()const;
	int getSecEnd() const;
	int getBoneScore() const;
	bool isDouble() const;
	void print()const;


private:
	int FirstEnd;
	int SecEnd;
};

#endif
