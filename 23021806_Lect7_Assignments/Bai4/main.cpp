#include <iostream>
using namespace std;

// Hàm đệ quy để tạo và in tất cả các chuỗi nhị phân độ dài n
void generateBinary(int n, string current){
    if (current.length() == n){  // Nếu chuỗi đạt độ dài n
        cout << current << endl;  // In chuỗi đó ra
        return;                   // Kết thúc nhánh đệ quy
    }
    generateBinary(n, current + "0"); // Thêm '0' và gọi đệ quy
    generateBinary(n, current + "1"); // Thêm '1' và gọi đệ quy
}

int main(){
    int n;
    cin >> n;               
    generateBinary(n, "");  
    return 0;
}
