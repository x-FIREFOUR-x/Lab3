#include <fstream>

class labyrynth
{
private:
	char** map;
	int** graph;
	int height, width;
	void parametres(std::ifstream&);
	void drawPath(int*, int, int);
public:
	void input();
	void output();
	int pathfinding(int, int, int, int);
};

