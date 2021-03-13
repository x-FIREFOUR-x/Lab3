#include "labyrynth.h"
#include<string>
#include<fstream>
#include <iostream>

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