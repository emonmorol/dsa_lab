#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
};

class circular_linked_list {
   public:
    Node* head;
    int sizee;

    circular_linked_list() {
        head = NULL;
        sizee = 0;
    }

    void insertHead(int data) {
        Node* temp = new Node();
        temp->data = data;
        temp->next = head;

        if (head != NULL) {
            Node* last = head;
            while (last->next != head)
                last = last->next;
            last->next = temp;
        } else {
            temp->next = temp;
        }

        head = temp;
        sizee++;
    }

    void insertEnd(int data) {
        Node* temp = new Node();
        temp->data = data;
        temp->next = head;
        if (head != NULL) {
            Node* last = head;
            while (last->next != head)
                last = last->next;
            last->next = temp;
        } else {
            temp->next = temp;
            head = temp;
        }

        sizee++;
    }
    void insertInPosition(int data, int position) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        sizee++;
        if (position == 0)
            insertHead(data);
        else {
            Node* temp = head;
            for (int i = 0; i < position - 1 && temp != head; i++) {
                temp = temp->next;
            }
            if (temp == head) return;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void deleteHead() {
        if (head == NULL) return;
        sizee--;
        Node* temp = head;
        head = temp->next;
        delete temp;
    }

    void deleteLast() {
        if (head == NULL || head->next == head) {
            delete head;
            head = NULL;
            sizee = 0;
        } else {
            Node* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node* toDel = temp->next;
            temp->next = head;
            delete toDel;
            sizee--;
        }
    }
    void deleteAnyPosition(int position) {
        Node* temp = head;
        sizee--;
        for (int i = 0; i < position - 1 && temp != head; i++) {
            temp = temp->next;
        }
        if (temp == head) return;
        Node* toDel = temp->next;
        temp->next = toDel->next;
        delete toDel;
    }

    Node* middle() {
        Node* c = head;
        Node* m = head;
        while ((m->next != head) && (c->next->next) != head) {
            c = c->next->next;
            m = m->next;
        }
        return m;
    }

    void print_list() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    circular_linked_list l;
    l.insertHead(3);
    l.insertHead(8);
    l.insertHead(2);
    l.insertHead(7);
    l.insertHead(0);
    l.insertHead(3);
    l.insertHead(23);
    l.print_list();

    l.deleteLast();
    l.print_list();

    return 0;
}
