#include <iostream>
using namespace std;

int binarySearch(int a[], int left, int right, int searchkey){
	int index;
	if (left > right)
		index = -1;
	
	else
	{
		int mid = (left + right)/2;
		if (searchkey == a[mid])
			index = mid;
		else
			if (searchkey < a[mid])
				index = binarySearch (a, left, mid - 1, searchkey);
			else
				index = binarySearch (a, mid + 1, right, searchkey);
	}
	return index;
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
	int searchkey;
	cout <<"Nhap gia tri k: ";
	cin >> searchkey;
	cout << binarySearch(a,0,n-1,searchkey);
	return 0;
}
