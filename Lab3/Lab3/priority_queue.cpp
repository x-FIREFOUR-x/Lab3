#include "priority_queue.h"

bool priority_queue::empty()
{
	if (size != 0)
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
	int* value_new = new int[size + 1];
	int* priority_new = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		value_new[i] = value[i];
		priority_new[i] = priority[i];
	}
	value_new[size] = value_el;
	priority_new[size] = priority_el;

	if (size > 0)
	{
		delete[] value;
		delete[] priority;
	}

	value = value_new;
	priority = priority_new;

	size++;
}

int priority_queue::pop()
{

	int min_priority = priority[0];
	int index_el = 0;
	for (int i = 1; i < size; i++)
	{
		if (min_priority > priority[i])
		{
			min_priority = priority[i];
			index_el = i;
		}
	}
	int element = value[index_el];

	int* value_new = new int[size - 1];
	int* priority_new = new int[size - 1];

	for (int i = 0; i < index_el; i++)
	{
		value_new[i] = value[i];
		priority_new[i] = priority[i];
	}
	for (int i = index_el + 1; i < size; i++)
	{
		value_new[i - 1] = value[i];
		priority_new[i - 1] = priority[i];
	}

	if (size > 0)
	{
		delete[] value;
		delete[] priority;
	}

	value = value_new;
	priority = priority_new;

	size--;

	return element;
}

int priority_queue::size_queue()
{
	return size;
}