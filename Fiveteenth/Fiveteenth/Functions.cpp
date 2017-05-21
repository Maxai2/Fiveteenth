#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void frame()
{
	int rowS = 5, rowF = 13, colS = 16, colF = 29;

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
	int temp = 1, i = 1;
	bool have = false;
	srand(time(0));
	int checkArr[16] = {};

	while (true)
	{
		arr[temp - 1] = checkArr[temp - 1] = rand() % 16;

		for (int j = 0; j < temp - 1; j++)
		{
			if (arr[temp - 1] == checkArr[j])
			{
				have = true;
				j = temp - 1;
			}	
		}		
		
		if (have == false)
			temp++;
		else
			have = false;

		if (temp == 17)
			break;
	}
}

void show(int arr[], int length)
{
	int turn = 1;
	short row = 6;
	SetConsoleCursorPosition(h, { 17, row });
	for (int i = 0; i < length; i++)
	{
		if (turn % 4 == 0)
		{
			if (arr[i] * 10 < 100 && arr[i] != 0)
				cout << 0 << arr[i];
			else if (arr[i] == 0)
				cout << " ";
			else
				cout << arr[i];

			row += 2;
			SetConsoleCursorPosition(h, { 17, row });
		}
		else
		{
			if (arr[i] * 10 < 100 && arr[i] != 0)
				cout << 0 << arr[i];
			else if (arr[i] == 0)
				cout << "  ";
			else
				cout << arr[i];

			if (turn % 4 != 0)
				cout << " ";
		}

		turn++;
	}
}

int findZero(int arr[])
{
	for (int i = 0; i < 16; i++)
	{
		if (arr[i] == 0)
			return i;
	}
}

bool cheker(int arr[], int length)
{
	for (int i = 0; i < length; i += 2)
	{
		if (arr[i] > arr[i + 1])
			return false;
		else
			return true;
	}
}
void move(int arr[])
{
	int key, temp = 0;
	while (true)
	{
		show(arr, 16);
		symbols();
		temp = findZero(arr);

		key = getch();
		if (key == 224)
			key = getch();

		if (key == 72) // Up
		{
			arr[temp] = arr[temp + 4];
			arr[temp + 4] = 0;
		}
		else if (key == 80) // Down
		{
			arr[temp] = arr[temp - 4];
			arr[temp - 4] = 0;
		}
		else if (key == 75) // Left
		{
			arr[temp] = arr[temp + 1];
			arr[temp + 1] = 0;
		}
		else if (key == 77) // Right
		{
			arr[temp] = arr[temp - 1];
			arr[temp - 1] = 0;
		}
	}
}