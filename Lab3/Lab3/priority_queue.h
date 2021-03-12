class priority_queue
{
private:
	int* value;				// massiv value elements queue 
	int* priority;			// massiv priority elements queue
	int size = 0;			// size queue

public:
	priority_queue() { size = 0; }
	bool empty();
	void push(int, int);
	int	pop();
	int size_queue();
};