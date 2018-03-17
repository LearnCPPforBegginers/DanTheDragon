#include <iostream>
#include <string>

int main()
{
	int pinNumber = 1234;
	int retryPin = 0;
	int userPinInput;
	int maxTries = 5;

	do 
	{
		std::cout << "Enter pin number: ";
		std::cin >> userPinInput;
		
		if (pinNumber == userPinInput)
		{
			std::cout << "The pin you have entered is correct!\n";
			retryPin = maxTries;
		}
		else
		{
			retryPin++;
			std::cout << "Wrong pin number! Please try again.\n Number of tryes left: " << maxTries - retryPin << std::endl;
		}

	} while (retryPin < maxTries);

	return 0;
}
