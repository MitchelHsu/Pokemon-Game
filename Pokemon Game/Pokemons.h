#ifndef POKEMONS_H
#define POKEMONS_H

#include <fstream>
#include <vector>

#include "Pokemon.h"

class Pokemons {
public:
	Pokemons() {
		loadPokemons();
	}
	Pokemon callbyTyperand(int tp);
	Pokemon callrand();
	void loadPokemons();
private:
	vector < Pokemon > pokemons;
};

void Pokemons::loadPokemons()
{
	ifstream inFile("pokemons.csv");

	string tempt;
	getline(inFile, tempt, ',');
	for (int i = 0; i < 34; i++)
	{
		getline(inFile, tempt, ',');
		string name = tempt;
		getline(inFile, tempt, ',');
		int type;
		for (int i = 0; i < 9; i++)
		{
			if (tempt == Type[i])
			{
				type = i;
				break;
			}
		}
		getline(inFile, tempt, ',');
		int hp = stoi(tempt);
		getline(inFile, tempt, ',');
		int atk = stoi(tempt);
		getline(inFile, tempt, ',');
		int def = stoi(tempt);
		getline(inFile, tempt, ',');
		int spd = stoi(tempt);
		getline(inFile, tempt, ',');
		int abi = stoi(tempt);

		Pokemon thepoke(i + 1, name, type, hp, atk, def, spd, abi);
		pokemons.push_back(thepoke);
	}

	inFile.close();
}

//Returns a Pokemon with certain type
Pokemon Pokemons::callbyTyperand(int tp)
{
	vector < Pokemon > require;
	int rqsize = 0;
	for (int i = 0; i < 34; i++)
	{
		if (pokemons[i].getType() == tp)
		{
			require.push_back(pokemons[i]);
			rqsize++;
		}
	}

	int randpick = rand() % rqsize;
	for (int i = 0; i < require.size(); i++)
	{
		if (i == randpick)
			return require[i];
	}
}

//Return random Pokemon
Pokemon Pokemons::callrand()
{
	int randpick = rand() % 34;

	for (int i = 0; i < pokemons.size(); i++)
	{
		if (i == randpick)
			return pokemons[i];
	}
}
#endif // !POKEMONS_H
#pragma once