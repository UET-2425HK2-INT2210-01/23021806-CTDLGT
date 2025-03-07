#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class StackLinkedList {
private:
    Node* topNode;

public:
    StackLinkedList() : topNode(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (!topNode) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int peek() {
        if (!topNode) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

int main() {
    StackLinkedList stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element: " << stack.peek() << endl; 

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl; 

    return 0;
}
