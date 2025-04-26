#include <iostream>
using namespace std;

// Hàm trộn 2 mảng con đã được sắp xếp
void merge(int a[], int l, int m, int r){
    int n1 = m - l + 1; // Số phần tử mảng trái
    int n2 = r - m;     // Số phần tử mảng phải

    int L[n1], R[n2]; // Tạo mảng tạm

    for (int i = 0; i < n1; i++) L[i] = a[l + i]; // Copy dữ liệu vào mảng trái
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i]; // Copy dữ liệu vào mảng phải

    int i = 0, j = 0, k = l; 

    // Trộn mảng trái và phải
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    // Sao chép phần còn lại nếu có
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

// Hàm merge sort chính
void mergeSort(int a[], int l, int r){
    if (l < r){
        int m = (l + r) / 2; 
        mergeSort(a, l, m);  // Gọi đệ quy mảng trái
        mergeSort(a, m + 1, r); // Gọi đệ quy mảng phải
        merge(a, l, m, r); // Trộn 2 mảng con
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
