#include <iostream>
using namespace std;

int luythua(int n){
    if(n == 1){
        return 2;
    } else return 2*luythua(n - 1);
}

int main(){
    int n;
    cin >> n;
    cout << luythua(n) << endl;
    return 0;
}