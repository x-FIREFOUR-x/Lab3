#include "labyrynth.h"
#include <fstream>
#include <iostream>
#include "priority_queue.h"

#define INF 10000;

using namespace std;

void labyrynth::parametres(ifstream&fin)
{
	int i, j;
	char c;
	i = 1;
	j = 0;
	fin.get(c);
	while (c != '\n')
	{
		j++;
		fin.get(c);
	}
	width = j;
	while (!fin.eof())
	{
		i++;
		for (int i = 0; i < width + 1; i++)
		{
			fin.get(c);
		}
	}
	height = i;
}

void labyrynth::input()
{
	char c;
	ifstream fin;
	fin.open("input.txt");
	parametres(fin);
	fin.clear();
	fin.seekg(0, fin.beg);
	map = new char* [height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new char[width];
		for (int j = 0; j < width; j++)
		{
			fin.get(c);
			map[i][j] = c;
		}
		fin.get(c);
	}
	fin.close();
}

void labyrynth::output()
{
	ofstream fout("output.txt");
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			fout << map[i][j];
		fout << endl;
	}
	fout.close();
}

int labyrynth::pathfinding(int xs, int ys, int xf, int yf)
{
	priority_queue q;
	int n = height * width;
	int* cost = new int [n];
	for (int i = 0; i < n; i++)
	{
		cost[i] = INF;
	}
	int id = xs + ys * width;
	q.push(id, 0);
	cost[id] = 0;
	while (!q.empty())
	{
		id = q.pop();
		if (map[id / width - 1][id % width] == ' ')
		{
			
			if (cost[id - width] > cost[id] + 1)
			{
				cost[id - width] = cost[id] + 1;
				q.push(id - width, cost[id - width]);
			}
		}
		if (map[id / width + 1][id % width] == ' ')
		{
			if (cost[id + width] > cost[id] + 1)
			{
				cost[id + width] = cost[id] + 1;
				q.push(id + width, cost[id + width]);
			}
		}
		if (map[id / width][id % width - 1] == ' ')
		{
			if (cost[id - 1] > cost[id] + 1)
			{
				cost[id - 1] = cost[id] + 1;
				q.push(id - 1, cost[id - 1]);
			}
		}
		if (map[id / width][id % width + 1] == ' ')
		{
			if (cost[id + 1] > cost[id] + 1)
			{
				cost[id + 1] = cost[id] + 1;
				q.push(id + 1, cost[id + 1]);
			}
		}
		if (id == (yf * width + xf)) 
			return cost[id];
	}
}