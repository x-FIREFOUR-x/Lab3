#include <iostream>
#include "priority_queue.h"
#include "labyrynth.h"

using namespace std;

int main()
{
	labyrynth lab;
	lab.input();
	cout << lab.pathfinding(1, 6, 6, 3);
	return 0;
}


