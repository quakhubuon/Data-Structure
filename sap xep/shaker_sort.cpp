#include<iostream>
using namespace std;
void hoanvi(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void shakersort(int a[],int n)
{
    int trai=0;
	int phai=n-1;
	int k=0;
	while(trai<phai)
	{
		for(int i=trai;i<phai;i++)
			if(a[i]>a[i+1])
			{
				swap(a[i],a[i+1]);
				k=i;
			}
		phai=k;
		for (int i=phai;i>trai;i--)
			if(a[i]<a[i-1])
			{
				hoanvi(a[i],a[i-1]);
				k=i;
			}
		trai=k;
	}
}
void xuat(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<"  ";
}
int main()
{
    int n;
    cout<<"nhap n: ";cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    shakersort(a,n);
    xuat(a,n);
    return 0;
}
