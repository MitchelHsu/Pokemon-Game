#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "rlutil.h"

using namespace std;

class Map {
public:
	Map() {
		loadmap();
	}
	void showMap();
	char getChar(int i, int j);//Return character in certain position
	bool checkBlock(int i, int j);//Checking wall
	void print(char obj);
private:
	vector < vector< char > > map;
	vector < vector< int > > block;
	void loadmap();
};

void Map::loadmap()
{
	ifstream inFile("yzumap.txt");

	char charac;
	vector <char> line;
	vector <int> blockline;
	while (inFile.get(charac))
	{
		if (charac == '\n')
		{
			line.push_back(charac);
			map.push_back(line);
			block.push_back(blockline);
			int size = line.size();
			for (int i = 0; i < size; i++)
			{
				line.pop_back();
			}
			int bsize = blockline.size();
			for (int i = 0; i < bsize; i++)
			{
				blockline.pop_back();
			}
		}
		else
		{
			if (charac == '*' || charac == '1' || charac == '2' || charac == '3' || charac == '4' || charac == '5' || charac == '6'
				|| charac == '7' || charac == '8' || charac == '9' || charac == '!') blockline.push_back(0);
			else blockline.push_back(1);

			line.push_back(charac);
		}
	}

	inFile.close();
}

void Map::showMap()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			switch (map[i][j])
			{
			case ';':
				rlutil::setColor(2);
				cout << map[i][j];
				rlutil::setColor(7);
				break;
			case '!':
				rlutil::setColor(6);
				cout << map[i][j];
				rlutil::setColor(7);
				break;
			case '~':
				rlutil::setColor(3);
				cout << map[i][j];
				rlutil::setColor(7);
				break;
			case '#':
				rlutil::setColor(14);
				cout << map[i][j];
				rlutil::setColor(7);
				break;
			default:
				cout << map[i][j];
				break;
			}
		}
	}
}

void Map::print(char obj)
{
	switch (obj)
	{
	case ';':
		rlutil::setColor(2);
		cout << obj;
		rlutil::setColor(7);
		break;
	case '!':
		rlutil::setColor(6);
		cout << obj;
		rlutil::setColor(7);
		break;
	case '~':
		rlutil::setColor(3);
		cout << obj;
		rlutil::setColor(7);
		break;
	case '#':
		rlutil::setColor(14);
		cout << obj;
		rlutil::setColor(7);
		break;
	default:
		cout << obj;
		break;
	}
}

char Map::getChar(int i, int j)
{
	return map[j - 1][i - 1];
}

bool Map::checkBlock(int i, int j)
{
	if (block[j - 1][i - 1] == 0)
		return false;
	
	return true;
}
#endif // !MAP_H
#pragma once
