#include <iostream>
using namespace std;

class StackArray {
private:
    int *arr;
    int top;
    int capacity;

public:
    StackArray(int size) {
        capacity = size;
        arr = new int[size];
        top = -1;
    }

    ~StackArray() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    StackArray stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element: " << stack.peek() << endl; 

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl; 

    return 0;
}
