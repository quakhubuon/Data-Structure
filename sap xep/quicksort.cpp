#include <iostream>
using namespace std;

void xuatmang(int a[], int n)
{
	for (int i = 0;i <n;i++)
	{
		cout << a[i] << " ";
	}
}

void quicksort (int a[], int left, int right)
{
	int l = left;
	int r = right;
	int p = a[(left + right)/2];
	int temp;
	while (l < r)
	{
		while (a[l] < p)
			l++;
		while (a[r] > p)
			r--;
		if (l<=r)
		{
			temp = a[l];
			a[l] = a[r];
			a[r] = temp;
			l++;
			r--;
		}
	}
	
	if (left < r)
	{
		quicksort (a,left,r);
	}
	
	if (right > l)
	{
		quicksort (a,l,right);
	}
}

int main ()
{
	int a[100];
	int n;
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout << "Phan tu thu a["<<i<<"]: ";
		cin >> a[i];
	}
	quicksort(a,0,n-1);
	xuatmang(a,n);
	return 0;
}
