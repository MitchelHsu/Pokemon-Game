#ifndef NPCS_H
#define NPCS_H

#include "NPC.h"

using namespace std;

class NPCs {
public:
	NPCs();
	NPC getNPC(int building);
	void modifiy(NPC npc);
private:
	vector< NPC > allNPC;
};

NPCs::NPCs()
{
	for (int i = 0; i < 12; i++)
	{
		NPC newnpc(i + 1);
		allNPC.push_back(newnpc);
	}
}

NPC NPCs::getNPC(int building)
{
	for (int i = 0; i < allNPC.size(); i++)
	{
		if (i + 1 == building)
			return allNPC[i];
	}
}

//Modify certain NPC
void NPCs::modifiy(NPC npc)
{
	for (int i = 0; i < allNPC.size(); i++)
	{
		if (npc.getBuilding() == allNPC[i].getBuilding())
		{
			vector <Pokemon> list;
			npc.getList(list);
			allNPC[i].setList(list);
		}
	}
}
#endif // !NPCS_H
#pragma once
