#include <iostream>   
#include <fstream>  

using namespace std;

const int MAX = 1000;    
int parent[MAX];         

// Cấu trúc lưu cạnh
struct Edge{
    int u, v, cost;       // u và v là hai đỉnh của cạnh, cost là trọng số
};

// Hàm tìm gốc của tập hợp chứa đỉnh u (thuật toán Disjoint Set - Find)
int find(int u){
    while (u != parent[u])    // đi lên đến khi gặp gốc
        u = parent[u];
    return u;
}

// Hàm hợp nhất hai tập hợp chứa u và v (Union)
void unite(int u, int v){
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;    // gán cha của rootU là rootV
}

// Hàm sắp xếp các cạnh theo trọng số tăng dần (Bubble Sort cho đơn giản)
void sortEdges(Edge edges[], int m){
    for (int i = 0; i < m - 1; i++){
        for (int j = 0; j < m - i - 1; j++){
            if (edges[j].cost > edges[j + 1].cost){
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main(){
    ifstream fin("connection.txt");  
    ofstream fout("connection.out"); 

    int n, m;         // n là số máy tính, m là số kết nối
    fin >> n >> m;    // đọc n và m từ file

    Edge edges[MAX];  // mảng lưu các cạnh

    for (int i = 0; i < m; i++){
        fin >> edges[i].u >> edges[i].v >> edges[i].cost; // đọc thông tin từng cạnh
        edges[i].u--;  // chuyển về chỉ số 0-based
        edges[i].v--;
    }

    // Khởi tạo tập hợp rời rạc cho mỗi đỉnh
    for (int i = 0; i < n; i++){
        parent[i] = i;
    }

    sortEdges(edges, m);  // sắp xếp các cạnh theo trọng số tăng dần

    int totalCost = 0;    // biến lưu tổng chi phí của cây khung nhỏ nhất
    int edgeCount = 0;    // đếm số cạnh đã chọn vào cây

    for (int i = 0; i < m && edgeCount < n - 1; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int cost = edges[i].cost;

        if (find(u) != find(v)){     // nếu u và v chưa được kết nối
            unite(u, v);             // hợp nhất hai tập hợp
            totalCost += cost;       // cộng chi phí
            fout << u + 1 << " " << v + 1 << " " << cost << endl;  // ghi cạnh vào file (1-based)
            edgeCount++;             // tăng số cạnh trong cây khung
        }
    }

    // Ghi tổng chi phí vào dòng đầu
    fout.seekp(0, ios::beg);         // quay về đầu file
    fout << totalCost << endl;

    fin.close();    
    fout.close();  

    return 0;
}
