#include <iostream>
using namespace std;

int timkiemlinhcanh (int a[], int n, int k)
{
	int i=0;
	a[n]=k;
	while (a[i]!=k)
		i++;
	return i;
}

int main ()
{
	int a[100];
	int n;
	cout <<"Nhap n: ";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout <<"Phan tu thu a[" << i << "]: ";
		cin >> a[i];
	}
	
	int k;
	cout <<"Gia tri can tim la: ";
	cin >> k;
	int i = timkiemlinhcanh(a,n,k);
	if (i == n)
	{
		cout <<"Khong tim thay phan tu";
	}
	else
	{
		cout <<"Phan tu thu " <<i;
	}
	return 0;
}
