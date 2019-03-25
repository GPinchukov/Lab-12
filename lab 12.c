#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

const int SIZE = 150;

struct hash
{
	int value; 
	int key;
	int next; 
};

int hashFunc(int k)
{
	return k % 10;
}

struct hash table[150];

int main()
{
	int pointers[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		pointers[i] = -1;
	}
	for (i = 0; i < 150; i++)
	{
		table[i].value = -1;
		table[i].next = -1;
	}

	printf("Enter number of iterations: ");
	int n;
	scanf_s("%i", &n);
	int min_val = 100000;
	int min_key = 100000;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		int value = rand() % 75;
		int key = hashFunc(value);
		table[i].value = value;
		table[i].key = key;
		if (pointers[key] != -1)
		{
			table[pointers[key]].next = i;
		}
		pointers[key] = i;
		printf("Value: %i Key: %i\n", value, key);

		if (key < min_key)
		{
			min_val = value;
			min_key = key;
		}
	}
	printf("\nMin key = %i\n", min_key);
	return 0;
}


