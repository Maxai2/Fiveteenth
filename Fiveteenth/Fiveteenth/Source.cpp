#include <iostream>
#include "Functions.h"

using namespace std;

int main()
{
	frame();

	const int size = 16;
	int arr[size] = {};

	initialArr(arr, size);
	show(arr, size);

	symbols();
	cout << "\n\n\n";
}