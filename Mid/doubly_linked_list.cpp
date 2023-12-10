#include <bits/stdc++.h>
using namespace std;

// DOUBLY LINKED LIST

class node {
   public:
    int data;
    node* next;
    node* prev;
};

class doubly_linked_list {
   public:
    node* head;
    int sizee;
    doubly_linked_list() {
        head = NULL;
        sizee = 0;
    }

    void insertHead(int data) {
        node* temp = (node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        sizee++;
    }
    void insertEnd(int data) {
        node* newNode = (node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        sizee++;
        if (head == NULL) {
            head = newNode;
        } else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            newNode->prev = temp;
            temp->next = newNode;
        }
    }
    void insertInPosition(int data, int position) {
        node* newNode = (node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
        sizee++;
        if (position == 0)
            insertHead(data);
        else {
            node* temp = head;
            for (int i = 0; i < position - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL) return;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    void deleteHead() {
        if (head == NULL) return;
        sizee--;
        node* temp = head;
        head = temp->next;
        head->prev = NULL;
        delete temp;
    }

    void deleteLast() {
        if (head == NULL) return;
        sizee--;
        node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        node* toDel = temp->next;
        temp->next = NULL;
        toDel->prev = NULL;
        delete toDel;
    }
    void deleteAnyPosition(int position) {
        node* temp = head;
        sizee--;
        for (int i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) return;
        node* toDel = temp->next;
        temp->next = toDel->next;
        toDel->next->prev = temp;
        delete toDel;
    }

    int middle() {
        node* c = head;
        node* m = head;
        while ((m->next != NULL) && (c->next) != NULL) {
            c = c->next->next;
            m = m->next;
        }
        return m->data;
    }

    void print_list() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void print_reverse() {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    return 0;
}