#include <iostream>  
#include <fstream> 

using namespace std;

const int MAX = 100; 
const int INF = 1e9; 

int n, m, s, e;            // n: số thành phố, m: số đường, s: điểm bắt đầu, e: điểm kết thúc
int D[MAX][MAX];           // Ma trận lưu Dirty giữa các thành phố
int dist[MAX];             // Mảng lưu Dirty ngắn nhất từ s đến các đỉnh
int parent[MAX];           // Mảng lưu cha để truy vết đường đi

// Hàm in đường đi từ điểm bắt đầu đến điểm u (dùng đệ quy)
void printPath(int u, ofstream &fout){
    if (u == -1) return;                 // Nếu không có cha thì dừng
    printPath(parent[u], fout);         // Gọi đệ quy in cha trước
    fout << u + 1 << " ";               // In đỉnh hiện tại (cộng 1 vì lưu từ 0)
}

int main(){
    ifstream fin("dirty.txt");      
    ofstream fout("dirty.out");       

    fin >> n >> m >> s >> e;            // Đọc số thành phố, số đường, điểm bắt đầu, điểm kết thúc
    s--; e--;                           // Giảm 1 để dùng chỉ số mảng từ 0

    // Khởi tạo ma trận Dirty D ban đầu
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) D[i][j] = 0;    // Dirty từ i đến chính nó là 0
            else D[i][j] = INF;         // Các đỉnh còn lại khởi tạo là vô cực
        }
    }

    // Nhập thông tin các đường đi và Dirty
    for (int i = 0; i < m; i++){
        int u, v, d;
        fin >> u >> v >> d;             // Đọc u: từ thành phố, v: đến thành phố, d: Dirty
        u--; v--;                       // Giảm 1 để dùng chỉ số từ 0
        D[u][v] = d;                    // Gán Dirty vào ma trận
    }

    // a: Tìm đường đi ngắn nhất từ s đến e bằng Bellman-Ford 
    for (int i = 0; i < n; i++){
        dist[i] = INF;                  // Khởi tạo Dirty vô cực
        parent[i] = -1;                 // Khởi tạo không có cha
    }
    dist[s] = 0;                        // Dirty từ s đến chính nó là 0

    // Lặp n-1 lần để relax các cạnh
    for (int k = 0; k < n - 1; k++){
        for (int u = 0; u < n; u++){
            for (int v = 0; v < n; v++){
                if (D[u][v] != INF && dist[u] + D[u][v] < dist[v]){
                    dist[v] = dist[u] + D[u][v]; // Cập nhật nếu tìm được Dirty nhỏ hơn
                    parent[v] = u;               // Ghi nhận cha để truy vết đường đi
                }
            }
        }
    }

    // In tổng Dirty từ s đến e
    if (dist[e] == INF) fout << "INF\n";          // Không có đường đi
    else fout << dist[e] << "\n";                 // Ghi Dirty nhỏ nhất

    // In đường đi từ s đến e
    if (dist[e] == INF) fout << "No path\n";      // Không có đường đi
    else{
        printPath(e, fout);                       // In đường đi
        fout << "\n";
    }

    // b: Dùng Floyd-Warshall tìm đường ngắn nhất mọi cặp đỉnh
    for (int k = 0; k < n; k++){                 // Duyệt qua từng đỉnh trung gian
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (D[i][k] != INF && D[k][j] != INF && D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];  // Cập nhật nếu có đường ngắn hơn
                }
            }
        }
    }

    // In ma trận khoảng cách ngắn nhất
    for (int i = 0; i < n; i++){                 // Duyệt từng hàng
        for (int j = 0; j < n; j++){             // Duyệt từng cột
            if (D[i][j] == INF) fout << "INF ";   // Nếu không có đường đi
            else fout << D[i][j] << " ";          // In Dirty
        }
        fout << "\n";                             
    }

    fin.close();
    fout.close();

    return 0; 
}
