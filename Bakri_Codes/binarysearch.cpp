// #include<iostream>
// using namespace std;
// int main(){
//     int n,index;
//     cin >> n;
//     int arr[n];

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
         
//     }

//     int key;
//     cin>>key;
//     bool found;

//     int s=0;
//     int e=n;
//     while(s<=e){
//         int mid =(s+e)/2;
//         if(arr[mid]==key){
//                 cout<<"found at "<<mid<<endl;
//                 found=true;
//                 break;
//         }
//         if(arr[mid]>key){
//             e=mid-1;

//         }
//         if(arr[mid]<key){
//             s=mid +1 ;
//         }
//         else{
//             found=false;
//         }


//     }
//     if(!found)cout <<"not found";
    

//     cout<<endl;
//     return 0;


// }

//char binary search

// #include <iostream>
// using namespace std;

// // Binary search function for a sorted array of characters
// int binarySearch(char arr[], int size, char target) {
//     int left = 0;
//     int right = size - 1;

//     while (left <= right) {
//         int mid = left + (right - left) / 2;

//         if (arr[mid] == target) {
//             return mid; // Element found at index mid
//         }

//         if (arr[mid] < target) {
//             left = mid + 1; // Search the right half
//         } else {
//             right = mid - 1; // Search the left half
//         }
//     }

//     return -1; // Element not found
// }

// int main() {
//     int size;
//     cout << "Enter the number of characters: ";
//     cin >> size;

//     char charArray[size];
//     cout << "Enter " << size << " sorted characters: ";
//     for (int i = 0; i < size; i++) {
//         cin >> charArray[i];
//     }

//     char target;
//     cout << "Enter the character to search for: ";
//     cin >> target;

//     int result = binarySearch(charArray, size, target);

//     if (result != -1) {
//         cout << "Element found at index: " << result << endl;
//     } else {
//         cout << "Element not found in the array." << endl;
//     }

//     return 0;
// }


//linked list

// #include <iostream>
// using namespace std;

// struct Node {
//     char data;
//     Node* next;

//     Node(char value) : data(value), next(nullptr) {}
// };

// class LinkedList {
// public:
//     Node* head;

//     LinkedList() : head(nullptr) {}

//     void insert(char newData) {
//         Node* newNode = new Node(newData);
//         if (head == nullptr || head->data >= newData) {
//             newNode->next = head;
//             head = newNode;
//         } else {
//             Node* temp = head;
//             while (temp->next != nullptr && temp->next->data < newData) {
//                 temp = temp->next;
//             }
//             newNode->next = temp->next;
//             temp->next = newNode;
//         }
//     }



//     int binarySearch(char target) {
//         Node* current = head;
//         int index = 0;

//         while (current != nullptr) {
//             if (current->data == target) {
//                 return index; // Element found at index
//             }
//             current = current->next;
//             index++;
//         }

//         return -1; // Element not found
//     }
// };

// int main() {
//     int size;
//     cout << "Enter the number of characters: ";
//     cin >> size;

//     LinkedList list;
//     cout << "Enter " << size << " sorted characters: ";
//     for (int i = 0; i < size; i++) {
//         char value;
//         cin >> value;
//         list.insert(value);
//     }

//     char target;
//     cout << "Enter the character to search for: ";
//     cin >> target;

//     int result = list.binarySearch(target);

//     if (result != -1) {
//         cout << "Element found at index: " << result << endl;
//     } else {
//         cout << "Element not found in the list." << endl;
//     }

//     return 0;
// }

// count how many element have

#include <iostream>
#include <algorithm>
using namespace std;

int binarySearchFirst(char arr[], int size, char target) {
    int left = 0;
    int right = size - 1;
    int first = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (tolower(arr[mid]) == tolower(target)) {
            first = mid;
            right = mid - 1; // Continue searching on the left
        } else if (tolower(arr[mid]) < tolower(target)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return first;
}

int binarySearchLast(char arr[], int size, char target) {
    int left = 0;
    int right = size - 1;
    int last = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (tolower(arr[mid]) == tolower(target)) {
            last = mid;
            left = mid + 1; // Continue searching on the right
        } else if (tolower(arr[mid]) < tolower(target)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return last;
}

int countOccurrences(char arr[], int size, char target) {
    int first = binarySearchFirst(arr, size, target);
    int last = binarySearchLast(arr, size, target);

    if (first == -1) {
        return 0; // Character not found
    }

    return last - first + 1;
}

int main() {
    char arr[] = "Unnnnn";
    int size = sizeof(arr) -1; // Excluding the null terminator

    sort(arr, arr + size); // Sort the characters

    char target = 'n';

    int count = countOccurrences(arr, size, target);
    cout << "Search for: '" << target << "', Output: " << count << endl;

    return 0;
}
