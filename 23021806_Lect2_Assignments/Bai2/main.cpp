#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < p - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }
            if (temp != nullptr) {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void remove(int p) {
        if (head == nullptr) return;
        if (p == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;
            for (int i = 0; i < p - 1 && temp->next != nullptr; ++i) {
                temp = temp->next;
            }
            if (temp->next != nullptr) {
                Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                delete nodeToDelete;
            }
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList linkedList;
    int n;
    cin >> n;
    while (n--) {
        string operation;
        cin >> operation;
        if (operation == "insert") {
            int p, x;
            cin >> p >> x;
            linkedList.insert(p, x);
        } else if (operation == "delete") {
            int p;
            cin >> p;
            linkedList.remove(p);
        }
    }

    linkedList.printList();
    return 0;
}
    