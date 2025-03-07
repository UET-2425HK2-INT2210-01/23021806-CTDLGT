#include<iostream>
using namespace std;
/*cach 1*/
void mun(int n){
        int tich = 1;
        for(int i = 0; i < n; i++){
            tich = tich * 2;
        }
        cout << "2^n = " << tich << endl;
    }
/* Do phuc tap thuat toan la O(n)*/

/*Cach 2*/
double bitleft(int n){
    double result;
    if(n >= 0){
        result = 1 << n;
    } else{
        result = 1 << -(n);
        result = 1/result;
    }
    return result;
}
/* Do phuc tap thuat toan la O(1)*/

int main(){
    int n;
    cin >> n;
    mun(n);
    bitleft(n);
}