#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Bone.h"
#include "ChickenYard.h"
#include "Field.h"

class Game
{
	public:
		Game();
		Game(int NumOfPlayer);
		~Game();
		void RunGame();
//		bool PlayerTurn(Player&);
//		int HighestBone(int NumOfPlayer);
		
	private:
		Player * players;
		ChickenYard * Yard;
		Field* aField;
		int NumOfPlayer;
		bool GameOver;

};
#endif
