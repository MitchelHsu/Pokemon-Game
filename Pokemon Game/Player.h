#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "rlutil.h"
#include "Map.h"
#include "Pokemons.h"
#include "NPCs.h"
#include "Ability.h"

#define waitkey rlutil::anykey("Press any key to continue...\n")

using namespace std;

class Player {
public:
	Player(Map map, NPCs &all);//Constructor
	void Play();//Main frame of the game
	void movePlayer(char key);//Moving player
	void Tressure(char pos);//Tressure
	void showList();//Showing Player's Pokemon List
	void Battle();//Battling NPC
	void setCurrentBuilding();//Setting the building that player is in
	void setCurrentABI(int player, int npc);//Setting the ability of player and NPC
	void BattleList(vector< Pokemon > list);//list when player battling
	int getScore() {
		return score;
	}
	void getOut();//Getting out after battling
	void printCurrentBuilding();
private:
	Map map;
	int xpos = 20;
	int ypos = 30;
	char tempt = ' ';
	bool blocks;//Walls
	int score = 0;
	int building;
	Pokemons pokemons;//all pokemons
	NPCs allNPC;//all NPC
	Ability *PlyerABI;//Pointer of Player's ability
	Ability *NPCabi;//Pointer of NPC's ability
	vector < Pokemon > pokemonList;
};

Player::Player(Map map, NPCs &all)
	: map(map), allNPC(all)
{
	//rlutil::hidecursor();
	rlutil::locate(xpos, ypos);
	cout << "@";
}

void Player::Play()
{
	while (true) {
		rlutil::hidecursor();
		if (kbhit()) {
			char k = getch(); // Get character
			int randnum = rand() % 10;
			if (k == ' ')
			{
				int choose = 0;
				rlutil::showcursor();
				rlutil::cls();

				while (choose < 1 || choose>2)
				{
					cout << "Are you sure about ending this game ?" << endl;
					cout << "1. Yesss ..." << endl;
					cout << "2. Of coures not : )" << endl;
					cin >> choose;
				}

				if (choose == 1)
					break;
				else
				{
					rlutil::cls();
					map.showMap();
					rlutil::locate(xpos, ypos);
					cout << "@";
				}
			}
			else movePlayer(k);
			if (tempt == '#')
			{
				Battle();
				getOut();
				rlutil::cls();
				map.showMap();
				rlutil::locate(xpos, ypos);
				cout << "@";
				tempt = ' ';
			}
			else
			{
				if (randnum == 0)
				{
					char pos = map.getChar(xpos, ypos);
					Tressure(pos);
					rlutil::cls();
					map.showMap();
					rlutil::locate(xpos, ypos);
					cout << "@";
				}
			}
		}
		//std::cout.flush();
	}
	rlutil::showcursor();
}

void Player::movePlayer(char key)
{
	if (key == ' ')
		return;
	else if (key == 'a')
	{
		int x = xpos - 1;
		if (!map.checkBlock(x, ypos))
			return;
		rlutil::locate(xpos, ypos); map.print(tempt); // Erase player
		tempt = map.getChar(x, ypos);
		--xpos;
		rlutil::locate(xpos, ypos); std::cout << '@'; // Output player
	}
	else if (key == 'd')
	{
		int x = xpos + 1;
		if (!map.checkBlock(x, ypos))
			return;
		rlutil::locate(xpos, ypos); map.print(tempt);  // Erase player
		tempt = map.getChar(x, ypos);
		++xpos;
		rlutil::locate(xpos, ypos); std::cout << '@'; // Output player
	}
	else if (key == 'w')
	{
		int y = ypos - 1;
		if (!map.checkBlock(xpos, y))
			return;
		rlutil::locate(xpos, ypos); map.print(tempt);  // Erase player
		tempt = map.getChar(xpos, y);
		--ypos;
		rlutil::locate(xpos, ypos); std::cout << '@'; // Output player
	}
	else if (key == 's')
	{
		int y = ypos + 1;
		if (!map.checkBlock(xpos, y))
			return;
		rlutil::locate(xpos, ypos); map.print(tempt);  // Erase player
		tempt = map.getChar(xpos, y);
		++ypos;
		rlutil::locate(xpos, ypos); std::cout << '@'; // Output player
	}
}

