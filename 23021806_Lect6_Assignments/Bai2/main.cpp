#include <iostream>
using namespace std;

class MinHeap {
private:
    int* heap;  // Mảng động lưu heap
    int capacity; // Dung lượng tối đa của heap
    int size;  // Số lượng phần tử hiện tại

    void heapifyUp(int index) { // Điều chỉnh lên để duy trì Min-Heap
        while (index > 0) { // Lặp lại cho đến khi đạt gốc
            int parent = (index - 1) / 2; // Xác định cha của node hiện tại
            if (heap[parent] > heap[index]) { // Nếu cha lớn hơn node hiện tại
                swap(heap[parent], heap[index]); // Hoán đổi vị trí
                index = parent; // Cập nhật index để tiếp tục kiểm tra
            } else break; // Thoát vòng lặp nếu heap hợp lệ
        }
    }

    void heapifyDown(int index) { // Điều chỉnh xuống để duy trì Min-Heap
        int leftChild = 2 * index + 1; // Xác định con trái
        int rightChild = 2 * index + 2; // Xác định con phải
        int smallest = index; // Giả sử node hiện tại là nhỏ nhất

        if (leftChild < size && heap[leftChild] < heap[smallest]) // Nếu con trái nhỏ hơn
            smallest = leftChild;
        if (rightChild < size && heap[rightChild] < heap[smallest]) // Nếu con phải nhỏ hơn
            smallest = rightChild;

        if (smallest != index) { // Nếu node nhỏ nhất thay đổi
            swap(heap[index], heap[smallest]); // Hoán đổi vị trí
            heapifyDown(smallest); // Gọi đệ quy cho node vừa đổi
        }
    }

public:
    MinHeap(int cap) {
        capacity = cap; // Gán dung lượng tối đa
        heap = new int[capacity]; // Cấp phát mảng động
        size = 0; 
    }

    void insert(int val) { // Chèn giá trị vào heap
        if (size == capacity) { // Nếu heap đầy
            cout << "Heap đầy! Không thể chèn thêm.\n"; 
            return;
        }
        heap[size] = val; // Đưa giá trị vào cuối mảng
        heapifyUp(size); // Điều chỉnh lên để đảm bảo Min-Heap
        size++; // Tăng kích thước heap
    }

    void deleteValue(int val) { // Xóa giá trị trong heap
        int index = -1; // Khởi tạo index = -1
        for (int i = 0; i < size; i++) { // Tìm giá trị trong heap
            if (heap[i] == val) { // Nếu tìm thấy
                index = i;
                break; 
            }
        }
        if (index == -1) { // Nếu không tìm thấy
            cout << "Giá trị không tồn tại trong heap!\n";
            return;
        }
        heap[index] = heap[size - 1]; // Đưa phần tử cuối lên vị trí xóa
        size--; // Giảm kích thước heap
        heapifyDown(index); // Điều chỉnh xuống để đảm bảo Min-Heap
    }

    void printHeap() { // In mảng heap
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl; 
    }

    ~MinHeap() { delete[] heap; } // Destructor giải phóng bộ nhớ
};

int main(){
     MinHeap heap(15); 

    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20}; // Mảng giá trị ban đầu
    int n = sizeof(values) / sizeof(values[0]); // Xác định số lượng phần tử
    
    cout << "Heap sau khi chèn các giá trị ban đầu: \n"; 
    for (int i = 0; i < n; i++) {
        heap.insert(values[i]);
    }
    heap.printHeap(); 

    // Thêm các giá trị mới
    heap.insert(14);
    heap.insert(0);
    heap.insert(35); 
    cout << "Heap sau khi chèn 14, 0, 35:\n";
    heap.printHeap();

    // Xóa các giá trị
    heap.deleteValue(6); 
    heap.deleteValue(13);
    heap.deleteValue(35);
    cout << "Heap sau khi xóa 6, 13, 35:\n"; 
    heap.printHeap(); 

    return 0;
    
}