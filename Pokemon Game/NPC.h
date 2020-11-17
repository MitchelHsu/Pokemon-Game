#ifndef NPC_H
#define NPC_H

#include "Pokemons.h"

using namespace std;

class NPC {
public:
	NPC(int build);
	Pokemon getPokemon(int pos) {
		return pokemons[pos];
	}
	void getList(vector< Pokemon > &list);
	void setList(vector< Pokemon > list);
	void showList();
	int getBuilding() {
		return building;
	}
	bool Defeted();
private:
	Pokemons pokemondata;
	vector < Pokemon > pokemons;
	int building;
};

NPC::NPC(int build)
{
	building = build;

	for (int i = 0; i < 3; i++)
	{
		Pokemon randpick = pokemondata.callrand();
		pokemons.push_back(randpick);
	}
}

//Return list odf Pokemons
void NPC::getList(vector< Pokemon > &list)
{
	for (int i = 0; i < pokemons.size(); i++)
	{
		list.push_back(pokemons[i]);
	}
}

//Setting list of Pokemons
void NPC::setList(vector< Pokemon > list)
{
	pokemons = list;
}

void NPC::showList()
{
	cout << "NPC pokemons : " << endl;
	for (int i = 0; i < pokemons.size(); i++)
	{
		cout << i + 1 << ". " << pokemons[i].getName() << endl;
	}

	cout << endl;
}

//Determine whether is NPC defeted
bool NPC::Defeted()
{
	if (pokemons.size() == 0)
	{
		cout << "You have already defeted bulding " << building << "!!" << endl << endl;
		system("pause");
		return true;
	}


	return false;
}
#endif // !NPC_H
#pragma once