void Player::getOut()
{
	if (building == 1 || building == 6)
		xpos++;
	else if (building == 5 || building == 2 || building == 10)
		ypos++;
	else if (building == 3 || building == 10 || building == 4)
		xpos--;
	else if (building == 7 || building == 9 || building == 8 || building == 12)
		ypos--;
}

void Player::Tressure(char pos)
{
	rlutil::showcursor();
	system("cls");
	cout << "Pokemon emerges!" << endl;

	Pokemon randapp;
	int randnum = rand() % 10;
	if (pos == ';')
	{
		if (randnum >= 0 && randnum <= 3)
		{
			randapp = pokemons.callbyTyperand(0);
			randapp.showIcon();
		}
		else
		{
			randapp = pokemons.callrand();
			randapp.showIcon();
		}
	}
	else if (pos == '~')
	{
		if (randnum >= 0 && randnum <= 3)
		{
			randapp = pokemons.callbyTyperand(2);
			randapp.showIcon();
		}
		else
		{
			randapp = pokemons.callrand();
			randapp.showIcon();
		}
	}
	else
	{
		randapp = pokemons.callrand();
		randapp.showIcon();
	}
	cout << "It's " << randapp.getName() << " !" << endl;

	showList();

	int choose = 0;
	while (choose < 1 || choose > 2)
	{
		cout << "Capture or not. " << endl;
		cout << "1. Let's do it. " << endl;
		cout << "2. Forget it." << endl;
		cin >> choose;
	}
	int capture = rand() % 2;
	switch (choose)
	{
	case 1:
		if (pokemonList.size() >= 0 && pokemonList.size() < 3)
		{
			if (capture == 1)
			{
				cout << "You have captured " << randapp.getName() << " !" << endl;
				pokemonList.push_back(randapp);
			}
			else
			{
				cout << randapp.getName() << " is gone... :(" << endl;
			}
		}
		else if (pokemonList.size() == 3)
		{
			if (capture == 1)
			{
				cout << "You have captured " << randapp.getName() << " !" << endl;
				cout << "But your poket is FULL! " << endl;
				int abandon = 0;
				while (abandon < 1 || abandon>4)
				{
					cout << "Choose one to abandon..." << endl;
					showList();
					cout << "4. Abandon " << randapp.getName() << endl;
					cin >> abandon;
				}

				if (abandon == 4)
				{
					system("pause");
					return;
				}
				else
				{
					vector< Pokemon >::iterator ab = pokemonList.begin();
					for (int i = 0; i < 3; i++, ++ab)
					{
						if (abandon - 1 == i)
						{
							pokemonList.erase(ab);
							break;
						}
					}

					pokemonList.push_back(randapp);
				}
			}
			else
			{
				cout << randapp.getName() << " is gone... :(" << endl;
			}
		}
		break;
	case 2:
		system("pause");
		rlutil::hidecursor();
		rlutil::cls();
		return;
	}

	system("pause");
	rlutil::hidecursor();
	rlutil::cls();
}

void Player::showList()
{
	if (pokemonList.size() == 0)
	{
		cout << "\nYou have no Pokemons !" << endl << endl;
	}
	else
	{
		cout << "Your Pokemons :" << endl;
		for (int i = 0; i < pokemonList.size(); i++)
		{
			cout << i + 1 << ". ";
			cout << pokemonList[i].getName() << endl;
		}
	}
}

