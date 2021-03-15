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
	int* value_new = new int[_size + 1];
	int* priority_new = new int[_size + 1];

	for (int i = 0; i < _size; i++)
	{
		value_new[i] = value[i];
		priority_new[i] = priority[i];
	}
	value_new[_size] = value_el;
	priority_new[_size] = priority_el;

	if (_size > 0)
	{
		delete[] value;
		delete[] priority;
	}

	value = value_new;
	priority = priority_new;

	_size++;
}

int priority_queue::pop()
{
	if (_size == 0)
	{
		throw "try to remove from empty";
	}

	int min_priority = priority[0];
	int index_el = 0;
	for (int i = 1; i < _size; i++)
	{
		if (min_priority > priority[i])
		{
			min_priority = priority[i];
			index_el = i;
		}
	}
	int element = value[index_el];

	int* value_new = new int[_size - 1];
	int* priority_new = new int[_size - 1];

	for (int i = 0; i < index_el; i++)
	{
		value_new[i] = value[i];
		priority_new[i] = priority[i];
	}
	for (int i = index_el + 1; i < _size; i++)
	{
		value_new[i - 1] = value[i];
		priority_new[i - 1] = priority[i];
	}

	if (_size > 0)
	{
		delete[] value;
		delete[] priority;
	}

	value = value_new;
	priority = priority_new;

	_size--;

	return element;
}

int priority_queue::size()
{
	return _size;
}