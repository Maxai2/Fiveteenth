#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void frame()
{
	int rowS = 4, rowF = 21, colS = 15, colF = 32;

	for (short i = rowS; i <= rowF; i++)
	{
		for (short j = colS; j <= colF; j++)
		{
			if (i == rowS || i == rowF)
			{
				SetConsoleCursorPosition(h, { j, i });

				cout << char(178);
			}
			else if (rowS < i && i < rowF && (j == colS || j == colF))
			{
				SetConsoleCursorPosition(h, { j, i });

				cout << char(178);
			}
		}
	}
}

void symbols()
{
	int rowS = 6, rowF = 12, colS = 15, colF = 31, tempThree = 15, tempOne = 15;

	for (short i = rowS; i <= rowF; i++)
	{
		for (short j = colS; j <= colF; j++)
		{
			if (i % 2 == 0 && j == tempThree + 3 && j != colF)
			{
				SetConsoleCursorPosition(h, { j, i });
				tempThree = j;
				cout << char(179);
			}
			else if (i % 2 != 0 && j == tempOne + 2 && j != colF)
			{
				SetConsoleCursorPosition(h, { j, i });
				tempOne = j;
				cout << char(196);
			}
		}
		tempThree = tempOne = 15;
	}
}