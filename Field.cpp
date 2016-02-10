#include "Field.h"

#include <iostream>
using namespace std;

Field::Field():UnLockGame(3)
{
	LockedDouble = false;
	EndsCounter = -1; 
	MatchDouble = 0;
	fieldSize = 0;
//	UnLockGame = 3; // 3 ends in the chicken foot
	LLField = new node*[45];	//45 the number of the bones

}

Field::~Field()
{

}
bool Field::GetLockedDouble() const
{
	return LockedDouble; //UnLockGame
}
void Field::SetDoubleBone(int DoubleBone)
{
	this->DoubleBone = DoubleBone;
}

int Field::GetDoubleBone()
{
	return DoubleBone;
}

bool Field::FirstMatch(Bone* aBone)
{
	
	if(!aBone->isDouble())
		return false;
	else
	{	
		LLField[fieldSize] = new node(aBone, aBone->getFirstEnd());
		MatchDouble = aBone->getFirstEnd();
		LockedDouble = true;
		return true;
	}

}

bool Field::PlayGame(Bone* aBone)
{
	if(LockedDouble)
	{
		if(aBone->getSecEnd() == DoubleBone) // if second end match double
		{
			node* Curr = LLField[fieldSize];
			while(Curr == Curr->next)
				Curr = Curr->next;
		
			Curr->next = new node(aBone, aBone->getFirstEnd());
			OpenEnds.push_back(aBone->getFirstEnd());
		
			EndsCounter++;
			
			if(EndsCounter == UnLockGame)
			{
				LockedDouble = false;
				EndsCounter = 0;
			}
			return true;
		}

		else if(aBone->getFirstEnd() == DoubleBone) // if second end match double
		{
			node* Curr = LLField[fieldSize];
			while(Curr == Curr->next)
				Curr = Curr->next;

			Curr->next = new node(aBone, aBone->getSecEnd());
			OpenEnds.push_back(aBone->getSecEnd());

			EndsCounter++;
		
			//lock the game to play from the double sides
			if(EndsCounter == UnLockGame)
			{
				LockedDouble = false;
				EndsCounter = 0;
			}
				return true;
		}

			return false;

	}
	else	//The game is unlocked double ends 
	{
		if(aBone->isDouble()) //No doubles on the ends
		{
			for(auto it = OpenEnds.begin(); it != OpenEnds.end();it++)
			{
				if(aBone->getSecEnd() == *it)
				{
					OpenEnds.erase(it);
					fieldSize++;
					LLField[fieldSize] = new node(aBone, aBone->getFirstEnd());

					LockedDouble = true;
					DoubleBone = aBone->getFirstEnd();
					EndsCounter = 0;		//Counter
					return true;
				}

			}
			return false;
		}
		
		for(auto it = OpenEnds.begin(); it != OpenEnds.end();it++)
			{
				if(aBone->getSecEnd() == *it)
				{
					OpenEnds.erase(it);
					OpenEnds.push_back(aBone->getFirstEnd());
					return true;
				}
				else if(aBone->getFirstEnd() == *it)
				{
					OpenEnds.erase(it);
					OpenEnds.push_back(aBone->getSecEnd());
					return true;
				}
		return false;	
		
			}
	return false;
	}


}

void Field::PrintFreeEnds()
{
	cout  <<"You Can play on these sides: ";
	for(auto it = OpenEnds.begin(); it != OpenEnds.end();it++)
	{
		cout << *it << endl;
	}

}
