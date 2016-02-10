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
					IntialPlayer = index;
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
	
	//Print Player's hand
/*	
	for(int i = 0; i < NumOfPlayer; i++)
	{
		cout << "Player # " << i + 1 << endl;
		players[i].print();
	}

*/
	int Index = players[IntialPlayer].DoubleIndex();
	
	if(aField->FirstMatch(players[IntialPlayer].ShowHand(Index)))
	{
		cout <<"Success to the first play\n\n";
		players[IntialPlayer].ShowHand(Index)->print();
		cout << "\n\n";
		players[IntialPlayer].DelBone(Index);
		cout << "First Double played\n\n";
	}

	else
		cout << "Faild First play\n";


	while(!GameOver)
	{
		IntialPlayer++;
		if(IntialPlayer == NumOfPlayer)
			IntialPlayer = 0;
		
		
		cout << "Player # " << IntialPlayer + 1 << endl;
		PlayerTurn(players[IntialPlayer]);

	}

}

bool Game::PlayerTurn(Player& CurrPlayer)
{
		int BonePlayed = 0; 
		if(CurrPlayer.HandSize() == 0)
		{
			cout << "You won the Game\n";
			GameOver = true;
			//SHOW SCORE
			return false;
		}
		if(aField->GetLockedDouble())
			cout << "Double is one of the ends: " << aField->GetDoubleBone() << endl;
		else
		{
			cout << "The open Ends are: \n";
			aField->PrintFreeEnds();
		}
	
		BonePlayed = CurrPlayer.PlayBone();
	
		char HideHand = ' ';
		cout << "(H)ide your hand\n(Q)uit the game\n(C)ontinue\nPress H, Q, C: ";
		cin >> HideHand;
		cin.clear();
		if(tolower(HideHand) == 'h')
			system("clear && printf '\e[3J'");
		else if(tolower(HideHand) == 'q')
			GameOver = true;
			

		//Draw a bone
		if(BonePlayed == -1)
		{
			cout << "This is the first bone you have to play double\n";
			if(CurrPlayer.DrawBone(*Yard))
			{
				cout << "Current Player drew a bone\n";
				return true;
			}
			else
			{
				cout << "Player couldn't draw a bone\n";
				return false;
			}
		}
	
		else
		{

			
			if(!aField->PlayGame(CurrPlayer.ShowHand(BonePlayed)))
			{
				cout << "Please Try again\n";
				return false;
			}
			else			
			{	
				CurrPlayer.DelBone(BonePlayed);

				if(CurrPlayer.HandSize() == 0)
				{
					cout << "Game Over\n";
					GameOver = true;
				}
			}
		}

		return true;
}
