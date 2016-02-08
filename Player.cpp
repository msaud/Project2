#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

Player::Player():WinningPile(0){}

bool Player::DrawBone(ChickenYard& yard)
{
	Bone* aBone;
	if(!yard.DealBone(aBone))
		return false;
	hand.push_back(aBone);
	WinningPile += aBone->getBoneScore();
	return true;
}

//bool Player::PlayBone(Bone*& aBone)
int Player::PlayBone()
{
	int BoneSelected = -1;
//	int HandsBones = DisplayHand();
	DisplayHand();
	
	cout << "Play a bone or hit 0 to draw one\n";

	cin >> BoneSelected;

	while (BoneSelected < 0 || BoneSelected > HandSize())
	{
		cout << "\n***Warning***\nWrong choice\nPlease try again\n\n";
//		cin.clear();
		cin >> BoneSelected;
	}
//	cin.clear();
	return BoneSelected - 1;

/*	// ***** hand.erase( begin,index)
	int position;
	srand(time(NULL));
	position = rand() % HandSize();
	if(!hand.pop_Back(position, aBone))
		return false;
	return true;*/
}

bool Player::DelBone(int delBone)
{
	if(delBone > HandSize() || delBone < 0)
		return false;

	WinningPile -= ShowHand(delBone)->getBoneScore();
	hand.erase(hand.begin() + delBone);
	return true;
}

int Player::DisplayHand()
{
	int j = 0;
	for (int index = 0; index < 45 ; index++)  //45 the number of bones
	{
		if (hand[index] != nullptr)
		{
			cout <<"(" << j + 1 << ")" << setw(5);
			hand[index]->print();
			++j;
			cout << j;
		}
	}
	return j;

}

void Player::setAsideBone(Bone* aBone)
{
	WinningPile++;
	delete aBone;
}

int	Player::getScore() const
{
	return WinningPile;
}

Bone* Player::ShowHand(int index)
{
	return hand[index];
}


int Player::HandSize()const
{
	return hand.size(); 
}


bool Player::HandEmpty() 
{
	if(hand[0] == nullptr)
		return true;
	else
		return false;
}

void Player::print() const
{
	int i = 1;
	cout << "\nCurrent Hand: " << endl;
	for (auto it = hand.cbegin(); it != hand.cend(); it++)
	{
		cout <<"(" << i << ")"<< setw(5);
		(*it)->print();
		cout << endl;
		i++;
	}
	cout << "(0)    " << "Draw a Bone"  << endl; 

	cout << "\nCurrent scores: " << WinningPile << endl;
}
