#include <iostream>
using namespace std;

int daoNguoc(int n, int revNum = 0) {
    if (n == 0) return revNum;        // Khi n đã hết, trả về số đã đảo
    return daoNguoc(n / 10, revNum * 10 + n % 10);  // Cập nhật revNum và tiếp tục đệ quy
}

int main() {
    int n;
    cin >> n;                          
    cout << daoNguoc(n) << endl;      
    return 0;
}