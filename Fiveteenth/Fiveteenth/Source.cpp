#include <iostream>
#include <windows.h>
#include "Functions.h"

using namespace std;

HANDLE f = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	frame();

	const int size = 16;
	int arr[size] = {};

	initialArr(arr, size);

	symbols();
	move(arr);

	SetConsoleCursorPosition(f, { 20, 15 });
	cout << "U WIN!!!!\n";
}