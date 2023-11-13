// #include<iostream>
// using namespace std;

// int main() {

//     int n=5;
//     // cin >> n;
//      int arr[5]={30,10,40,20,15};

//     // for (int i = 0; i < n; i++) {
//     //     cin >> arr[i];
//     // }
//     int count = 0;

//     for (int i = 1; i < n; i++) {
//         int current = arr[i];
//         int j = i - 1;
//         while (arr[j] < current && j >= 0) { // Change from j > 0 to j >= 0
//             arr[j + 1] = arr[j];
//             j--;
//             count++;
//         }
//         arr[j + 1] = current;
//     }

//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << "Loop "<<count;

//     return 0;
// }


// Insertion sort in C++
// #include <iostream>
// using namespace std;
// void print_array(int arr[], int size)
// {
// for (int i = 0; i < size; i++)
// {
// cout << arr[i] << " ";
// }
// cout << endl;
// }
// void insertion_sort(int arr[], int size)
// {
//     int count =0;
// for (int step = 1; step < size; step++)
// {
// int key = arr[step];
// int j = step - 1;
// while (key > arr[j] && j >= 0)
// {
// // For ascending order, change key> arr[j] to key< arr[j].
// arr[j + 1] = arr[j];
// --j;
// count++;
// }
// arr[j + 1] = key;
// }
// cout<<"Count"<<count;
// }
// int main()
// {
// int arr[] = {30,10,40,20,15};
// int size = sizeof(arr) / sizeof(arr[0]);
// insertion_sort(arr, size);
// cout << "Sorted array in descending order:\n";
// print_array(arr, size);
// }



// insertion sort using linklist
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void push(int newData) {
        Node* newNode = new Node(newData);
        newNode->next = head;
        head = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertionSort() {
        int count = 0;
        if (head == nullptr || head->next == nullptr) {
            return; // No sorting needed for 0 or 1 element
        }

        Node* sorted = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next;

            if (sorted == nullptr || sorted->data <= current->data) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* search = sorted;
                while (search->next != nullptr && search->next->data > current->data) {
                    search = search->next;
                }
                current->next = search->next;
                search->next = current;
            }
            current = nextNode;
        }
        head = sorted;
    }
};

int main() {
    LinkedList list;
    list.push(30);
    list.push(10);
    list.push(40);
    list.push(20);
    list.push(15);

    cout << "Original List:" << endl;
    list.printList();

    list.insertionSort();

    cout << "Sorted List (ascending order):" << endl;
    list.printList();

    return 0;
}
