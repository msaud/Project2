#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	players = new Player[0];
	Yard = new ChickenYard();
	aField = new Field();
	GameOver = false;
}

Game::Game(int NumOfPlayer)
{
	players = (new Player[NumOfPlayer]);
	Yard = (new ChickenYard());
	aField = new Field();
	this->NumOfPlayer = NumOfPlayer;
	GameOver = false;
}

Game::~Game()
{
	delete []players;
	delete Yard;
	delete aField;
	
}

void Game::RunGame()
{

	Yard->ShuffleBones();

	//Draw bones to players
	
	int DealIntial = 7;
	for(int j = 0; j < NumOfPlayer; j++)
	{
		for (int index = 0; index < DealIntial; index++)
		{
			players[j].DrawBone(*Yard);
		}
	}

	//Find the highest double
	int tmp = 0;	
//	int PlayerNumber = 0;
	int CurrPlayer = 0;
	int j;
	int HighBone = 0;

	for(int index = 0; index < NumOfPlayer; index++)
	{
		for ( j = 0; j < players->HandSize(); j++)
	//		if(players[index].ShowHand(j) == NULL)
				if((players[index].ShowHand(j)->isDouble() && (players[index].ShowHand(j)->getFirstEnd()) > tmp))
				{
					j = players[index].ShowHand(tmp)->getFirstEnd();
					CurrPlayer = index;
					HighBone = tmp;
				}
	}
	int SwitchPlayer = CurrPlayer;

	//Print Player's hand
	
//	for(int i = 0; i < NumOfPlayer; i++)
//	{
//		cout << "Player # " << i + 1 << endl;
//	}

	cout << "|" << HighBone << "|" << HighBone << "|" << endl;
	cout << "The highest double with Player " << (CurrPlayer + 1) << endl;	
	players[CurrPlayer].print();
	if(aField->FirstMatch(players[CurrPlayer].ShowHand(tmp)))
	{
		players[CurrPlayer].ShowHand(tmp)->print();
		cout << "\n\n";
//		players[CurrPlayer].DelBone(tmp);
	}

	while(!GameOver)
	{
		if(SwitchPlayer < NumOfPlayer)
			SwitchPlayer = 0;
		
		players[SwitchPlayer].print();
		
		SwitchPlayer++;
		cout << "Player # " << SwitchPlayer + 1 << endl;
		PlayerTurn(players[SwitchPlayer]);

	
	}

}
bool Game::PlayerTurn(Player& CurrPlayer)
{
	int BonePlayed;
//	bool turn = true;
//	do
//	{
		if(CurrPlayer.HandEmpty())
		{
			cout << "You won the Game\n";
			//SHOW SCORE
			return false;
//			turn = false;
		}
		if(aField->isFirstMatch())
		{
			cout << "\nFirst Run\n";
			BonePlayed = CurrPlayer.PlayBone();
			if(BonePlayed == -1)
				cout << "This is the first bone you have to play double\n";
			else
				aField->FirstMatch(CurrPlayer.ShowHand(BonePlayed));
		//		if(turn == true)
		//		{
		//			CurrPlayer.DelBone(BonePlayed);
		//		}
		
		}
		if(aField->GetDoubleBone())
			cout << "The Field has a double bone: "<< aField->GetDoubleBone() << endl;
		else
			{
				cout << "***The Field has NO double***\n";
				aField->PrintFreeEnds();
			}
		
		BonePlayed = CurrPlayer.PlayBone();

		if(BonePlayed == -1)
		{
			if(CurrPlayer.DrawBone(*Yard))
			{
				cout << "Drawing a Bone\n";
				return true;
			}
			else
			{
				cout << "***NO MORE BONES***\n";
				return false;
			}
		}
		else
		{
			if(aField->PlayGame(CurrPlayer.ShowHand(BonePlayed)))
			{
				cout << "Great Choice :)\n";
				CurrPlayer.DelBone(BonePlayed);
				if(CurrPlayer.HandSize() == 0)
					return false;
					//GameOver

			}
			else
			{
				cout << "Wrong Bone\n";
				return false;
			}

		}
		return true;
//	}while (turn);
}


