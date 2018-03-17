#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

int main()
{
	int h = 0;
	int m = 0;
	int s = 0;

	for (int i = 1; i > 0; i++)
	{
		++s;
		if (s == 60 && m != 59)
		{
			m++;
			s = 0;
		}
		else if (m == 59 && s == 60 && h != 23)
		{
			h++;
			m = 0;
			s = 0;
		}
		else if ((h == 23) && (m == 59) && (s == 60))
		{
			h = 0;
			m = 0;
			s = 0;
		}
		system("cls");
		cout << "\n";
		cout << "  " << setw(2) << setfill('0') << h << ":"; 
		cout << setw(2) << setfill('0') << m << ":";
		cout << setw(2) << setfill('0') << s << "\n\n";
		Sleep(999);
	}
	return 0;
}
