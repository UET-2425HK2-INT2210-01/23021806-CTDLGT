#include <iostream>

using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct Node{
    int Data; // Giá trị của nút
    int children[100]; // Mảng chứa danh sách các con của nút
    int childCount; // Số lượng con của nút
};

Node nodes[100]; // Mảng chứa tất cả các nút
bool hasParent[100]; // Mảng đánh dấu nút nào có cha

// Bước 1: Tìm gốc của cây
Node* findRoot(int N){
    for (int i = 1; i <= N; i++){
        if (!hasParent[i]){ // Nếu nút không có cha, đó là gốc cây
            return &nodes[i];
        }
    }
    return nullptr; // Trả về nullptr nếu không tìm thấy gốc
}

// Bước 2: Tính chiều cao của cây
int treeHeight(Node* root){
    if (!root) return 0; // Nếu nút gốc không tồn tại, trả về 0
    
    int maxHeight = 0; // Biến lưu chiều cao lớn nhất
    for (int i = 0; i < root->childCount; i++){
        int height = treeHeight(&nodes[root->children[i]]); // Đệ quy tính chiều cao cây con
        if (height > maxHeight){
            maxHeight = height;
        }
    }
    return maxHeight + 1; // Chiều cao cây = chiều cao lớn nhất của cây con + 1
}

// Bước 3: Duyệt cây theo thứ tự trước (Preorder)
void preorder(Node* root){
    if (!root) return;
    cout << root->Data << " "; // In giá trị của nút hiện tại
    for (int i = 0; i < root->childCount; i++){
        preorder(&nodes[root->children[i]]); // Đệ quy duyệt cây con
    }
}

// Bước 4: Duyệt cây theo thứ tự sau (Postorder)
void postorder(Node* root){
    if (!root) return;
    for (int i = 0; i < root->childCount; i++){
        postorder(&nodes[root->children[i]]); // Đệ quy duyệt cây con trước
    }
    cout << root->Data << " "; // In giá trị của nút hiện tại
}

// Bước 5: Kiểm tra cây có phải cây nhị phân không
bool isBinaryTree(int N){
    for (int i = 1; i <= N; i++){
        if (nodes[i].childCount > 2){ // Nếu có nút có nhiều hơn 2 con, không phải cây nhị phân
            return false;
        }
    }
    return true;
}

// Bước 6: Duyệt cây theo thứ tự giữa (Inorder - chỉ áp dụng cho cây nhị phân)
void inorder(Node* root){
    if (!root) return;
    
    if (root->childCount > 0){
        inorder(&nodes[root->children[0]]); // Duyệt cây con trái
    }
    
    cout << root->Data << " "; // In giá trị của nút hiện tại
    
    if (root->childCount > 1){
        inorder(&nodes[root->children[1]]); // Duyệt cây con phải
    }
}

int main(){
    int N, M;
    cin >> N >> M; // Nhập số lượng nút và số lượng cạnh

    //Khởi tạo các nút
    for (int i = 1; i <= N; i++){
        nodes[i].Data = i;
        nodes[i].childCount = 0;
        hasParent[i] = false;
    }

    //Nhập danh sách các cạnh
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        nodes[u].children[nodes[u].childCount++] = v; // Thêm v vào danh sách con của u
        hasParent[v] = true; // Đánh dấu v có cha
    }

    //Tìm gốc của cây
    Node* root = findRoot(N);
    if (!root){
        cout << "INVALID TREE" << endl;
        return 0;
    }

    //Xuất chiều cao của cây
    cout << treeHeight(root) << endl;

    //Duyệt cây theo Preorder
    preorder(root);
    cout << endl;

    //Duyệt cây theo Postorder
    postorder(root);
    cout << endl;

    //Nếu là cây nhị phân, duyệt theo Inorder, ngược lại thông báo không phải cây nhị phân
    if (isBinaryTree(N)){
        inorder(root);
        cout << endl;
    } else{
        cout << "NOT BINARY TREE" << endl;
    }

    return 0;
}
