#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void search(int x) {
        Node* p = head;
        int pos = 1;
        while (p) {
            if (p->data == x) {
                cout << pos << endl;
                return;  
            p = p->next;
            pos++;
        }
        cout << "NO" << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current) {
            next = current->next; 
            current->next = prev;   
            prev = current;         
            current = next;         
        }
        head = prev; 
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int n;
    cin >> n;
    
    LinkedList list;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        
        if (command == "append") {
            int x;
            cin >> x;
            list.append(x);
        } else if (command == "search") {
            int x;
            cin >> x;
            list.search(x);
        } else if (command == "reverse") {
            list.reverse();
        }
    }

    list.printList();
    return 0;
}
