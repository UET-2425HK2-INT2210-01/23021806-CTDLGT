#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int A[n];
    int dem = 0;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if (A[i] == A[j]){
                dem ++;
            }
        }
    }
    cout << dem;
}