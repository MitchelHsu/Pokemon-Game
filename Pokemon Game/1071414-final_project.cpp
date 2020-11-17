//Pokemon Game
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Map.h"
#include "Player.h"
#include "NPCs.h"

#define waitkey rlutil::anykey();

using namespace std;

void showScore(Player player);

int main()
{
	srand(time(NULL));
	Map map; //Declaring Map
	map.showMap();
	
	NPCs allNPC;//Declaring all NPC
	Player player(map, allNPC);//Declaring Player
	player.Play();//Start game

	showScore(player);

	system("pause");
	return 0;
}

//Showing Final Score
void showScore(Player player)
{
	cout << "Game Ended ~" << endl << endl;

	cout << "This is your socre : " << player.getScore() << endl << endl << endl;
}