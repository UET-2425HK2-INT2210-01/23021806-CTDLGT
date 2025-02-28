#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data): data(data), next(nullptr){}
};

class Stack{
private:
    Node* top;
public:
    Stack() : top(nullptr){}

    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if (top == nullptr) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void printStack(){
        Node* temp = top;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){
    Stack stack;
    int n;
    cin >> n;
    while (n--){
        string operation;
        cin >> operation;
        if (operation == "push"){
            int x;
            cin >> x;
            stack.push(x);
        } else if (operation == "pop"){
            stack.pop();
        }
    }

    stack.printStack();
    return 0;
}
