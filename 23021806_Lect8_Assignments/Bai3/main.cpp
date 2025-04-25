#include <iostream>
using namespace std;

int max(int a, int b){ return (a > b) ? a : b; }

// Hàm giải bài toán cái túi bằng quy hoạch động
int knapsack(int weights[], int values[], int n, int X){
    int dp[101][101]; // dp[i][w]: max giá trị với i đồ vật và sức chứa w

    for (int i = 0; i <= n; i++){
        for (int w = 0; w <= X; w++){
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][X]; // kết quả cuối cùng
}

int main(){
    int n, X;
    cin >> n >> X;
    int weights[100], values[100];
    for (int i = 0; i < n; i++){
        cin >> weights[i] >> values[i]; // Nhập trọng lượng và giá trị
    }

    cout << knapsack(weights, values, n, X) << endl;
    return 0;
}
