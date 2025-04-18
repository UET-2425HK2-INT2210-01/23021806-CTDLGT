#include <iostream>
using namespace std;

// Hàm hoán đổi 2 phần tử
void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

// Hàm đệ quy sinh hoán vị
void generatePermutations(string &s, int l, int r){
    if (l == r){         // Nếu chỉ còn 1 vị trí, in kết quả
        cout << s << endl;
        return;
    }

    for (int i = l; i <= r; i++){
        swap(s[l], s[i]);                          // Đổi chỗ ký tự tại l và i
        generatePermutations(s, l + 1, r);         // Gọi đệ quy với vị trí tiếp theo
        swap(s[l], s[i]);                          // Hoán đổi lại để quay lui (backtrack)
    }
}

int main(){
    int n;
    cin >> n;                    
    string s = "";               
    for (int i = 1; i <= n; i++){ 
        s += char('0' + i);      // Chuyển số thành ký tự, ví dụ: 1 → '1'
    }
    
    generatePermutations(s, 0, n - 1); 
    return 0;
}