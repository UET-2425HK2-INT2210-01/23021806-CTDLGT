#include <iostream>
using namespace std;

// Hàm phân hoạch theo Lomuto
int partitionLomuto(int a[], int l, int r){
    int pivot = a[r]; // Pivot chọn phần tử cuối
    int i = l - 1;    // Vị trí của phần tử nhỏ hơn pivot

    for (int j = l; j < r; j++){
        if (a[j] <= pivot){
            i++;
            int temp = a[i]; a[i] = a[j]; a[j] = temp; // Hoán đổi a[i] và a[j]
        }
    }

    int temp = a[i + 1]; a[i + 1] = a[r]; a[r] = temp; // Đưa pivot vào đúng chỗ
    return i + 1; // Trả về chỉ số pivot mới
}

// Hàm quick sort
void quickSortLomuto(int a[], int l, int r){
    if (l < r){
        int pi = partitionLomuto(a, l, r); // Chia mảng
        quickSortLomuto(a, l, pi - 1); // Đệ quy bên trái
        quickSortLomuto(a, pi + 1, r); // Đệ quy bên phải
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    quickSortLomuto(a, 0, n - 1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
