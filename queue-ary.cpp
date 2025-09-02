#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // enqueue(x): add element at rear
    void enqueue(int val) {
        if (size == capacity) return; // queue full (not required by problem)
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }

    // dequeue(): remove and return front element
    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        if (size == 0) { // reset when empty
            front = -1;
            rear = -1;
        }
        return val;
    }

    // peek(): return front element without removing
    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // isEmpty(): return true if queue empty
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    int n;
    cin >> n;
    Queue q(n); // capacity = n (enough for all operations)

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
