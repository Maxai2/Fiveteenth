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
				cout << "  ";
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
	int temp = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < arr[i + 1])
			temp++;
	}

	if (temp == 14 && arr[15] == 0)
	{
		temp = 0;
		return true;
	}
	else
	{
		temp = 0;
		return false;
	}

}

void example(int arr[])
{
	for (int i = 0; i < 16; i++)
	{
		if (i != 15)
			arr[i] = i + 1;
		else
			arr[i] = 0;
	}
}

void cheatCode(int arr[])
{
	int sec = 7, fNum = 0, sNum = 0, temp = 0;
	while (sec != -1)
	{
		SetConsoleCursorPosition(h, { 0, 0 });
		cout << "          You have a 10 second to use cheat: " << sec << endl;

		cout << "First number(1-16): ";
		if (kbhit())
		{
			cin >> fNum;
			cout << "Second number(1-16): ";
			cin >> sNum;

			fNum--; sNum--;

			temp = arr[fNum];
			arr[fNum] = arr[sNum];
			arr[sNum] = temp;
			show(arr, 16);
			symbols();
			SetConsoleCursorPosition(h, { 20, 1 });
			cout << "   ";
			SetConsoleCursorPosition(h, { 20, 2 });
			cout << "   ";
		}

		Sleep(1000);
		sec--;
		SetConsoleCursorPosition(h, { 33, 0 });
		cout << "  ";
	}
}

void clearCheat()
{
	for (short i = 0; i < 3; i++)
	{
		SetConsoleCursorPosition(h, { 0,i });
		cout << "\t\t\t\t\t\t";
	}

}

void move(int arr[])
{
	int key, temp = 0;
	bool cheat = true;
	SetConsoleCursorPosition(h, { 0,0 });
	cout << "Input \'`\' for cheat(7 sec) but use it at once";
	while (true)
	{
		show(arr, 16);
		symbols();
		temp = findZero(arr);

		key = getch();
		if (key == 224)
			key = getch();

		if (key == 72 && temp < 12) // Up
		{
			arr[temp] = arr[temp + 4];
			arr[temp + 4] = 0;
		}
		else if (key == 80 && temp > 3) // Down
		{
			arr[temp] = arr[temp - 4];
			arr[temp - 4] = 0;
		}
		else if (key == 75 && temp != 3 && temp != 7 && temp != 11 && temp != 15) // Left
		{
			arr[temp] = arr[temp + 1];
			arr[temp + 1] = 0;
		}
		else if (key == 77 && temp % 4 != 0) // Right
		{
			arr[temp] = arr[temp - 1];
			arr[temp - 1] = 0;
		}
		else if (key == 96 && cheat == true) // ` 
		{
			cheatCode(arr);
			cheat = false;
			clearCheat();
		}
		else if (key == 23) // ctrl + W
		{
			example(arr);
			show(arr, 16);
			symbols();
		}
		else if (key == 27) // esc
		{
			break;
		}

		if (cheker(arr, 16))
		{
			break;
			show(arr, 16);
			symbols();
		}
	}
}