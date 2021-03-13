#include <fstream>

class labyrynth
{
private:
	char**map;
	int height, width;
	void parametres(std::ifstream&);
public:
	void input();
	void output();
};

