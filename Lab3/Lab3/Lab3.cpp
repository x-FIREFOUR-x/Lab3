#include <iostream>
#include "priority_queue.h"
#include "labyrynth.h"

using namespace std;

int main()
{
	labyrynth lab;
	lab.input();
	cout << lab.pathfinding(1, 6, 10, 1);
	lab.output();

	return 0;
}


