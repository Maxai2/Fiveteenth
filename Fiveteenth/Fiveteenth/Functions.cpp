#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void frame()
{
	int rowS = 4, rowF = 14, colS = 16, colF = 31;

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
	int rowS = 6, rowF = 12, colS = 16, colF = 30, tempThree, tempOne;
	tempThree = tempOne = colS;

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
		tempThree = tempOne = 16;
	}
}

void initialArr(int arr[], int length)
{
	int temp = 1;
	bool have = false;
	srand(time(0));
	int checkArr[16] = {};

	for (int i = 0; i < length; i++)
	{
		checkArr[i] = arr[i] = rand() % 16;

		for (int j = 0; j < temp; j++)
		{
			if (arr[i] == checkArr[j] && i >= 1)
				have = true;
		}		
	}
}

void show(int arr[], int length)
{
	int turn = 0;
	short row = 6;
	SetConsoleCursorPosition(h, { 17, row });
	for (int i = 0; i < length; i++)
	{
		if (turn % 4 == 0 && turn != 0)
		{
			if (arr[i] * 10 < 100 && arr[i] != 0)
			{
				row += 2;
				cout << SetConsoleCursorPosition(h, { 17, row }) << 0 << arr[i] ;
			}
			else if (arr[i] == 0)
				cout << "  ";
			else
			{
				row += 2;
				cout << SetConsoleCursorPosition(h, { 17, row }) << arr[i] ;
			}
		}
		else
		{
			if (arr[i] * 10 < 100 && arr[i] != 0)
				cout << 0 << arr[i] << "  ";
			else if (arr[i] == 0)
				cout << "  ";
			else
				cout << arr[i] << "  ";
		}

		turn++;
	}
}