#include <iostream>
using namespace std;

class QueueArray {
private:
    int* arr;
    int front, rear, size;

public:
    QueueArray(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty\n";
            return;
        }
        front++;
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    ~QueueArray() {
        delete[] arr;
    }
};

int main() {
    QueueArray q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.peek() << endl;
    
    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;
    
    return 0;
}
