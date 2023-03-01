#include <iostream>
using namespace std;
void nhapmang (int a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout <<" Nhap phan tu a[" << i << "]: ";
		cin >> a[i];
	}
}
void bubblesort (int a[], int n)
{
	int temp;
	for (int i = 0;i < n-1;i++ )
	{
		for (int j = n-2; j >= i;j--)
		{
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
void xuatmang (int a[],  int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << a[i] << " ";
	}
}
int main()
{
	int a[100];
	int n;
	cout<<"Nhap vao so phan tu: ";
	cin >> n;
	nhapmang(a,n);
	bubblesort(a,n);
	cout<<"Xuat mang: ";
	xuatmang(a,n);
	return 0;
}
