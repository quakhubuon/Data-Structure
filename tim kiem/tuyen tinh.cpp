#include <iostream>
using namespace std;

int timkiem (int a[], int n, int k)
{
	for (int i = 0;i < n;i++)
	{
		if (a[i] == k)
			return i;
	}
	return -1;
}

int main ()
{
	int a[100];
	int n;
	cout <<"Nhap n: ";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout <<"Nhap phan tu a[" << i <<"]: ";
		cin >> a[i];
	}
	int k;
	cout <<"Nhap gia tri can tim: ";
	cin >> k;
	cout<<timkiem(a, n, k);
	return 0;
}

