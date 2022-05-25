#include <iostream>
#include <time.h>



void make(int* array, int mass)
{
	for (int i = 0; i < mass; i++)
	{
		array[i] = (rand() % 100) + 1;
	}
}

void print(int* array, int mass)
{
	for (int i = 0; i < mass; i++)
	{
		std::cout << " " << array[i];
	}
	std::cout << "\n";
}

void sort1(int* array, int mass)
{
	for (int i = mass - 1; i > 0; i--)
	{
		int x = 0;
		int n = 0;
		for (int j = 0; j <= i; j++)
		{
			if (array[j] > x) { x = array[j]; n = j; }
			if (i == j) { array[n] = array[j]; array[j] = x; }
		}
		if (x == 0) break;
	}
}

void sort2(int* array, int mass)
{
	int X = mass;
	do
	{
		bool i = 0;
		for (int j = 0; j < X-1; j++)
		{
			if (array[j]>array[j+1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				i = 1;
			}
		}
		X--;
		if (i == 0||X==0)break;
	} while (mass);
}


int main()
{
	srand(time(nullptr));
	int mass = 10;
	int* array = new int[mass];

	void (*pMake)(int*, int);
	void (*pPrint)(int*, int);
	void (*pS1)(int*, int);
	void (*pS2)(int*, int);
	pMake = make;
	pPrint = print;
	pS1 = sort1;
	pS2 = sort2;
	(*pMake)(array, mass);
	(*pPrint)(array, mass);
	(*pS1)(array, mass);
	(*pPrint)(array, mass);
	std::cout << "\n";
	(*pMake)(array, mass);
	(*pPrint)(array, mass);
	(*pS2)(array, mass);
	(*pPrint)(array, mass);

	return 0;
}