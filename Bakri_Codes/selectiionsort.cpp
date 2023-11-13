// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int arr[n];

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     for (int i = 0; i < n; i++) {
//         for(int j= i+1;j<n;j++){
//             if(arr[j]<arr[i]){
//                 int temp= arr[j];
//                 arr[j]=arr[i];
//                 arr[i]=temp;
//             }
//         }
        
//     }

//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

//using linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int newData) {
        Node* newNode = new Node(newData);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void sort() {
        if (head == nullptr || head->next == nullptr) {
            return; // Already sorted or empty list
        }

        Node* i = head;
        while (i != nullptr) {
            Node* j = i->next;
            while (j != nullptr) {
                if (j->data < i->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
                j = j->next;
            }
            i = i->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList list;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.append(num);
    }

    list.sort();

    list.display();

    return 0;
}

