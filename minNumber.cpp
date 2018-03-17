#include "stdafx.h"
#include<iostream>

using namespace std;

void numbersInput(double numbers[],int size);
void printNumbers(double numbers[], int size);

double minNumber(double numbers[],int size);
double maxNumber(double numbers[],int size);

int main()
{
	double numbers[5];
	numbersInput(numbers, 5);
	cout << "\n\nThe min number is: " << minNumber(numbers, 5) << "\n";
	cout << "The max number is: " << maxNumber(numbers, 5) << "\n\n";
	printNumbers(numbers, 5);
	return 0;
}
void numbersInput(double numbers[],int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter number " << i + 1 << "\n";
		cin >> numbers[i];
	}
	
}
void printNumbers(double numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout.width(5);
		cout << "  numbers[" << i << "] = " << numbers[i];
	}
	cout << "\n\n";
}
double minNumber(double numbers[],int size)
{
	double minNumber=numbers[0];
	for(int i=1;i<size;i++)
	{
		if (minNumber > numbers[i])
			minNumber = numbers[i];
	}
	return minNumber;
}
double maxNumber(double numbers[], int size)
{
	double maxNumber = numbers[0];
	for (int i = 1; i < size; i++)
	{
		if (maxNumber < numbers[i])
			maxNumber = numbers[i];
	}
	return maxNumber;
}
