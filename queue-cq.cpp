#include <iostream>
using namespace std;

class cq {
    int *arr;
    int f, r;
    int size, cap;

public:
    cq(int c) {
        cap = c;
        arr = new int[cap];
        f = -1;
        r = -1;
        size = 0;
    }

    void push(int val) {
        if (size == cap) return; // queue full
        if (f == -1) f = 0;      // first insertion
        r = (r + 1) % cap;
        arr[r] = val;
        size++;
    }

    void pop() {
        if (size == 0) return; // queue empty
        f = (f + 1) % cap;
        size--;
        if (size == 0) { // reset when empty
            f = -1;
            r = -1;
        }
    }

    int front() {
        if (size == 0) return -1;
        return arr[f];
    }

    bool isEmpty() {
        return size == 0;
    }
};


int main() {
    cq q(5);
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl; // 1
    q.pop();
    cout << q.front() << endl; // 2

    return 0;
}
