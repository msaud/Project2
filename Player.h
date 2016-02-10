#ifndef PLAYER_H
#define PLAYER_H

#include "ChickenYard.h"
//#include "Hand.h"
#include "Bone.h"
#include <vector>

class Player
{
	public:
		Player();
		bool DrawBone(ChickenYard& yard);
//		bool PlayBone(Bone*& aBone);
		bool DelBone(int delBone);
		int PlayBone();
		void setAsideBone(Bone* aBone);
		int getScore() const;
		Bone* ShowHand(int index);
		void print() const;
		bool HandEmpty();
		int HandSize() const; 
		int DisplayHand();
		int DoubleIndex() const;

	private:
		//Hand hand;
		vector<Bone*> hand;
		int WinningPile;
};

#endif

