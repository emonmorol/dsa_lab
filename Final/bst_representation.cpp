#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

   public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Example: Inorder Traversal
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }

    void postorderTraversal(Node* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->data << " ";
        }
    }
    void postorderTraversal() {
        postorderTraversal(root);
        cout << endl;
    }


    void preorderTraversal(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }
    void preorderTraversal() {
        preorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst.insert(x);
    }
    
    // Printing inorder traversal of the BST
    cout << "Inorder Traversal of the BST: ";
    bst.inorderTraversal();
    cout << "Post Order Traversal of the BST: ";
    bst.postorderTraversal();
    cout << "Pre Order Traversal of the BST: ";
    bst.preorderTraversal();

    return 0;
}
