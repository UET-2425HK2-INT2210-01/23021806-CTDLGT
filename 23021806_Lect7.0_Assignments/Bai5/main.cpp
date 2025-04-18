#include <iostream>
using namespace std;

int demChuSo(int n) {
    if (n < 10) return 1;              // Nếu n chỉ có 1 chữ số thì trả về 1
    else return 1 + demChuSo(n / 10);  // Gọi đệ quy với n/10 và cộng thêm 1
}

int main() {
    int n;
    cin >> n;                        
    cout << demChuSo(n) << endl;      
    return 0;
}