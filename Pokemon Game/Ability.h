#ifndef ABILITY_H
#define ABILITY_H

#include "Pokemon.h"

using namespace std;

class Ability {
public:
	Ability() {}
	virtual void execute(Pokemon &atk,Pokemon &def) { return; }//Virtual function execute
	virtual void prexecute(Pokemon &the) { return; }//Virtual function preexecute
	int getNum() {
		return num;
	}
private:
	int num;
};

#endif // !ABILITY_H
#pragma once

#ifndef HEAL_H
#define HEAL_H

class Heal :public Ability {
public:
	Heal() {}
	void execute(Pokemon &atk, Pokemon &def)
	{
		if (def.getABInum() != num)
			return;
		cout << def.getName() << " Healing..." << endl;
		def.setHP(def.getHP() + 3);
	}
	void prexecute(Pokemon &the) { return; }
	int getNum() {
		return num;
	}
private:
	int num = 1;
};
#endif // !HEAL_H
#pragma once

#ifndef BURNING_H
#define BURNING_H

class Burning :public Ability {
public:
	Burning() {}
	void execute(Pokemon &atk,Pokemon &def) {
		if (atk.getABInum() != num)
			return;
		int hit = rand() % 3 + 1;
		cout << def.getName() << " is burned, HP - " << hit << endl;
		def.setHP(def.getHP() - hit);
	}
	void prexecute(Pokemon &the) { return; }
	int getNum() {
		return num;
	}
private:
	int num = 2;
};
#endif // !BURNING_H
#pragma once

#ifndef COUNTERA_H
#define COUNTERA_H

class Counter_A :public Ability {
public:
	Counter_A() {}
	void execute(Pokemon &atk, Pokemon &def) {
		if (def.getABInum() != num)
			return;
		cout << def.getName() << " Counter Attacked !!" << endl;
		atk.setHP(atk.getHP() - (atk.getAtk() / 5));
	}
	void prexecute(Pokemon &the) { return; }
	int getNum() {
		return num;
	}
private:
	int num = 3;
};
#endif // !COUNTERA_H
#pragma once

#ifndef IMMUNOLOGY_H
#define IMMUNOLOGY_H

class Immunology :public Ability {
public:
	Immunology() {}
	void execute(Pokemon &atk, Pokemon &def) {
		return;
	}
	void prexecute(Pokemon &the) {
		if (!the.getImmun())
		{
			cout << the.getName() << "'s ";
			cout << "Immunology Activated !!" << endl;
			the.setImmun();
		}
	}
	int getNum() {
		return num;
	}
private:
	int num = 4;
};
#endif // !IMMUNOLOGY_H
#pragma once	

#ifndef LEECHLIFE_H
#define LEECHLIFE_H

class Leechlife :public Ability {
public:
	Leechlife() {}
	void execute(Pokemon &atk, Pokemon &def) {
		if (atk.getABInum() != num)
			return;
		int steal = rand() % 2 + 2;
		atk.setHP(atk.getHP() + steal);
		def.setHP(def.getHP() - steal);

		cout << atk.getName() << " Stealed Life from " << def.getName() << " while Attacking !" << endl;
	}
	void prexecute(Pokemon &the) { return; }
	int getNum() {
		return num;
	}
private:
	int num = 5;
};
#endif // !LEECHLIFE_H
#pragma once

#ifndef AVOID_H
#define AVOID_H

class Avoid :public Ability {
public:
	Avoid() {}
	void execute(Pokemon &atk, Pokemon &def) {
		if (def.getABInum() != num)
			return;
		int random = rand() % 5;
		if (random == 0)
		{
			cout << def.getName() << "Avoided the Attack !!" << endl;
			def.setHP(def.getHP() + atk.getAtk());
		}
	}
	void prexecute(Pokemon &the) { return; }
	int getNum() {
		return num;
	}
private:
	int num = 6;
};
#endif // !AVOID_H
#pragma once

#ifndef DOUBLEATTACK_H
#define DOUBLEATTACK_H

class Doubleattack :public Ability {
public:
	Doubleattack() {}
	void execute(Pokemon &atk, Pokemon &def) {
		if (atk.getABInum() != num)
			return;
		int random = rand() % 5;
		if (def.getHP() > 0 && random == 0);
		{
			cout << atk.getName() << " Double Attacked !!" << endl;
			def.setHP(def.getHP() - atk.getAtk());
		}
	}
	void prexecute(Pokemon &the) { return; }
	int getNum() {
		return num;
	}
private:
	int num = 7;
};
#endif // !DOUBLEATTACK_H
#pragma once

#ifndef POISON_H
#define POISON_H

class Poison :public Ability {
public:
	Poison() {}
	void execute(Pokemon &atk, Pokemon &def) {
		if (atk.getABInum() != num)
			return;
		if (def.getPoison())
			def.setHP(def.getHP() - 2);
		else
		{
			cout << def.getName() << " is Poisoned. " << endl;
			def.setPoison();
		}
	}
	void prexecute(Pokemon &the) { return; }
	int getNum() {
		return num;
	}
private:
	int num = 8;
};
#endif // !POISON_H
#pragma once

#ifndef LOWERSPEED_H
#define LOWERSPEED_H

class Lowerspeed :public Ability {
public:
	Lowerspeed() {}
	void execute(Pokemon &atk, Pokemon &def) {
		if (atk.getABInum() != num)
			return;
		if (!def.getImmun() && !def.getLowspd())
		{
			def.setLowspd();
			def.setSpd(def.getSpd() - 2);
			cout << def.getName() << "Speed Lowered. " << endl;
		}
	}
	void prexecute(Pokemon &the) { return; }
	int getNum() {
		return num;
	}
private:
	int num = 9;
};
#endif // !LOWERSPEED_H
#pragma once

#ifndef ROCKSKIN_H
#define ROCKSKIN_H

class Rockskin :public Ability {
public:
	Rockskin() {}
	void execute(Pokemon &atk, Pokemon &def) {
		return;
	}
	void prexecute(Pokemon &the) {
		cout << the.getName() << "'s ";
		cout << "Rock Skin Activated !!" << endl;
		the.setDef(the.getDef() + 2);
	}
	int getNum() {
		return num;
	}
private:
	int num = 10;
};
#endif // !ROCKSKIN_H
#pragma once

#ifndef LOWERDEF_H
#define LOWERDEF_H

class Lowerdef :public Ability {
public:
	Lowerdef() {}
	void execute(Pokemon &atk, Pokemon &def) {
		if (atk.getABInum() != num)
			return;
		if (!def.getImmun() && !def.getLowd())
		{
			def.setLowd();
			def.setDef(def.getDef() - 2);
			cout << def.getName() << "'s Defence Lowered ." << endl;
		}
	}
	void prexecute(Pokemon &the) { return; }
	int getNum() {
		return num;
	}
private:
	int num = 11;
};
#endif // !LOWERDEF_H
#pragma once

#ifndef LOWERATK_H
#define LOWERATK_H

class Loweratk :public Ability {
public:
	Loweratk() {}
	void execute(Pokemon &atk, Pokemon &def) {
		if (atk.getABInum() != num)
			return;
		if (!def.getImmun() && !def.getLowatk())
		{
			def.setLowatk();
			def.setAtk(def.getAtk() - 2);
			cout << def.getName() << "'s Attack is Lowered. " << endl;
		}
	}
	void prexecute(Pokemon &the) { return; }
	int getNum() {
		return num;
	}
private:
	int num = 12;
};
#endif // !LOWERATK_H
#pragma once