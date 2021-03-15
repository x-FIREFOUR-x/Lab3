#include "priority_queue.h"

bool priority_queue::empty()
{
	if (_size != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void priority_queue::push(int value_el, int priority_el)
{

	if (_size + 1 > real_size) // check whether the real arrays needs to be expand (doubled)
	{
		if (real_size == 0)
		{
			real_size = 1;
		}
		else
		{
			real_size = real_size * 2;
		}

		int* value_new = new int[real_size];			// expand arrays
		int* priority_new = new int[real_size];

		for (int i = 0; i < _size; i++)			// overwrite elements queue(arrays) in new arrays 
		{
			value_new[i] = value[i];
			priority_new[i] = priority[i];
		}
		value_new[_size] = value_el;
		priority_new[_size] = priority_el;

		if (_size > 0)		// check whether is old arrays
		{
			delete[] value;		// delete old arrays
			delete[] priority;
		}

		value = value_new;	
		priority = priority_new;

		_size++;
	}
	else
	{
		value[_size] = value_el;			// adding a new queue element
		priority[_size] = priority_el;

		_size++;
	}

	
}

int priority_queue::pop()
{
	if (_size == 0)
	{
		throw "try to remove from empty";
	}

	int min_priority = priority[0];
	int index_el = 0;
	for (int i = 1; i < _size; i++)			// search element queue than is the most priority
	{
		if (min_priority > priority[i])
		{
			min_priority = priority[i];
			index_el = i;
		}
	}
	int element = value[index_el];

	for (int i = index_el; i < _size; i++)	// overwrite without this element (delete)
	{
		value[i] = value[i+1];
		priority[i] = priority[i+1];
	}

	_size--;

	return element;
}

int priority_queue::size()
{
	return _size;
}