#include <iostream>
using namespace std;

int binarySearch(int a[], int size, int key){
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = (left + right)/2;
		if (a[mid] == key)
		{
			return mid;
		}
		else
			if (a[mid] < key)
				left = mid + 1;
			else 
				right = mid - 1;
	}
	return -1;
}

int main ()
{
	int a[1000];
	int n;
	cout <<"Nhap n: ";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout <<"Phan tu thu a[" << i << "]: ";
		cin >> a[i];
	}
	int key;
	cout <<"Nhap gia tri k: ";
	cin >> key;
	int i = binarySearch(a,n,key);
	cout << i;
	return 0;
}
