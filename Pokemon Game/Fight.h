#ifndef FIGHT_H
#define FIGHT_H


#include <iostream>

using namespace std;

class Fight {
public:
	Fight(NPCs npcs, Player player);
	Fight();
private:
	NPCs allNPC;
	Player thePlayer;
};

Fight::Fight(NPCs npcs, Player player)
	:allNPC(npcs), thePlayer(player)
{

}
#endif // !FIGHT_
#pragma once
