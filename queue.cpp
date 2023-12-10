#include <bits/stdc++.h>
using namespace std;

// QUEUE IMPLEMENTATION

class node {
   public:
    int data;
    node* next;
    node* prev;
};

class Queue {
   public:
    node* head;
    node* tail;
    int sizee;
    Queue() {
        head = NULL;
        tail = NULL;
        sizee = 0;
    }

    void enqueue(int data) {
        node* temp = new node();
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        sizee++;
    }

    void dequeue() {
        if (head == NULL) return;
        sizee--;

        node* toDel = tail;
        node* temp = toDel->prev;
        temp->next = NULL;
        toDel->prev = NULL;
        tail = temp;
        delete toDel;
    }

    void print_queue() {
        node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    int peek() {
        return tail->data;
    }
    bool isEmpty() {
        return (head==NULL);
    }
};

int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(23);
    q.enqueue(12);
    q.enqueue(54);
    q.enqueue(18);
    q.enqueue(49);
    q.dequeue();
    cout << q.peek() << endl;
    cout << q.isEmpty() << endl;
    q.print_queue();
}