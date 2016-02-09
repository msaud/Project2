#include "Field.h"

#include <iostream>
using namespace std;

Field::Field():UnLockGame(3)
{
	LockedDouble = false;
	EndsCounter = -1; //-2
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
	return UnLockGame;
}
void Field::SetDoubleBone(int DoubleBone)
{
	this->DoubleBone = DoubleBone;
}

int Field::GetDoubleBone()
{
	return DoubleBone;
}

//bool Field::isFirstMatch()
//{
/*
	if(EndsCounter == -2)
		return true;
	else
		return false;*/
//}

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

//	return false;
	
/*	if((aBone->getFirstEnd() == DoubleBone) && (aBone->getSecEnd() == DoubleBone))
	{
		EndsCounter++;  //sa
		return true;
	}
	else
	{
		cout << "***This is not your highest double***\n" << "**Please Try Again**\n";
		return false;
	}*/
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
		
		//	LLField[fieldSize] = new node(aBone, aBone->getSecEnd()); //new LL
		//	OpenEnds[fieldSize] = LLField[fieldSize];
		//	fieldSize++;
			EndsCounter++;
			
			if(EndsCounter == UnLockGame)
			{
				LockedDouble = false;
				EndsCounter = 0;
//				return true;
			}
//			else	//open the game again
				return true;
		}

		else if(aBone->getFirstEnd() == DoubleBone) // if second end match double
		{
			node* Curr = LLField[fieldSize];
			while(Curr == Curr->next)
				Curr = Curr->next;

			Curr->next = new node(aBone, aBone->getSecEnd());
				OpenEnds.push_back(aBone->getSecEnd());


//			LLField[fieldSize] = new node(aBone, aBone->getFirstEnd()); //new LL
//			OpenEnds[fieldSize] = LLField[fieldSize];
//			fieldSize++;
			EndsCounter++;
		
			//lock the game to play from the double sides
			if(EndsCounter == UnLockGame)
			{
				LockedDouble = false;
				EndsCounter = 0;
//				return true;
			}
//			else	//open the game again
				return true;
		}

//		else
//		{
//			cout << "***Invalid Choice***\nTry Again";
			return false;
//		}

	}
	else	//The game is unlocked double ends 
	{
	//	cout << "The open ends are: \n";
	//	PrintFreeEnds();
		if(aBone->isDouble()) //No doubles on the ends
		{
		//	for(int index = 0; index < fieldSize; index++)
			for(auto it = OpenEnds.begin(); it != OpenEnds.end();it++)
			{
			//	if(aBone->getFirstEnd() == OpenEnds[index]->Ends)
				if(aBone->getSecEnd() == *it)
				{
					OpenEnds.erase(it);
					fieldSize++;
					LLField[fieldSize] = new node(aBone, aBone->getFirstEnd());

				//	OpenEnds[index]->setEnd(9 + 1);
					LockedDouble = true;
					DoubleBone = aBone->getFirstEnd();
					EndsCounter = 0;		//Counter
					return true;
				}
			//	else if(aBone->getSecEnd() == OpenEnds[index]->Ends)
			/*	if(aBone->getFirstEnd() == *it)
				{
					//	OpenEnds[index]->setEnd(9 + 1);
					OpenEnds.erase(it);
					fieldSize++;
					LLField[fieldSize] = new node(aBone, aBone->getFirstEnd());
					LockedDouble = true;
					DoubleBone = aBone->getFirstEnd();
					return true;
				}*/
	
			}
		//	cout << "***Invalid choice***\nchoose one of the ends";
			return false;
		}
//		else	//Add ends not double
//		{
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
//			}
		return false;	
		
		/*	for(int index = 0; index < fieldSize; index++)
			{
				if(aBone->getSecEnd() == OpenEnds[index]->Ends)
				{
					OpenEnds[index] = new node(aBone, aBone->getFirstEnd());
					node* current = LLField[index];
					while(current->next == NULL)
						current = current->next;
					current->setNext(OpenEnds[index]);
					return true;
				}
				if(aBone->getFirstEnd() == OpenEnds[index]->Ends)
				{
				OpenEnds[index] = new node(aBone, aBone->getSecEnd());
				node* current = LLField[index];
				while(current->next == NULL)
					current = current->next;
				current->setNext(OpenEnds[index]);
				return true;
				}
				cout << "***Invalid choice***\nchoose one of the ends";
				return false;	
			}
		*/
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
