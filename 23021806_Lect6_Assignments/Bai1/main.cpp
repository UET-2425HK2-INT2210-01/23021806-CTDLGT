#include <iostream>
using namespace std;

struct Node{
    int data; // Giá trị của node
    Node* left; // Con trỏ đến node con bên trái
    Node* right; // Con trỏ đến node con bên phải
    Node(int val) : data(val), left(nullptr), right(nullptr){} // Constructor khởi tạo node mới
};

class BST{
public:
    Node* root; // Gốc của cây BST
    BST() : root(nullptr){} // Constructor khởi tạo cây rỗng

    Node* insert(Node* node, int val){
        if (!node) return new Node(val); // Nếu node rỗng, tạo node mới
        if (val < node->data) node->left = insert(node->left, val); // Nếu giá trị nhỏ hơn node hiện tại, chèn vào bên trái
        else node->right = insert(node->right, val); // Nếu giá trị lớn hơn, chèn vào bên phải
        return node;
    }
    
    void insert(int val){ root = insert(root, val); } // Hàm chèn một giá trị vào cây

    Node* findMin(Node* node){
        while (node && node->left) node = node->left; // Tìm node nhỏ nhất trong cây con phải
        return node; 
    }
    
    Node* remove(Node* node, int val){
        if (!node) return node; // Nếu cây rỗng, trả về nullptr
        if (val < node->data) node->left = remove(node->left, val); // Nếu giá trị nhỏ hơn, tiếp tục tìm trong cây con trái
        else if (val > node->data) node->right = remove(node->right, val); // Nếu lớn hơn, tìm trong cây con phải
        else{
            if (!node->left){ // Nếu node chỉ có con phải hoặc không có con
                Node* temp = node->right; 
                delete node; 
                return temp; 
            } else if (!node->right){ // Nếu node chỉ có con trái
                Node* temp = node->left; 
                delete node; 
                return temp; 
            }
            Node* temp = findMin(node->right); // Tìm node nhỏ nhất ở cây con phải
            node->data = temp->data; 
            node->right = remove(node->right, temp->data);
        }
        return node;
    }
    
    void remove(int val){ root = remove(root, val); } // Hàm xóa một giá trị khỏi cây

    void inorder(Node* node){
        if (!node) return; // Nếu node rỗng, dừng lại
        inorder(node->left); 
        cout << node->data << " "; 
        inorder(node->right);
    }
    
    void display(){ inorder(root); cout << endl; } // Hàm hiển thị cây theo thứ tự trung tố
};

int main(){
    BST tree;
    int n;
    cout << "Nhập số lượng phần tử: ";
    cin >> n; 
    
    int* values = new int[n]; // Khởi tạo mảng động
    cout << "Nhập các phần tử: ";
    for (int i = 0; i < n; i++){
        cin >> values[i]; 
        tree.insert(values[i]); 
    }
    
    cout << "BST sau khi chèn: ";
    tree.display();
    
    delete[] values; // Giải phóng bộ nhớ của mảng động

    tree.insert(14);
    tree.insert(0); 
    tree.insert(35); 
    cout << "BST sau khi chèn thêm 14, 0, 35: "; 
    tree.display();

    tree.remove(6); 
    tree.remove(13);
    tree.remove(35); 
    cout << "BST sau khi xóa 6, 13, 35: ";
    tree.display();

    return 0; 
}