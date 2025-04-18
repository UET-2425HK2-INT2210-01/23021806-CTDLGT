#include<iostream>
using namespace std;

int sum(int n){
    if (n == 1) {   // Trường hợp cơ sở: nếu n = 1 thì trả về 1
        return 1;
    } else return n + sum(n - 1); // Gọi lại hàm với n-1 và cộng thêm n
}

int main(){
    int n;
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}