#include <iostream> 
using namespace std;

// Hàm hoán đổi 2 số thực
void swap(double &a, double &b){
    double temp = a; 
    a = b;           
    b = temp;        
}

// Hàm phân hoạch mảng cho quicksort
int partition(double arr[], int low, int high){
    double pivot = arr[high]; 
    int i = low - 1;          

    for (int j = low; j < high; j++){ 
        if (arr[j] < pivot){          // Nếu phần tử nhỏ hơn pivot
            i++;                       // Tăng chỉ số vùng nhỏ
            swap(arr[i], arr[j]);     // Đưa phần tử nhỏ về đầu
        }
    }
    swap(arr[i + 1], arr[high]); // Đưa pivot về đúng vị trí
    return i + 1;                // Trả về chỉ số pivot
}

// Hàm quicksort đệ quy
void quickSort(double arr[], int low, int high){
    if (low < high){                             // Nếu vùng cần sắp xếp hợp lệ
        int pi = partition(arr, low, high);       // Tìm vị trí phân hoạch
        quickSort(arr, low, pi - 1);              // Sắp xếp nửa bên trái
        quickSort(arr, pi + 1, high);             // Sắp xếp nửa bên phải
    }
}

int main(){
    int n;
    cin >> n;                     

    double arr[1000];             
    for (int i = 0; i < n; i++){
        cin >> arr[i];            
    }

    quickSort(arr, 0, n - 1);     

    for (int i = 0; i < n; i++){
        cout << arr[i];        
        if (i != n - 1) cout << " "; 
    }
    cout << endl;                
    return 0;                     
}