void Player::setCurrentBuilding()
{
	if (xpos == 14 && ypos == 18)
		building = 1;
	else if (xpos == 35 && ypos == 7)
		building = 2;
	else if (xpos == 31 && ypos == 15)
		building = 3;
	else if (xpos == 75 && ypos == 4)
		building = 4;
	else if (xpos == 18 && ypos == 7)
		building = 5;
	else if (xpos == 10 && ypos == 11)
		building = 6;
	else if (xpos == 41 && ypos == 14)
		building = 7;
	else if (xpos == 76 && ypos == 9)
		building = 8;
	else if (xpos == 77 && ypos == 12)
		building = 9;
	else if (xpos == 84 && ypos == 7)
		building = 10;
	else if (xpos == 76 && ypos == 7)
		building = 11;
	else if (xpos == 86 && ypos == 10)
		building = 12;
}

void Player::setCurrentABI(int player, int npc)
{
	switch (player)
	{
	case 0:
		PlyerABI = new Ability;
		break;
	case 1:
		PlyerABI = new Heal;
		break;
	case 2:
		PlyerABI = new Burning;
		break;
	case 3:
		PlyerABI = new Counter_A;
		break;
	case 4:
		PlyerABI = new Immunology;
		break;
	case 5:
		PlyerABI = new Leechlife;
		break;
	case 6:
		PlyerABI = new Avoid;
		break;
	case 7:
		PlyerABI = new Doubleattack;
		break;
	case 8:
		PlyerABI = new Poison;
		break;
	case 9:
		PlyerABI = new Lowerspeed;
		break;
	case 10:
		PlyerABI = new Rockskin;
		break;
	case 11:
		PlyerABI = new Lowerdef;
		break;
	case 12:
		PlyerABI = new Loweratk;
		break;
	}

	switch (npc)
	{
	case 0:
		NPCabi = new Ability;
		break;
	case 1:
		NPCabi = new Heal;
		break;
	case 2:
		NPCabi = new Burning;
		break;
	case 3:
		NPCabi = new Counter_A;
		break;
	case 4:
		NPCabi = new Immunology;
		break;
	case 5:
		NPCabi = new Leechlife;
		break;
	case 6:
		NPCabi = new Avoid;
		break;
	case 7:
		NPCabi = new Doubleattack;
		break;
	case 8:
		NPCabi = new Poison;
		break;
	case 9:
		NPCabi = new Lowerspeed;
		break;
	case 10:
		NPCabi = new Rockskin;
		break;
	case 11:
		NPCabi = new Lowerdef;
		break;
	case 12:
		NPCabi = new Loweratk;
		break;
	}
}

void Player::BattleList(vector< Pokemon > list)
{
	cout << "Player Pokemons :" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		cout << i + 1 << ".";
		cout << list[i].getName() << endl;
	}
	cout << endl;
}

void Player::printCurrentBuilding()
{
	if (building == 4)
		cout << "You have entered building A" << endl;
	else if (building == 10)
		cout << "You have entered building B" << endl;
	else if (building == 11)
		cout << "You have entered building C" << endl;
	else if (building == 12)
		cout << "You have entered building D" << endl;
	else
		cout << "You have entered building " << building << endl;

	system("pause");
}

