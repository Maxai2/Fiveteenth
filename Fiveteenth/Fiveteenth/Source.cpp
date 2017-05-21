#include <iostream>
#include "Functions.h"

using namespace std;

int main()
{
	frame();

	const int size = 16;
	int arr[size] = {};

	initialArr(arr, size);

	symbols();
	move(arr);

	cout << "\n\n\n";
}