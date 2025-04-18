#include <iostream>
using namespace std;

int Fibonacci(int n){
    if (n < 2){    //nếu n<2 thì trả về giá trị n 
        return n;
    } else return (Fibonacci(n - 1) + Fibonacci(n - 2)); //nếu n > 1 thì trả về hàm
}

int main()
{
    int n;
    cin >> n;
    cout << Fibonacci(n) << endl;
    return 0;
}