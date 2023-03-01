#include <iostream>
using namespace std;

void nhapmang (int a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout <<"Nhap phan tu thu a[" <<i<< "]: ";
		cin >> a[i];
	}
}

void insertion_sort (int a[], int n)
{
	int temp;
	int j;
	for (int i = 1;i < n;i++)
	{
		j = i-1;
		temp = a[i];
		
	while (j>=0 && temp<a[j])
	{
		a[j+1] = a[j];
		j--;
	}
	a[j+1] = temp;
	}
}
void xuatmang (int a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << a[i] <<" ";
	}
}
int main()
{
	int a[100];
	int n;
	cout <<"Nhap so phan tu cua mang: ";
	cin >> n;
	nhapmang(a,n);
	insertion_sort(a,n);
	xuatmang(a,n);
	return 0;
}
