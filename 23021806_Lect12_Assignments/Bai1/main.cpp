#include <iostream>  
#include <fstream>  

using namespace std;

const int MAX = 100;

int adj[MAX][MAX];    // ma trận kề: adj[u][v] = 1 nếu có cạnh từ u đến v
bool visited[MAX];    // đánh dấu đỉnh đã thăm trong DFS
int topoStack[MAX];   // ngăn xếp lưu thứ tự topo
int top = -1;         // đỉnh của ngăn xếp

int n, m;             // số lượng công việc (đỉnh) và ràng buộc (cạnh)

// Hàm DFS từ đỉnh u
void dfs(int u){
    visited[u] = true;                   // đánh dấu đã thăm u
    for (int v = 0; v < n; v++){
        if (adj[u][v] && !visited[v])   // nếu có cạnh từ u đến v và v chưa được thăm
            dfs(v);                     // đệ quy DFS từ v
    }
    topoStack[++top] = u + 1;           // đẩy u vào stack sau khi xử lý xong (chuyển lại chỉ số 1-based)
}

int main(){
    ifstream fin("jobs.txt");    
    ofstream fout("jobs.out");  

    fin >> n >> m;               // đọc số đỉnh và số cạnh

    // Khởi tạo ma trận kề
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Đọc m cạnh u -> v
    for (int i = 0; i < m; i++){
        int u, v;
        fin >> u >> v;
        adj[u - 1][v - 1] = 1;   // chuyển sang chỉ số 0-based
    }

    // Khởi tạo mảng visited
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // Gọi DFS cho mỗi đỉnh chưa thăm
    for (int i = 0; i < n; i++){
        if (!visited[i])
            dfs(i);
    }

    // Xuất kết quả từ stack
    while (top >= 0){
        fout << topoStack[top--] << " ";
    }
    fout << "\n";

    fin.close();
    fout.close();

    return 0;
}
