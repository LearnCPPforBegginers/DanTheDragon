#include <iostream>
#include <string>

void displayTable(char arr[3][3]); // Display the X-O table from 1 to 9
void validateAndApply(int x, int y, char arr[3][3], char xo); // Check the user input for validity
void gameEngine(char userChoice, char arr[3][3], char xo); // Place and verify in array

bool resetTable(char arr[3][3]); // Sets the table array to the default numbers of 1 to 9
bool exitProgramQuestion(); // Asks the user if they want to play again

bool isGameWon; // This variable defines if the game is won or it's ongoing/draw
bool isGameDraw; // This variable defines if the game is draw or it's ongoing/won
bool stateX = true; // It determins if it's X or O's turn

char winCheck(char winner, char arr[3][3]); // Checks the array for a winning combination
char xo = 'X';

int main()
{
	bool playAgain = true;
	char arr[3][3];
	
	resetTable(arr);
	
	system("cls");
	isGameWon = false;
	isGameDraw = false;
	std::string userChoiceStr;
	do
	{
		while ((isGameWon == false) && (isGameDraw == false))
		{
			if (playAgain == true)
			{
				xo = 'X';
				stateX = true;
			}
			playAgain = false;
			isGameWon = false;
			displayTable(arr);
			std::cout << "Chose a location for [" << xo << "]: ";
			std::cin >> userChoiceStr;
			char* userChoice = &userChoiceStr.at(0);
			system("cls");

			if (isdigit(*userChoice))
			{
				if ((*userChoice > 48) && (*userChoice < 59))
				{
					if (stateX == true)
					{
						gameEngine(*userChoice, arr, 'X');
						xo = 'O';
						stateX = false;
					}
					else
					{
						gameEngine(*userChoice, arr, 'O');
						xo = 'X';
						stateX = true;
					}
				}
				else
				{
					std::cout << "\nPlease enter a number between 1 and 9!\n\n";
				}
			}
			else
			{
				std::cout << "Invalid character! Please enter a number between 1 and 9!\n\n";
			}
		}
		if (isGameWon == true)
		{
			displayTable(arr);
			std::cout << "\nThe winner is " << winCheck(xo, arr) << "!\n\n\n";
			playAgain = exitProgramQuestion();
			system("cls");
			isGameWon = resetTable(arr);
		}
		else if (isGameDraw == true)
		{
			displayTable(arr);
			std::cout << "\nThis game is a DRAW!\n\n\n";
			playAgain = exitProgramQuestion();
			system("cls");
			isGameDraw = resetTable(arr);
		}
	} while (playAgain == true);
	return 0;
}

void displayTable(char arr[3][3])
{
	std::cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout.width(6);
			std::cout << arr[i][j];
		}
		std::cout << "\n\n";
	}
}

char winCheck(char winner, char arr[3][3])
{
	if (((arr[0][0] == arr[0][1]) && (arr[0][2] == arr[0][0])) || ((arr[1][0] == arr[1][1]) && (arr[1][2] == arr[1][0]))
		|| ((arr[2][0] == arr[2][1]) && (arr[2][2] == arr[2][0])))
	{
		isGameDraw = false;
		isGameWon = true;
		if (winner == 'X')
		{
			winner = 'O';
			return winner;
		}
		else if (winner == 'O')
		{
			winner = 'X';
			return winner;
		}
	}
	else if ((arr[0][0] == arr[1][1]) && (arr[2][2] == arr[0][0]) || (arr[0][2] == arr[1][1]) && (arr[2][0] == arr[0][2]))
	{
		isGameDraw = false;
		isGameWon = true;
		if (winner == 'X')
		{
			winner = 'O';
			return winner;
		}
		else if (winner == 'O')
		{
			winner = 'X';
			return winner;
		}
	}
	if (((arr[0][0] == arr[1][0]) && (arr[2][0] == arr[0][0])) || ((arr[0][1] == arr[1][1]) && (arr[2][1] == arr[0][1]))
		|| ((arr[0][2] == arr[1][2]) && (arr[2][2] == arr[0][2])))
	{
		isGameDraw = false;
		isGameWon = true;
		if (winner == 'X')
		{
			winner = 'O';
			return winner;
		}
		else if (winner == 'O')
		{
			winner = 'X';
			return winner;
		}
	}
	if ((arr[0][0] != '1') && (arr[0][1] != '2') && (arr[0][2] != '3') && (arr[1][0] != '4') && (arr[1][1] != '5') && (arr[1][2] != '6')
		&& (arr[2][0] != '7') && (arr[2][1] != '8') && (arr[2][2] != '9'))
	{
		isGameDraw = true;
		isGameWon = false;
		return '-';
	}
	else
	{
		isGameDraw = false;
		isGameWon = false;
		return '-';
	}
}

void validateAndApply(int x, int y, char arr[3][3], char xo)
{
	if ((arr[x][y] != 'X') && (arr[x][y] != 'O'))
	{
		arr[x][y] = xo;
		winCheck(xo, arr);
	}
	else
	{
		std::cout << "That spot is already asigned!";
	}
}

void gameEngine(char userChoice, char arr[3][3], char xo)
{
	switch (userChoice)
	{
	case '1':
		validateAndApply(0, 0, arr, xo);
		break;
	case '2':
		validateAndApply(0, 1, arr, xo);
		break;
	case '3':
		validateAndApply(0, 2, arr, xo);
		break;
	case '4':
		validateAndApply(1, 0, arr, xo);
		break;
	case '5':
		validateAndApply(1, 1, arr, xo);
		break;
	case '6':
		validateAndApply(1, 2, arr, xo);
		break;
	case '7':
		validateAndApply(2, 0, arr, xo);
		break;
	case '8':
		validateAndApply(2, 1, arr, xo);
		break;
	case '9':
		validateAndApply(2, 2, arr, xo);
		break;
	default:
		break;
	}
}

bool resetTable(char arr[3][3])
{
	char *arrPtr = arr[0];
	for (int i = 0; i < 9; i++)
	{
		*arrPtr = 49 + i;
		arrPtr++;
	}

	return false;
}

bool exitProgramQuestion()
{
	char userResponse;
	std::cout << "\nDo you want to continue (y/n)? ";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> userResponse;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return (userResponse == 'y') || (userResponse == 'Y');
}
