#include <iostream>
using namespace std;

int _max[2]{};
int _min[2]{};
int operation = 0;

void MinMaxinArr(int* arr, int count)
{
	_max[1] = arr[0];
	_min[1] = arr[0];
	for (int i = 1; i < count; i++)
	{
		if (_max[1] < arr[i])
		{
			_max[1] = arr[i];
			_max[0] = i;
		}
		if (_min[1] > arr[i])
		{
			_min[1] = arr[i];
			_min[0] = i;
		}
	}

	if (_max[0] != count)
	{
		for (int i = _max[0]; i < count; i++)
		{
			if (arr[i] < _max[1])
			{
				_max[0] = -1;
			}
		}
	}
}

void DifferenceArray(int* arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] = _max[1] - arr[i];
	}
}

bool ToUpper(int* differenc, int count)
{
	int temp;
	for (int i = 0; i < count; i++)
	{
		temp = differenc[i];
		for (int j = i; j < count; j++)
		{
			if (temp < differenc[j]) {

				return false;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		if (differenc[i] == 0)
		{
			continue;
		}
		if (differenc[i] < i + 1)
		{
			return false;
		}
	}

	return true;
}

void OperationCount(int* differenc, int count)
{
	int tempMinus;
	for (int i = count - 1; i >= 0; i--)
	{
		while (differenc[i] != 0)
		{
			for (int j = 0; j <= i; j++)
			{
				differenc[j] -= i + 1;
				operation++;
			}
		}
	}
}

int main()
{
	int count;
	string tempCin;
	cin >> count;
	if (count < 1)
	{
		cout << "-1"; return 0;
	}
	int* arr = new int[count];

	for (int i = 0; i < count; i++)
	{
		cin >> arr[i];
	}
	MinMaxinArr(arr, count);

	if ((_min[0] != 0) || (_max[0] == -1)) //Ќе на первом месте и максимальный не на последнем
	{
		cout << "-1"; return 0;
	}

	DifferenceArray(arr, count);
	if (!(ToUpper(arr, count)))
	{
		cout << "-1"; return 0;
	}

	OperationCount(arr, count);
	cout << operation;
	delete[] arr;
	return 0;
}