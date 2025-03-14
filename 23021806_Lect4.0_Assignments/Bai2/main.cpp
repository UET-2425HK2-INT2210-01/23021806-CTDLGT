#include <iostream>
using namespace std;

struct Node {
    int value, priority;
    Node* next;
    Node* prev;
    Node(int v, int p) : value(v), priority(p), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* head = nullptr;

public:
    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);
        if (!head || p > head->priority) { // Chèn đầu nếu danh sách rỗng hoặc có độ ưu tiên cao nhất
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->priority >= p) temp = temp->next;

        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void printQueue() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->value << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~PriorityQueue() {
        while (head) dequeue();
    }
};

int main() {
    int n;
    cin >> n;
    PriorityQueue pq;

    while (n--) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }

    pq.printQueue();
}