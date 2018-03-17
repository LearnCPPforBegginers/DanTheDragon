#include <iostream>

using namespace std;

void sortNumbers(int arr[], char sortFrom, int sizeOfArray);

int main()
{
	int arr[] = { 41, 73, 2, 11, 63, 47 };
	int arrSize = sizeof(arr) / sizeof(int);

	sortNumbers(arr, 'M', arrSize);

	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
}

void sortNumbers(int arr[], char sortFrom, int sizeOfArray)
{
	bool numbersSwap = true;

	while (numbersSwap)
	{
		numbersSwap = false;
		for (int i = 1; i < sizeOfArray; i++)
		{
			switch (sortFrom)
			{
			case 'm':
				if (arr[i - 1] > arr[i])
				{
					int temp = arr[i - 1];
					arr[i - 1] = arr[i];
					arr[i] = temp;
					numbersSwap = true;
				}
				break;
			case 'M':
				if (arr[i - 1] < arr[i])
				{
					int temp = arr[i - 1];
					arr[i - 1] = arr[i];
					arr[i] = temp;
					numbersSwap = true;
				}
				break;
			default:
				break;
			}
		}	
	}
}
