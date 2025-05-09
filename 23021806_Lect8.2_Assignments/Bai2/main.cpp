#include <iostream>
using namespace std;

// Hàm đệ quy kiểm tra có tồn tại tập con có tổng bằng target
bool subsetSum(int arr[], int n, int target){
    if (target == 0) return true;          // Tổng = 0 => tồn tại
    if (n == 0) return false;              // Không còn phần tử để xét
    if (arr[n-1] > target)                 // Bỏ qua nếu phần tử lớn hơn target
        return subsetSum(arr, n - 1, target);
    return subsetSum(arr, n - 1, target) || subsetSum(arr, n - 1, target - arr[n - 1]);
}

int main(){
    int n, X;
    cin >> n >> X;                         // Nhập n và X
    int arr[100];                          // Mảng chứa tuổi sinh viên
    for (int i = 0; i < n; i++){
        cin >> arr[i];                     // Nhập từng tuổi
    }

    if (subsetSum(arr, n, X)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
