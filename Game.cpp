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
//	int CurrPlayer = 0;

	int IntialPlayer = 0;
	bool ExistedDouble = false;
	int tmp = 0;	//tmp is the highest double
	for(int index = 0; index < NumOfPlayer; index++)
	{
		for (int j = 0; j < players->HandSize(); j++)
		{	
			if(players[index].ShowHand(j))
			{
				if(players[index].ShowHand(j)->isDouble() && (players[index].ShowHand(j)->getFirstEnd() > tmp))
				{
				//	j = players[index].ShowHand(tmp)->getFirstEnd();
				//	CurrPlayer = index;
					IntialPlayer = index;
				//	HighBone = tmp;
					tmp = players[index].ShowHand(j)->getFirstEnd();
					
					ExistedDouble = true;
				
				}
			}
		}
	}
	if(ExistedDouble == false)
	{
		cout << "There is no double in the first run\n";
		cout << "Please run the game again\n";
		return ;
	}
	aField->SetDoubleBone(tmp);

//	int SwitchPlayer = IntialPlayer;

	cout << tmp << "HIGHEST BONE\n\n\n";

	
	
	//Print Player's hand
	
	for(int i = 0; i < NumOfPlayer; i++)
	{
		cout << "Player # " << i + 1 << endl;
		players[i].print();
	}

	cout << "|" << tmp << "|" << tmp << "|" << endl;
//	cout << "The highest double with Player " << IntialPlayer + 1 << endl;	
//	players[CurrPlayer].print();


	
/*	if(aField->FirstMatch(players[IntialPlayer].ShowHand(tmp)))
	{
		cout <<"Success to the first play\n\n";
		players[IntialPlayer].ShowHand(tmp)->print();
		cout << "\n\n";
		players[IntialPlayer].DelBone(tmp);
		cout << "First Double played\n\n";
	}

	else
		cout << "Faild First play\n";
*/
		

		players[IntialPlayer].DelBone(tmp);

		players[IntialPlayer].print();
	//Player's turn

/*	if(aField->FirstMatch(players[IntialPlayer].ShowHand(tmp)))
	//	cout << "**WARNING**\n\n";
//	else
	{
		cout << "First Player played highest bone\n";
		players[IntialPlayer].ShowHand(tmp)->print();
		players[IntialPlayer].DelBone(tmp);
	}
*/
		

	while(!GameOver)
	{
		IntialPlayer++;
		if(IntialPlayer < NumOfPlayer)
			IntialPlayer = 0;
		
		players[IntialPlayer].print();
		
	//	SwitchPlayer++;
		cout << "Player # " << IntialPlayer + 1 << endl;
//		PlayerTurn(players[IntialPlayer]);

		GameOver = true;	
	}

}

/*
int Game::HighestBone(int NumOfPlayer)
{
//	int CurrPlayer;
	int IntialPlayer = 0;
//	int HighBone;
	bool ExistedDouble = false;
	int tmp = 0;	//tmp is the highest double
	for(int index = 0; index < NumOfPlayer; index++)
	{
		for (int j = 0; j < players->HandSize(); j++)
		{	
//			if(players[index].ShowHand(j))
//			{
				if(players[index].ShowHand(j)->isDouble() && (players[index].ShowHand(j)->getFirstEnd() > tmp))
				{
				//	j = players[index].ShowHand(tmp)->getFirstEnd();
				//	CurrPlayer = index;
					IntialPlayer = index;
				//	HighBone = tmp;
					tmp = players[index].ShowHand(j)->getFirstEnd();
					
					ExistedDouble = true;
			//		cout << j << ":  J\n\n ";
			//		cout << "INDEX IS " << index << endl;
					cout << " TMP "  << tmp << endl;	
				
				}
//			}
		}
	}
	if(ExistedDouble == false)
	{
		cout << "There is no double in the first run\n";
		cout << "Please run the game again\n";
		return 0;
	}
	aField->SetDoubleBone(tmp);

	cout << tmp << "TMP\n\n" ;	
	return tmp;
	
}*/
/*
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
		if(aField->FirstMatch(CurrPlayer.ShowHand(BonePlayed)))
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
*/

