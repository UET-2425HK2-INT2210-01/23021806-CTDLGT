#include <iostream> 

using namespace std;

// Hàm đệ quy tính GCD (Ước số chung lớn nhất) bằng thuật toán Euclid
int gcd(int x, int y) {
    if (y == 0)            // Điều kiện dừng: nếu y = 0 thì GCD là x
        return x;
    return gcd(y, x % y);  // Gọi đệ quy với (y, x mod y)
}

int main() {
    int x, y;
    cin >> x >> y;           
    cout << gcd(x, y) << endl; 
    return 0;
}