void Player::Battle()
{
	rlutil::cls();

	setCurrentBuilding();
	printCurrentBuilding();


	NPC theNPC = allNPC.getNPC(building);
	if (theNPC.Defeted())
		return;



	vector< Pokemon > NPClist;
	theNPC.getList(NPClist);
	vector< Pokemon > PlayerList;
	for (int i = 0; i < pokemonList.size(); i++)
	{
		PlayerList.push_back(pokemonList[i]);
	}
	


	int pcount = PlayerList.size() - 1;
	int ncount = NPClist.size() - 1;
	while (NPClist.size() > 0 && PlayerList.size() > 0)
	{
		setCurrentABI(PlayerList[pcount].getABInum(), NPClist[ncount].getABInum());
		while (true)
		{
			system("cls");
			PlayerList[pcount].showInfo(40, 2);
			for (int i = 0; i < 15; i++)
			{
				cout << endl;
			}
			NPClist[ncount].showInfo(40, 20);
			for (int i = 0; i < 20; i++)
			{
				cout << endl;
			}
			

			cout << endl;

			BattleList(PlayerList);
			theNPC.showList();
			system("pause");


			PlyerABI->prexecute(PlayerList[pcount]);
			NPCabi->prexecute(NPClist[ncount]);
			cout << endl << endl;
			PlayerList[pcount].showStats();
			NPClist[ncount].showStats();
			system("pause");
			cout << endl << endl;

			cout << "Fight Begins !" << endl << endl;
			while (PlayerList[pcount].getHP() > 0 && NPClist[ncount].getHP() > 0)
			{
				if (PlayerList[pcount].getSpd() > NPClist[ncount].getSpd())
				{
					cout << "Player Attacks !" << endl;
					PlayerList[pcount].Attack(NPClist[ncount]);
					if (NPClist[ncount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					PlyerABI->execute(PlayerList[pcount], NPClist[ncount]);
					NPCabi->execute(PlayerList[pcount], NPClist[ncount]);
					if (NPClist[ncount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					if (PlayerList[pcount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					cout << endl;
					PlayerList[pcount].showStats();
					NPClist[ncount].showStats();
					cout << endl << endl;

					cout << "NPC Attacks !" << endl;
					NPClist[ncount].Attack(PlayerList[pcount]);
					if (PlayerList[pcount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					NPCabi->execute(NPClist[ncount], PlayerList[pcount]);
					PlyerABI->execute(NPClist[ncount], PlayerList[pcount]);
					if (PlayerList[pcount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					if (NPClist[ncount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					cout << endl;
					PlayerList[pcount].showStats();
					NPClist[ncount].showStats();
					cout << endl << endl;
					system("pause");
				}
				else
				{
					cout << "NPC Attacks !" << endl;
					NPClist[ncount].Attack(PlayerList[pcount]);
					if (PlayerList[pcount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					NPCabi->execute(NPClist[ncount], PlayerList[pcount]);
					PlyerABI->execute(NPClist[ncount], PlayerList[pcount]);
					if (PlayerList[pcount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					if (NPClist[ncount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					cout << endl << endl;
					PlayerList[pcount].showStats();
					NPClist[ncount].showStats();
					cout << endl << endl;

					cout << "Player Attacks !" << endl;
					PlayerList[pcount].Attack(NPClist[ncount]);
					if (NPClist[ncount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					PlyerABI->execute(PlayerList[pcount], NPClist[ncount]);
					NPCabi->execute(PlayerList[pcount], NPClist[ncount]);
					if (NPClist[ncount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					if (PlayerList[pcount].getHP() <= 0)
					{
						PlayerList[pcount].showStats();
						NPClist[ncount].showStats();
						break;
					}
					cout << endl << endl;
					PlayerList[pcount].showStats();
					NPClist[ncount].showStats();
					cout << endl << endl;
					system("pause");
				}
			}


			if (PlayerList[pcount].getHP() <= 0)
			{
				cout << endl << endl;
				cout << PlayerList[pcount].getName() << " DIED ..." << endl;
				pcount--;
				PlayerList.pop_back();
				system("pause");
			}
			if (NPClist[ncount].getHP() <= 0)
			{
				cout << endl << endl;
				cout << NPClist[ncount].getName() << " DIED ..." << endl;
				ncount--;
				NPClist.pop_back();
				theNPC.setList(NPClist);
				system("pause");
			}

			rlutil::cls();
			break;
		}
	}


	if (NPClist.size() == 0)
	{
		score += 100;
		cout << "Plyer wins !!" << endl;
		cout << "You have defeted by NPC in building " << theNPC.getBuilding() << endl;
	}
	else if (PlayerList.size() == 0)
	{
		cout << "You are Defeted... :(" << endl;
	}
	else if (NPClist.size() == 0 && PlayerList.size() == 0)
	{
		cout << "The Fight was Tied. " << endl;
	}

	allNPC.modifiy(theNPC);
	cout << "Your Pokemons Will Be Recovered ..." << endl;

	system("pause");
}
#endif // !PLAYER_H
#pragma once
