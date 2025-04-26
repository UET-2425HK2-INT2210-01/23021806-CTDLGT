#include <iostream>
using namespace std;

// Hàm phân hoạch theo Hoare
int partitionHoare(int a[], int l, int r){
    int pivot = a[l]; // Pivot là phần tử đầu
    int i = l - 1, j = r + 1; // i đi từ trái, j đi từ phải

    while (true){
        do{ i++; } while (a[i] < pivot); // Tìm phần tử >= pivot bên trái
        do{ j--; } while (a[j] > pivot); // Tìm phần tử <= pivot bên phải

        if (i >= j) return j; // Nếu i >= j, trả về vị trí phân chia

        int temp = a[i]; a[i] = a[j]; a[j] = temp; // Hoán đổi a[i] và a[j]
    }
}

// Hàm quick sort
void quickSortHoare(int a[], int l, int r){
    if (l < r){
        int pi = partitionHoare(a, l, r); // Chia mảng
        quickSortHoare(a, l, pi); // Đệ quy mảng bên trái
        quickSortHoare(a, pi + 1, r); // Đệ quy mảng bên phải
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    quickSortHoare(a, 0, n - 1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
