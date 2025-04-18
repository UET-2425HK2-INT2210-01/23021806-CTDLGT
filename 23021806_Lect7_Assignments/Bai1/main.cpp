#include <iostream>  
#include <fstream>    

using namespace std;

// Hàm hoán đổi 2 số thực
void swap(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}

// Hàm sắp xếp nổi bọt (bubble sort)
void bubbleSort(double arr[], int n){
    for (int i = 0; i < n - 1; ++i){           
        for (int j = 0; j < n - i - 1; ++j){    // So sánh từng cặp liên tiếp
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);       // Đổi chỗ nếu cần
            }
        }
    }
}

int main(){
    ifstream input("numbers.txt");     
    ofstream output("numbers.sorted");  

    double arr[1000];  // Mảng lưu tạm
    int count = 0;     

    while (input >> arr[count]){ // Đọc từng số cho đến khi hết file
        count++;
    }

    bubbleSort(arr, count);  // Gọi hàm sắp xếp

    for (int i = 0; i < count; ++i){
        output << arr[i];           
        if (i != count - 1)
            output << " ";          // Thêm khoảng trắng giữa các số (trừ số cuối)
    }

    input.close();   
    output.close();  
    return 0;
}
