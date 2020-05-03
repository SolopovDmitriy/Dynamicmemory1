#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int index, int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int* &arr, int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Input number of elements: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;


	int value;
	cout << "Input value: "; cin >> value;
	arr = push_back(arr, n, value);
	cout << "�������� �������� � ����� �������: " << value << endl;
	cout << endl;
	Print(arr, n);
	cout << endl;

	cout << "Input value: "; cin >> value;
	arr = push_front(arr, n, value);
	cout << "�������� �������� � ������ �������: " << value << endl;
	cout << endl;
	Print(arr, n);
	cout << endl;

	int index;
	cout << "Input index: "; cin >> index;
	cout << "Input value: "; cin >> value;
	arr = insert(arr, n, index, value);
	cout << "�������� ��������: " << value << " �� �������: " << index << endl;
	cout << endl;
	Print(arr, n);
	cout << endl;

	arr = pop_back(arr, n);
	cout << "������� �������� � ����� �������:" << endl;
	cout << endl;
	Print(arr, n);
	cout << endl;

	arr = pop_front(arr, n);
	cout << "������� �������� � ������ �������:" << endl;
	cout << endl;
	Print(arr, n);
	cout << endl;

	cout << "Input index delete: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);


	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{

	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}

int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int* insert(int arr[], int& n, int index, int value)
{
	if (index > n)return arr;
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	return arr;
}

int* erase(int* &arr, int &n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		if (i >= index)
		{
			buffer[i] = arr[i + 1];
		}
		else
		{
			buffer[i] = arr[i];
		}
	}
	n--;
	delete[]arr;
	arr = buffer;

	return arr;
}