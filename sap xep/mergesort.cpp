#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int nhapmang (int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap a[" << i << "] : ";
		cin >> a[i];
	}
}

void merge(int a[] , int i, int mid, int j) {


	int temp[ j - i + 1]; 
	int left = i, right = mid + 1, it = 0;

	while (left <= mid && right <= j) { 
		if (a[left] <= a[right])
			temp[it++] = a[left++];
		else
			temp[it++] = a[right++];
	}

	while (left <= mid) temp[it++] = a[left++];
	while (right <= j)  temp[it++] = a[right++];
	for (int k = 0; k < j - i + 1  ;k++)
		a[i + k] = temp[k];
}

void mergeSort(int a[] , int i, int j) {
	if (i < j) {
		int mid = (i+j) / 2;
		mergeSort(a, i, mid);
		mergeSort(a, mid + 1, j);
		merge(a, i, mid, j);
	}
}

void printarray(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
}

int main()
{
	int a[1000];
	int n;
	cout << "Nhap phan tu : " << endl;
	cin >> n;
	nhapmang(a, n);
	mergeSort(a, 0, n - 1);
	printarray(a, n);
	return 0;
}
