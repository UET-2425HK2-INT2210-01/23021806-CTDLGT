#include <iostream> 
using namespace std;

const int MAX = 100;
int graph[MAX][MAX]; // Ma trận kề để biểu diễn đồ thị
bool visited[MAX];   // Mảng đánh dấu các đỉnh đã được thăm
int n, m;           

// Hàm duyệt DFS từ một đỉnh cho trước
void dfs(int node){
    visited[node] = true; // Đánh dấu đỉnh hiện tại là đã thăm
    for (int i = 1; i <= n; ++i){ // Duyệt qua tất cả các đỉnh còn lại
        if (graph[node][i] && !visited[i]){ // Nếu có cạnh và đỉnh i chưa được thăm
            dfs(i); // Gọi đệ quy tiếp tục DFS
        }
    }
}

int main(){
    cin >> n >> m;

    // Nhập m cạnh của đồ thị
    for (int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y; // Nhập cạnh nối đỉnh x và y
        graph[x][y] = 1; // Đánh dấu có cạnh giữa x và y
        graph[y][x] = 1; // Vì đồ thị vô hướng nên cần đánh dấu cả chiều ngược lại
    }

    int connected_components = 0; // Biến đếm số thành phần liên thông

    // Duyệt qua tất cả các đỉnh
    for (int i = 1; i <= n; ++i){
        if (!visited[i]){ // Nếu đỉnh chưa được thăm
            ++connected_components; // Tăng số thành phần liên thông
            dfs(i); // Bắt đầu DFS từ đỉnh đó
        }
    } 

    cout << connected_components << endl; // In ra số thành phần liên thông
    return 0; 
}