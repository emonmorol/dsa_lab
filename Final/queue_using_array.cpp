#include <bits/stdc++.h>
using namespace std;

// QUEUE IMPLEMENTATION

int Queue[10];
int tail = -1;

void enqueue(int data) {
    if (tail >= 10) {
        cout << "Queue Overflow\n";
        return;
    }
    Queue[++tail] = data;
}
void dequeue() {
    if (tail < 0) {
        cout << "Queue Underflow\n";
        return;
    }
    for (int i = 1; i <= tail; i++) {
        Queue[i - 1] = Queue[i];
    }
    Queue[tail] = 0;
    tail--;
}
void print_queue() {
    for (int i = 0; i <= tail; i++) {
        cout << Queue[i] << " ";
    }
    cout << endl;
}
int peek() {
    return Queue[0];
}
bool isEmpty() {
    return tail < 0;
}

int main() {
    enqueue(4);
    enqueue(23);
    enqueue(12);
    enqueue(54);
    enqueue(18);
    enqueue(49);
    dequeue();
    cout << peek() << endl;
    cout << isEmpty() << endl;
    print_queue();
}