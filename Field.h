#ifndef FIELD_H
#define FIELD_H

#include "Bone.h"
#include "ChickenYard.h"

struct node
{
	node(Bone * aBone, int Ends)
	{
		bone = aBone;
		this->Ends = Ends;
		next = nullptr;
	}

	Bone* bone;
	node* next;
	int Ends;

};

class Field
{
	public:
		Field();
		~Field();
		void SetDoubleBone(int DoubleBone);
		int GetDoubleBone();
		bool PlayGame(Bone* aBone);
	//	bool isFirstMatch();
		bool FirstMatch(Bone* aBone);
		void PrintFreeEnds();
	private:
		int DoubleBone;
		int EndsCounter; // Number of double has been played
		bool LockedDouble;
		int fieldSize;
		int UnLockGame; 	//No ends are double
		int MatchDouble;

		node** LLField;
	//	node** OpenEnds;
		vector <int> OpenEnds;
};

#endif
