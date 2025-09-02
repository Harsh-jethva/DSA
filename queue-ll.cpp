#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = tail = NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) return -1;
        Node* temp = head;
        int val = head->data;
        head = head->next;
        if (head == NULL) tail = NULL; // queue empty
        delete temp;
        return val;
    }

    int peek() {
        if (isEmpty()) return -1;
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    int n;
    cin >> n;
    Queue q;

    while (n--) {
        int type;
        cin >> type;

        switch (type) {
            case 1: { // enqueue
                int x;
                cin >> x;
                q.enqueue(x);
                break;
            }
            case 2: // dequeue
                cout << q.dequeue() << endl;
                break;
            case 3: // peek
                cout << q.peek() << endl;
                break;
            case 4: // isEmpty
                cout << (q.isEmpty() ? 1 : 0) << endl;
                break;
        }
    }
    return 0;
}
