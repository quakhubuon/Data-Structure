#include <iostream>
using namespace std;



void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}

void radixSort(int a[], int n)
{
	int b[n], m = a[0], exp = 1;

	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

	while (m / exp > 0)
	{
		int count[10] = {0};
		for (int i = 0; i < n; i++)
			count[a[i] / exp % 10]++;
			
		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];
			
		for (int i = n - 1; i >= 0; i--)
			b[--count[a[i] / exp % 10]] = a[i];
		//Output
		for (int i = 0; i < n; i++)
			a[i] = b[i];
			
		exp *= 10;
	}
}

int main()
{
	int a[100];
	int  n;
	cout <<"Nhap n: ";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout<<"Nhap phan tu thu a[" << i << "]: ";
		cin >> a[i];
	}
	radixSort(a, n);	
	cout << endl << "After sort : ";
	printArray(a, n);

	return 0;
}
