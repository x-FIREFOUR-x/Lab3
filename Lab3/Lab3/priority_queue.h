class priority_queue
{
private:
	int* value;				// massiv value elements queue 
	int* priority;			// massiv priority elements queue
	int _size = 0 ;			// size queue

public:
	bool empty();			
	void push(int, int);	
	int	pop();				
	int size();				
};