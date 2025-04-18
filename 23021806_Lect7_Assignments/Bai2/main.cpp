#include <iostream>   
#include <fstream>   

using namespace std;

// Hàm tính tổng hình chữ nhật từ (r1,c1) đến (r2,c2)
int calcSum(int matrix[100][100], int r1, int c1, int r2, int c2){
    int sum = 0;
    for (int i = r1; i <= r2; ++i){
        for (int j = c1; j <= c2; ++j){
            sum += matrix[i][j];  // Cộng tất cả phần tử trong hình chữ nhật
        }
    }
    return sum;
}

int main(){
    ifstream input("matrix.txt");     
    ofstream output("matrix.out");  

    int m, n;
    input >> m >> n;   

    int matrix[100][100];  

    for (int i = 0; i < m; ++i)     
        for (int j = 0; j < n; ++j)
            input >> matrix[i][j];

    int maxSum = matrix[0][0];  
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0; 

    for (int i1 = 0; i1 < m; ++i1){     
        for (int j1 = 0; j1 < n; ++j1){   
            for (int i2 = i1; i2 < m; ++i2){   
                for (int j2 = j1; j2 < n; ++j2){
                    int sum = calcSum(matrix, i1, j1, i2, j2);  // Tính tổng vùng
                    if (sum > maxSum){  // Nếu lớn hơn tổng hiện tại thì cập nhật
                        maxSum = sum;
                        r1 = i1; c1 = j1; r2 = i2; c2 = j2;
                    }
                }
            }
        }
    }
    
    output << (r1+1) << " " << (c1+1) << " " << (r2+1) << " " << (c2+1) << " " << maxSum;

    input.close();   
    output.close();  

    return 0;
}

