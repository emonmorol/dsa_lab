#include <bits/stdc++.h>
using namespace std;

// SINGLY LINKED LIST

class Node {
   public:
    int data;
    Node* next;
};

class singly_linked_list {
   public:
    Node* head;
    int sizee;
    singly_linked_list() {
        head = NULL;
        sizee = 0;
    }

    void insertHead(int data) {
        Node* temp = new Node();
        temp->data = data;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        sizee++;
    }
    void insertEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        sizee++;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
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
            for (int i = 0; i < position - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL) return;
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
        if (head == NULL) return;
        sizee--;
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        Node* toDel = temp->next;
        temp->next = NULL;
        delete toDel;
    }
    void deleteAnyPosition(int position) {
        Node* temp = head;
        sizee--;
        for (int i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) return;
        Node* toDel = temp->next;
        temp->next = toDel->next;
        delete toDel;
    }

    Node* middle() {
        Node* c = head;
        Node* m = head;
        while ((m->next != NULL) && (c->next->next) != NULL) {
            c = c->next->next;
            m = m->next;
        }
        return m;
    }

    void print_list() {
        Node* temp = new Node();
        temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int getSize() {
        return sizee;
    }
    Node* getHead() {
        return head;
    }
    void delete_last_occurence(int key) {
        Node* temp = head;
        Node* temp2 = NULL;
        while (temp != NULL) {
            if (temp->next != NULL && temp->next->data == key) {
                temp2 = temp;
            }
            temp = temp->next;
        }
        // cout << temp2->data << endl;
        // cout << temp2->next->data << endl;
        if (temp2 == NULL) {
            cout << "NO OCCURENCE!\n";
            return;
        }
        Node* toDel = temp2->next;
        temp2->next = toDel->next;
        delete toDel;
    }
};

int main() {
    singly_linked_list l;
    l.insertHead(1);
    l.insertHead(3);
    l.insertHead(4);
    l.insertHead(1);
    l.insertHead(6);
    l.insertHead(9);
    l.insertHead(1);
    l.print_list();
    l.delete_last_occurence(1);
    l.print_list();

    return 0;
}