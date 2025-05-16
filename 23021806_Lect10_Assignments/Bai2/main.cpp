#include <iostream>
using namespace std;

const int MAX = 100;         // Số đỉnh tối đa
int graph[MAX][MAX];         // Ma trận kề lưu cạnh có hướng
bool visited[MAX];           // Đánh dấu các đỉnh đã được thăm
int distance[MAX];           // Lưu khoảng cách (số cạnh) từ X đến từng đỉnh
int queue[MAX];              // Hàng đợi tự cài đặt cho BFS
int front = 0, rear = 0;     // Con trỏ đầu và cuối của hàng đợi

int main(){
    int n, m, X, Y;
    cin >> n >> m >> X >> Y; // Nhập số đỉnh, số cạnh, và hai đỉnh X, Y

    // Nhập m cạnh có hướng và cập nhật vào ma trận kề
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;       // Cạnh từ u đến v (đồ thị có hướng)
        graph[u][v] = 1;     // Đánh dấu có cạnh u -> v
    }

    // Bắt đầu BFS từ đỉnh X
    visited[X] = true;       // Đánh dấu đỉnh X là đã thăm
    distance[X] = 0;         // Khoảng cách từ X đến X là 0
    queue[rear++] = X;       // Đưa X vào hàng đợi

    // Vòng lặp BFS
    while (front < rear){
        int current = queue[front++];  // Lấy đỉnh đầu hàng đợi

        // Duyệt qua tất cả các đỉnh kề với current
        for (int i = 1; i <= n; ++i){
            if (graph[current][i] && !visited[i]){
                visited[i] = true;                     // Đánh dấu đã thăm
                distance[i] = distance[current] + 1;   // Cập nhật khoảng cách
                queue[rear++] = i;                     // Thêm vào hàng đợi
            }
        }
    }

    // In ra kết quả
    if (visited[Y]){
        cout << distance[Y] << endl; // In số cạnh ngắn nhất từ X đến Y
    } else{
        cout << -1 << endl; // Nếu không có đường đi, in -1
    }

    return 0;
}