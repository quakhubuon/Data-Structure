#include <iostream>
using namespace std;

void nhapmang (int a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << "Nhap phan tu thu a[" << i << "]: ";
		cin >> a[i];
	}
}
void selection_sort (int a[], int n)
{
	int temp;
	int j;
	for (int i = 0;i < n-1;i++)
	{
		int min_index = i;
		for (int j = i;j < n;j++)
		{
			if (a[min_index] > a[j])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			temp = a[min_index];
			a[min_index]= a[i];
			a[i] = temp; 
		}
	}
}

void xuatmang (int a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << a[i] <<" ";
	}
}
int main ()
{
	int a[100];
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	nhapmang(a,n);
	selection_sort(a,n);
	xuatmang(a,n);
	return 0;
}
