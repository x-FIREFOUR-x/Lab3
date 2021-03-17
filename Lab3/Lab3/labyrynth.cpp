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
			if (map[i][j] == 'X')
				fout << map[i][j];
			else
				fout << map[i][j];
		fout << endl;
	}
	fout.close();
}

int labyrynth::pathfinding(int xs, int ys, int xf, int yf)
{
	priority_queue q;
	int n = height * width;
	//int k = 0;
	int idf = xf + yf * width;
	int* cost = new int[n];
	int* from = new int[n];
	for (int i = 0; i < n; i++)
	{
		cost[i] = INF;
	}
	int id = xs + ys * width;
	q.push(id, 0);
	cost[id] = 0;
	from[id] = -1;
	map[ys][xs] = '0';
	while (!q.empty())
	{
		id = q.pop();
		//k++;
		if (map[id / width - 1][id % width] == ' ')
		{

			if (cost[id - width] > cost[id] + 1)
			{				
				cost[id - width] = cost[id] + 1;
				from[id - width] = id;
				//map[id / width - 1][id % width] = k % 10 + 48;
				map[id / width - 1][id % width] = '^';
				q.push(id - width, cost[id - width] + heuristic(id, idf));
			}
		}
		if (map[id / width + 1][id % width] == ' ')
		{
			if (cost[id + width] > cost[id] + 1)
			{
				cost[id + width] = cost[id] + 1;
				from[id + width] = id;
				//map[id / width + 1][id % width] = k % 10 + 48;
				map[id / width + 1][id % width] = '|';
				q.push(id + width, cost[id + width] + heuristic(id, idf));
			}
		}
		if (map[id / width][id % width - 1] == ' ')
		{
			if (cost[id - 1] > cost[id] + 1)
			{
				cost[id - 1] = cost[id] + 1;
				from[id - 1] = id;
				//map[id / width][id % width - 1] = k % 10 + 48;
				map[id / width][id % width - 1] = '<';
				q.push(id - 1, cost[id - 1] + heuristic(id, idf));
			}
		}
		if (map[id / width][id % width + 1] == ' ')
		{
			if (cost[id + 1] > cost[id] + 1)
			{
				cost[id + 1] = cost[id] + 1;
				from[id + 1] = id;
				//map[id / width][id % width + 1] = k % 10 + 48;
				map[id / width][id % width + 1] = '>';
				q.push(id + 1, cost[id + 1] + heuristic(id, idf));
			}
		}
		if (id == (yf * width + xf))
		{
			//drawPath(from, id, cost[id]);
			return cost[id];
		}	
	}
}

/*void labyrynth::drawPath(int* from, int id, int count)
{
	int i = id;
	while (from[i] != -1)
	{
		if (count % 36 > 9)
			map[i / width][i % width] = 97 + (count % 36 - 10);
		else
			map[i / width][i % width] = 48 + count % 36;
		i = from[i];
		count--;
	}
	map[i / width][i % width] = '0';
}*/

int labyrynth::heuristic(int a, int b)
{
	int x1 = a % width;
	int y1 = a / width;
	int x2 = b % width;
	int y2 = b / width;
	return (abs(y2 - y1) + abs(x2 - x1));
}