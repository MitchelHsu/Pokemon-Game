#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string Type[9] = { "Grass","Fire","Water","Bug","Flying","Normal","Poison","Electric","Ground" };
string Abilities[13] = { "None","Heal","Burning","Counter Attack","Immunology","LeechLife",
					"Avoid","Double Attack","Poison","Lower Speed","Rock Skin","Lower Def","Lower Attack" };
double typeatk[9][9] = { 0.5,0.5,2,0.5,0.5,1,0.5,1,2,
						2,0.5,0.5,2,1,1,1,1,1,
						0.5,2,0.5,1,1,1,1,1,2,
						2,0.5,1,1,0.5,1,0.5,1,1,
						2,1,1,2,1,1,1,0.5,1,
						1,1,1,1,1,1,1,1,1,
						2,1,1,1,1,1,0.5,1,0.5,
						0.5,1,2,1,2,1,1,0.5,0,
						0.5,2,1,0.5,0,1,2,2,1 }; //Attack type rate

class Pokemon {
public:
	Pokemon(int num, string name, int tpe, int hp, int atk, int def, int spd, int ABI);
	Pokemon() {}
	void resetPokemon(Pokemon poke);
	void showInfo(int x, int y);
	void showStats();//Show HP...
	int getHP() {
		return HP;
	}
	int getDef() {
		return DEF;
	}
	int getAtk()
	{
		return ATK;
	}
	int getSpd() {
		return Speed;
	}
	int getType() {
		return type;
	}
	int getABInum() {
		return abi;
	}
	//Determine Immunology
	bool getImmun() {
		return immun;
	} 
	//Determining Poisoned
	bool getPoison() {
		return poisoned;

	}
	//Determine Lowered spd
	bool getLowspd() {
		return lowerspd;

	}
	bool getLowd() {
		return lowerdef;
	}
	bool getLowatk() {
		return loweratk;
	}
	void setSlow() {
		slowed = true;
	}
	void setPoison() {
		poisoned = true;
	}
	void setLowd() {
		lowerdef = true;
	}
	void setLowatk() {
		loweratk = true;
	}
	void setLowspd() {
		lowerspd = true;
	}
	void setImmun() {
		immun = true;
	}
	string getName() {
		return Name;
	}
	void setHP(int hp) {
		HP = hp;
	}
	void setDef(int d) {
		DEF = d;
	}
	void setAtk(int atk) {
		ATK = atk;
	}
	void setSpd(int spd) {
		Speed = spd;
	}
	void setType(int tp) {
		type = tp;
	}
	void setName(string nm) {
		Name = nm;
	}
	void showIcon();
	//void showIconpos(int x, int y);
	void Attack(Pokemon &appo)
	{
		appo.setHP(appo.getHP() - ((ATK*typeatk[type][appo.getType()]) - appo.getDef()));
	}
private:
	int Num;
	int HP;
	int ATK;
	int DEF;
	int Speed;
	int type;
	int abi;
	string Name;
	bool immun = false;
	bool slowed = false;
	bool poisoned = false;
	bool lowerspd = false;
	bool lowerdef = false;
	bool loweratk = false;
};

Pokemon::Pokemon(int num, string name, int tpe, int hp, int atk, int def, int spd, int ABI)
	:Num(num), Name(name), type(tpe), HP(hp), ATK(atk), DEF(def), Speed(spd), abi(ABI)
{
}

void Pokemon::showIcon()
{
	ifstream inFile;
	char icon;
	switch (Num)
	{
	case 1:
		inFile.open("001.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 2:
		inFile.open("002.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 3:
		inFile.open("001.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 4:
		inFile.open("004.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 5:
		inFile.open("005.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 6:
		inFile.open("006.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 7:
		inFile.open("007.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 8:
		inFile.open("008.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 9:
		inFile.open("009.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 10:
		inFile.open("010.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 11:
		inFile.open("011.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 12:
		inFile.open("012.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 13:
		inFile.open("013.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 14:
		inFile.open("014.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 15:
		inFile.open("015.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 16:
		inFile.open("016.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 17:
		inFile.open("017.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 18:
		inFile.open("018.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 19:
		inFile.open("019.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 20:
		inFile.open("020.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 21:
		inFile.open("021.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 22:
		inFile.open("022.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 23:
		inFile.open("023.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 24:
		inFile.open("024.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 25:
		inFile.open("025.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 26:
		inFile.open("026.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 27:
		inFile.open("027.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 28:
		inFile.open("028.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 29:
		inFile.open("029.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 30:
		inFile.open("030.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 31:
		inFile.open("031.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 32:
		inFile.open("032.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 33:
		inFile.open("033.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	case 34:
		inFile.open("034.txt");
		while (inFile.get(icon))
			cout << icon;
		break;
	}
}

//void Pokemon::showIconpos(int x, int y)
//{
//	ifstream inFile;
//	char icon;
//	rlutil::locate(x, y);
//	switch (Num)
//	{
//	case 1:
//		inFile.open("001.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 2:
//		inFile.open("002.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 3:
//		inFile.open("001.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 4:
//		inFile.open("004.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 5:
//		inFile.open("005.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 6:
//		inFile.open("006.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 7:
//		inFile.open("007.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 8:
//		inFile.open("008.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 9:
//		inFile.open("009.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 10:
//		inFile.open("010.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 11:
//		inFile.open("011.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 12:
//		inFile.open("012.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 13:
//		inFile.open("013.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 14:
//		inFile.open("014.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 15:
//		inFile.open("015.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 16:
//		inFile.open("016.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 17:
//		inFile.open("017.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 18:
//		inFile.open("018.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 19:
//		inFile.open("019.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 20:
//		inFile.open("020.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 21:
//		inFile.open("021.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 22:
//		inFile.open("022.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 23:
//		inFile.open("023.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 24:
//		inFile.open("024.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 25:
//		inFile.open("025.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 26:
//		inFile.open("026.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 27:
//		inFile.open("027.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 28:
//		inFile.open("028.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 29:
//		inFile.open("029.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 30:
//		inFile.open("030.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 31:
//		inFile.open("031.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 32:
//		inFile.open("032.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 33:
//		inFile.open("033.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	case 34:
//		inFile.open("034.txt");
//		while (inFile.get(icon))
//			cout << icon;
//		break;
//	}
//
//	cout << endl;
//}

void Pokemon::showInfo(int x, int y)
{
	showIcon();

	rlutil::locate(x, y);
	cout << "Type : " << Type[type] << endl;


	rlutil::locate(x, y + 1);
	cout << "Name :" << Name << endl;

	rlutil::locate(x, y + 2);
	cout << "Ability : " << Abilities[abi] << endl;
}

void Pokemon::showStats()
{
	cout << Name << "'s Stats :" << endl;
	cout << "-----------------------------" << endl;
	cout << "HP: " << HP << endl;
	cout << "DEF:¡@" << DEF << endl;
	cout << "ATK: " << ATK << endl;
	cout << "Speed: " << Speed << endl;
	cout << endl;

	if (poisoned == true)
	{
		cout << "Poisoned ><" << endl;
	}
	if (lowerspd == true)
	{
		cout << "Speed Lowered...." << endl;
	}
	if (lowerdef == true)
	{
		cout << "Defence Lowered...." << endl;
	}
	if (loweratk == true)
	{
		cout << "Attack Lowered...." << endl;
	}
}

void Pokemon::resetPokemon(Pokemon poke)
{
	HP = poke.getHP();
	ATK = poke.getAtk();
	DEF = poke.getDef();
	Speed = poke.getSpd();
}
#endif // !POKEMON_H
#pragma once