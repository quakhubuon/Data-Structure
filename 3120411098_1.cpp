#include <iostream>
using namespace std;

//Tạo hàm xuất mảng để xuất mảng sau khi sắp xếp
void xuatmang(int a[], int n)
{
    for (int i = 0;i <n;i++)
   {
        cout << a[i] <<" ";
    }
}

//Tạo hàm đổi vị trí 2 phần tử
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int partition(int a[], int i, int j) //tạo 1 hàm có tên là partition trả về 1 biến m kiểu int vàtruyền vào 1 mảng a[] và 1 biến i lưu phần tử đầu của mảng và 1 biến j lưu phần tử cuối của mảng

{
    int pivot = a[i]; // chọn pivot = giá trị phần tử đầu của mảng dùng để làm phần tử chốt so sánh với giá trị các phần tử khác của mảng
    int m = i;    // gán biến m = vị trí phần tử đầu của mảng, mục đích của việc tạo biến m này dùng để chia mảng làm 2 nửa, biên trái là các phần tử có giá trị < giá trị pivot, bên phải các phần tử có giá trị lớn hơn
    for (int k = i + 1; k <= j; k++) // tạo 1 vòng lặp chạy từ vị trí i + 1 đến cuối mảng
    {
        if (a[k] < pivot) // tạo câu lệnh if với điều kiện giá trị phần tử k < pivot, mục đích để kiếm các phần tử < pivot chuyển về phía bên trái của mảng
        {
            m++; // tăng m lên 1 đơn vị
            swap(a[k], a[m]); // đổi giá trị 2 biến k và m 
        }
    }
    swap(a[i], a[m]); // đổi giá trị 2 biến i và m
    return m; // trả về vị trí cuối cùng m 
}
void quickSort(int a[], int i, int j) //tạo hàm có tên quickSort truyền vào 1 mảng a và biến i lưu phần tử đầu, j lưu phần tử cuối của mảng
{
    if (i < j) // điều kiện để mảng có ít nhất 2 phần tử
    {
        int pivot = partition(a, i, j); // gọi hàm partition và gán cho biến pivot để chia mảng
        quickSort(a, i, pivot - 1); // gọi đề quy để sắp xếp mảng bên trái
        quickSort(a, pivot + 1, j); // gọi đề quy để sắp xếp mảng bên phải
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
    quickSort(a,0,n-1);
    xuatmang(a,n);
    return 0;
}
