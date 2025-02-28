#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int countTriplets() {
        int count = 0;
        Node* temp = head->next;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->prev->data + temp->data + temp->next->data == 0) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    DoublyLinkedList dll;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        dll.insertAtEnd(num);
    }

    cout << dll.countTriplets() << endl;

    return 0;
}