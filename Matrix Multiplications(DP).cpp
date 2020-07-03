#include<iostream>
using namespace std;
int multiPlications(int* a, int i, int j, int** arr, int** n)
{
	if (i == j)
		return 0;
	if (arr[i][j] != 999999)
		return arr[i][j];
	int min = 99999999;
	for (int k = i; k < j; k++)
	{
		int temp = multiPlications(a, i, k, arr, n) + multiPlications(a, k + 1, j, arr, n) + a[i - 1] * a[k] * a[j];
		if (min > temp)
		{
			min = temp;
			n[i][j] = k;
		}
	}
	arr[i][j] = min;
	return min;
}
void print(int** n, int i, int j)
{
	if (i == j)
		cout << "A" << i;
	else
	{
		cout << "(";
		print(n, i, n[i][j]);
		print(n, n[i][j] + 1, j);
		cout << ")";
	}
}
int main()
{
	int a[6] = { 30, 35, 5, 10, 20, 25 };
	int **arr = new int*[6];
	int **n = new int*[6];
	for (int i = 0; i < 6; i++)
	{
		arr[i] = new int[6];
		n[i] = new int[6];
		for (int j = 0; j < 6; j++)
			arr[i][j] = 999999;
	}
	cout << multiPlications(a, 1, 5, arr, n) << endl;
	print(n, 1, 5);
	system("pause");
}