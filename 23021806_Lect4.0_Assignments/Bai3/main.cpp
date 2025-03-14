#include <iostream>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node(char val): data(val), next(nullptr){}
};

class Stack{
private:
    Node* top; 

public:
    Stack(): top(nullptr){}

    void push(char c){
        Node* newNode = new Node(c);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    char peek(){
        return top ? top->data : '\0';
    }

    bool isEmpty(){
        return top == nullptr;
    }

    ~Stack(){
        while (!isEmpty()) pop();
    }
};

bool isValid(string s){
    Stack st;

    for (char c : s){
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else{
            if (st.isEmpty()) return false;
            char topChar = st.peek();
            if ((c == ')' && topChar == '(') ||
                (c == ']' && topChar == '[') ||
                (c == '}' && topChar == '{')) {
                st.pop();
            } else{
                return false;
            }
        }
    }

    return st.isEmpty();
}

int main(){
    string s;
    cin >> s;
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}