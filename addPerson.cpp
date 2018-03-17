#include <iostream>
#include <string>
#include "library.h"

void showHelp()
{
	std::cout << "This is help!\nPress X to close this shit!\n\n";
}

void enterData(int *i, personalData person[], std::string *firstName, std::string *lastName, std::string *phoneNumber, std::string *age)
{	
		person[*i].firstName = *firstName;
		person[*i].lastName = *lastName;
		person[*i].phoneNumber = *phoneNumber;
		person[*i].age = *age;
}

void enterPersonToStruct()
{
	int numberOfEntries = 0;
	int *numberOfEntriesPtr = &numberOfEntries;
	const int numberOfPersons = 5;

	personalData person[numberOfPersons];
	personalData *personPtr = &person[0];

	std::string tmp[4];
	std::string inputList[4] = { "First Name", "Last Name", "Phone Number", "Age" };

	std::string *tmpInputName = &tmp[0];
	std::string *tmpInputLName = &tmp[1];
	std::string *tmpInputPhone = &tmp[2];
	std::string *tmpInputAge = &tmp[3];

	for (int i = 0; i < numberOfPersons; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << "Enter " << inputList[j] << ": ";
			std::cin >> tmp[j];
		}
		enterData(numberOfEntriesPtr, personPtr + i, tmpInputName, tmpInputLName, tmpInputPhone, tmpInputAge);
		std::cout << "\n\n";
	}

	for (int i = 0; i < numberOfPersons; i++)
	{
		std::cout << "\nFirst Name: " << (*(personPtr + i)).firstName << "\n";
		std::cout << "Last Name: " << (*(personPtr + i)).lastName << "\n";
		std::cout << "Phone: " << (*(personPtr + i)).phoneNumber << "\n";
		std::cout << "Age: " << (*(personPtr + i)).age << "\n\n";
	}
	return;
}
