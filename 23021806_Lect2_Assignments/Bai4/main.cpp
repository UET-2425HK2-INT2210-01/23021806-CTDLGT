#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data): data(data), next(nullptr){}
};

class Queue{
private:
    Node* front;
    Node* rear;
public:
    Queue(): front(nullptr), rear(nullptr){}

    void enqueue(int x){
        Node* newNode = new Node(x);
        if (rear == nullptr){
            front = rear = newNode;
        } else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue(){
        if (front == nullptr) return;
        Node* temp = front;
        front = front->next;
        if (front == nullptr){
            rear = nullptr;
        }
        delete temp;
    }

    void printQueue(){
        Node* temp = front;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){
    Queue queue;
    int n;
    cin >> n;
    while (n--) {
        string operation;
        cin >> operation;
        if (operation == "enqueue") {
            int x;
            cin >> x;
            queue.enqueue(x);
        } else if (operation == "dequeue") {
            queue.dequeue();
        }
    }

    queue.printQueue();
    return 0;
}
